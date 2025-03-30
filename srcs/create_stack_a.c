/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 11:13:49 by meandrad          #+#    #+#             */
/*   Updated: 2025/03/30 13:13:02 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_index(t_stack_node *stack)
{
	int	index;
	int	median;

	index = 0;
	if (!stack)
		return ;
	median = ft_stack_len(stack) / 2;
	while (stack != NULL)
	{
		stack->index = index;
		if (index <= median)
			stack->above_mediam = true;
		else
			stack->above_mediam = false;
		stack = stack->next;
		index++;
	}
}

static void	search_target_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*node_b;
	t_stack_node	*target_node;
	long			closest_smaller;

	while (stack_a != NULL)
	{
		closest_smaller = LONG_MIN;
		node_b = stack_b;
		while (stack_b != NULL)
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
void	set_cost(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	length_a;
	int	length_b;

	length_a = ft_stack_len(stack_a);
	length_b = ft_stack_len(stack_b);
	while (stack_a != NULL)
	{
		stack_a->push_cost = stack_a->index;
		if (stack_a->above_mediam == false)
			stack_a->push_cost = length_a - (stack_a->index);
		if (stack_a->target_node->above_mediam == true)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += length_b - (stack_a->target_node->index);
		stack_a = stack_a->next;
	}
}

void	cheapest(t_stack_node *stack)
{
	long			cheapest;
	t_stack_node	*cheapest_node;
	
	if (!stack)
		return ;
	cheapest = LONG_MAX;
	while (stack != NULL)
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
void	create_stack_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	search_target_b(stack_a, stack_b);
	set_cost(stack_a, stack_b);
	cheapest(stack_a);
}