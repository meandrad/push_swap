/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:42:18 by meandrad          #+#    #+#             */
/*   Updated: 2025/03/18 20:26:51 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack_node *search_node(t_stack_node *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

int	ft_stack_len(t_stack_node *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack != NULL)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}
