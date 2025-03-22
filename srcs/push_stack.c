/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:48:42 by meandrad          #+#    #+#             */
/*   Updated: 2025/03/22 00:03:46 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_stack(t_stack_node **stack1, t_stack_node **stack2)
{
	t_stack_node *push_node;
	
	if (!*stack1)
		return ;
	push_node = *stack1;
	(*stack1) = (*stack1)->next;
	if (*stack1)
		(*stack1)->prev = NULL;
	push_node->prev = NULL;
	if (*stack2 == NULL)
	{
		*stack2 = push_node;
		(*stack)->prev = NULL
	}
	else
	{
		push_node->next = (*stack2);
		push_node->next->prev = push_node;
		(*stack2) = push_node;
	}
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push_node(b, a);
	ft_putstr("pa");
	ft_putchar("\n");
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push_node(a, b);
	ft_putstr("pa");
	ft_putchar("\n");
}
