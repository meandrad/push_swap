/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:42:18 by meandrad          #+#    #+#             */
/*   Updated: 2025/03/30 15:28:06 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack_node	*search_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	stack_len(t_stack_node *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack != NULL)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_stack_node	*search_max(t_stack_node *stack)
{
	long			max;
	t_stack_node	*biggest_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	if (stack->nbr > max)
	{
		max = stack->nbr;
		biggest_node = stack;
	}
	stack = stack->next;
	return (biggest_node);
}

t_stack_node	*search_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*smallest_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	if (stack->nbr < LONG_MAX)
	{
		min = stack->nbr;
		smallest_node = stack;
	}
	stack = stack->next;
	return (smallest_node);
}

void	put_min_top(t_stack_node **stack_a)
{
	while ((*stack_a)->nbr != search_min(*stack_a)->nbr)
	{
		if (search_min(*stack_a)->above_mediam)
			ra(stack_a);
		else
			rra(stack_a);
	}
}
