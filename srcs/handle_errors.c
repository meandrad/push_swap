/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:36:06 by meandrad          #+#    #+#             */
/*   Updated: 2025/03/08 10:56:48 by meandrad         ###   ########.fr       */
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

int	handle_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **a)
{
	//learn more about lists before build this function
}

void	print_error(t_stack_node **a)
{
	free_stacl(a);
	ft_putstr("Error\n"); //fix: include ft_printf on libft
	exit(1); //read exit manual again
}
