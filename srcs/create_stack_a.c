/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 11:13:49 by meandrad          #+#    #+#             */
/*   Updated: 2025/04/12 12:26:00 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_index(t_node *stack)
{
	int	index;
	int	median;

	index = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = index;
		if (index <= median)
			stack->above_mediam = true;
		else
			stack->above_mediam = false;
		stack = stack->next;
		++index;
	}
}

void	set_target_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*node_b;
	t_node	*target_node;
	long			closest_smaller;

	while (stack_a)
	{
		closest_smaller = LONG_MIN;
		node_b = stack_b;
		while (node_b)
		{
			if (node_b->nbr < stack_a->nbr && node_b->nbr > closest_smaller)
			{
				closest_smaller = node_b->nbr;
				target_node = node_b;
			}
			node_b = node_b->next;
		}
		if (closest_smaller == LONG_MIN)
			stack_a->target_node = search_max(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

void	set_cost(t_node *stack_a, t_node *stack_b)
{
	int	length_a;
	int	length_b;

	length_a = stack_len(stack_a);
	length_b = stack_len(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_mediam))
			stack_a->push_cost = length_a - (stack_a->index);
		if (stack_a->target_node->above_mediam)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += length_b - (stack_a->target_node->index);
		stack_a = stack_a->next;
	}
}

void	cheapest(t_node *stack)
{
	long			cheapest;
	t_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest)
		{
			cheapest = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_stack_a(t_node *stack_a, t_node *stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	set_target_a(stack_a, stack_b);
	set_cost(stack_a, stack_b);
	cheapest(stack_a);
}
