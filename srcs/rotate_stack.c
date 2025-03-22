/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:51:20 by meandrad          #+#    #+#             */
/*   Updated: 2025/03/21 21:27:08 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate_stack(t_stack_node **head)
{
	t_stack_node *tail;
	
	if (!*head || !(*head)->next)
		return ;
	tail = search_last_node(*head);
	tail->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	tail->next->prev = tail;
	tail->next->next = NULL;
}

void	ra(t_stack_node t_stack_node **stack_a)
{
	rotate_stack(stack_a);
	ft_putstr("ra");
	ft_putchar("\n");
}
void	rb(t_stack_node t_stack_node **stack_b)
{
	rotate_stack(stack_a);
	ft_putstr("ra");
	ft_putchar("\n");
}

void	rr(t_stack_node t_stack_node **stack_a, t_stack_node t_stack_node **stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
}