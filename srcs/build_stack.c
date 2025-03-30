/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:55:41 by meandrad          #+#    #+#             */
/*   Updated: 2025/03/30 18:31:02 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	add_node(t_stack_node **stack_a, int n)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack_a)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->nbr = n;
	new_node->next = NULL;
	new_node->cheapest = 0;
	if (*stack_a == NULL)
	{
		new_node->prev = NULL;
		*stack_a = new_node;
	}
	else
	{
		last_node = search_last_node(*stack_a);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	start_stack_a(t_stack_node **stack_a, char *argv[])
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_input(argv[i]))
			print_error(stack_a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			print_error(stack_a);
		if (handle_duplicate(&stack_a, (int)n))
			print_error(stack_a);
		add_node(stack_a, (int)n);
		i++;
	}
}

t_stack_node	*search_cheapest(t_stack_node *stack)
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

void	prep_for_push(t_stack_node **stack, t_stack_node *top, char stack_name)
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
