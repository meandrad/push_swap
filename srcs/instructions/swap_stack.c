/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:30:42 by meandrad          #+#    #+#             */
/*   Updated: 2025/03/30 12:10:45 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap_stack(t_stack_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next != NULL)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node **stack_a)
{
	swap_stack(stack_a);
	ft_putstr("sa");
	ft_putchar('\n');
}

void	sb(t_stack_node **stack_b)
{
	swap_stack(stack_b);
	ft_putstr("sb");
	ft_putchar('\n');
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
}
