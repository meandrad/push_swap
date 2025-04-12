/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:42:18 by meandrad          #+#    #+#             */
/*   Updated: 2025/04/12 12:26:38 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*search_last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_len(t_node *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		++len;
	}
	return (len);
}

t_node	*search_max(t_node *stack)
{
	long			max;
	t_node	*biggest_node;

	biggest_node = NULL;
	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack != NULL)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

t_node	*search_min(t_node *stack)
{
	long			min;
	t_node	*smallest_node;

	smallest_node = stack;
	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

void	put_min_top(t_node **stack_a)
{
	while ((*stack_a)->nbr != search_min(*stack_a)->nbr)
	{
		if (search_min(*stack_a)->above_mediam)
			ra(stack_a);
		else
			rra(stack_a);
	}
}
