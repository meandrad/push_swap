/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:36:06 by meandrad          #+#    #+#             */
/*   Updated: 2025/04/02 19:41:44 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	error_input(char *s)
{
	int	i;

	i = 0;
	if (s[i] != '-' || s[i] != '+' || !(s[i] >= '0' && s[i] <= '9'))
		return (1);
	if ((s[i] == '-' || s[i] == '+') && !(s[i + 1] >= '0' && s[i + 1] <= '9'))
		return (1);
	while (s[i] != '\0')
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (1);
		i++;
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
