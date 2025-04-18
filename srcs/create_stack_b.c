/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 11:46:28 by meandrad          #+#    #+#             */
/*   Updated: 2025/04/13 11:54:17 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_target_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*node_a;
	t_node	*target_node;
	long	match;

	while (stack_b)
	{
		match = LONG_MAX;
		node_a = stack_a;
		while (node_a)
		{
			if (node_a->nbr > stack_b->nbr && node_a->nbr < match)
			{
				match = node_a->nbr;
				target_node = node_a;
			}
			node_a = node_a->next;
		}
		if (match == LONG_MAX)
			stack_b->target_node = search_min(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	init_stack_b(t_node *stack_a, t_node *stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	set_target_b(stack_a, stack_b);
}
