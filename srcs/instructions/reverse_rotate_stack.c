/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:04:14 by meandrad          #+#    #+#             */
/*   Updated: 2025/04/03 20:04:29 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	reverse_rotate(t_stack_node **head)
{
	t_stack_node	*tail;

	if (!*head || !(*head)->next)
		return ;
	tail = search_last_node(*head);
	tail->prev->next = NULL;
	tail->next = (*head);
	tail->prev = NULL;
	(*head) = tail;
	tail->next->prev = tail;
}

void	rra(t_stack_node **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr("rra");
	ft_putchar('\n');
}

void	rrb(t_stack_node **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr("rrb");
	ft_putchar('\n');
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr("rrr");
	ft_putchar('\n');
}
