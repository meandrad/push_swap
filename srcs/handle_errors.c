/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:36:06 by meandrad          #+#    #+#             */
/*   Updated: 2025/04/08 21:37:07 by meandrad         ###   ########.fr       */
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

int	handle_duplicate(t_stack_node *stack, long n)
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

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*current;

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

void	print_error(t_stack_node **stack)
{
	free_stack(stack);
	ft_putstr("Error\n");
	exit(1);
}

void	free_args(char *argv[])
{
	int	i;

	i = 0;
	if (*argv)
		return ;
	if (argv != NULL)
	{
		while (argv[i])
		{
			free(argv[i]);
			++i;
		}
		free(argv);
	}
}
