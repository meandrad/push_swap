/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:55:41 by meandrad          #+#    #+#             */
/*   Updated: 2025/03/22 14:39:09 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	add_node(t_stack_node **a, int n)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!a)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->nbr = n;
	new_node->next = NULL;
	new_node->cheapest = 0;
	if (*a == NULL)
	{
		new_node->prev = NULL;
		*a = new_node;
	}
	else
	{
		last_node = search_last_node(*a);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	start_stack_a(t_stack_node *a, char *argv[])
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
		if (handle_duplicate(&a, (int)n))
			print_error(a);
		add_node(a, (int)n);
		i++;
	}
}
