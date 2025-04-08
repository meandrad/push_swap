/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 11:46:28 by meandrad          #+#    #+#             */
/*   Updated: 2025/04/03 20:49:50 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_target_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*node_a;
	t_stack_node	*target_node;
	long			closest_smaller;

	while (stack_b)
	{
		closest_smaller = LONG_MAX;
		node_a = stack_a;
		while (node_a)
		{
			if (node_a->nbr > stack_b->nbr && node_a->nbr < closest_smaller)
			{
				closest_smaller = node_a->nbr;
				target_node = node_a;
			}
			node_a = node_a->next;
		}
		if (closest_smaller == LONG_MAX)
			stack_b->target_node = search_min(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	init_stack_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	set_target_b(stack_a, stack_b);
}
