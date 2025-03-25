/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tree_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:18:46 by meandrad          #+#    #+#             */
/*   Updated: 2025/03/25 19:35:41 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_tree_nodes(t_stack_node **stack)
{
	t_stack_node	*biggest_node;

	biggest_node = search_max(*stack);
	if (biggest_node == *stack)
		ra(*stack);
	else if ((*stack)->next == biggest_node)
		rra(*stack);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(*stack);
}
