/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:55:41 by meandrad          #+#    #+#             */
/*   Updated: 2025/04/12 12:25:53 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	add_node(t_node **stack_a, long n)
{
	t_node	*new_node;
	t_node	*last_node;

	if (!stack_a)
		return ;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->nbr = n;
	new_node->cheapest = 0;
	if (!(*stack_a))
	{
		*stack_a = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = search_last_node(*stack_a);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	start_stack_a(t_node **stack_a, char *argv[])
{
	long	number;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_input(argv[i]))
			print_error(stack_a);
		number = ft_atol(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			print_error(stack_a);
		if (handle_duplicate(*stack_a, number))
			print_error(stack_a);
		add_node(stack_a, number);
		++i;
	}
}

t_node	*search_cheapest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack != NULL)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_node **stack, t_node *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_mediam)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top->above_mediam)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
