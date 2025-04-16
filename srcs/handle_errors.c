/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:36:06 by meandrad          #+#    #+#             */
/*   Updated: 2025/04/15 22:57:47 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	error_input(char *str)
{
	if (!str || !*str)
		return (1);
	if (*str == '+' || *str == '-')
	{
		++str;
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		++str;
	}
	return (0);
}

int	handle_duplicate(t_node *stack, long n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->nbr == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_stack(t_node **stack)
{
	t_node	*temp;
	t_node	*current;

	if (!*stack)
		return ;
	current = *stack;
	while (current != NULL)
	{
		temp = current->next;
		current->nbr = 0;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	print_error(t_node **stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}
