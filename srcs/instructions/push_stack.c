/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:48:42 by meandrad          #+#    #+#             */
/*   Updated: 2025/04/03 19:09:06 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	push_node(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dest)
	{
		*dest = push_node;
		(*dest)->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push_node(stack_a, stack_b);
	ft_putstr("pa");
	ft_putchar('\n');
}

void	pb(t_stack_node **stack_b, t_stack_node **stack_a)
{
	push_node(stack_b, stack_a);
	ft_putstr("pb");
	ft_putchar('\n');
}
