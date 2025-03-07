/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:55:41 by meandrad          #+#    #+#             */
/*   Updated: 2025/03/06 21:36:51 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_stack_a(t_stack_node *a, char *argv[])
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_input(argv[i]))
			print_error(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			print_error(a);
		if (handle_duplicate(*a, (int)n))
			print_error(a);
		add_node(); //create add_node
		i++;
	}
}
