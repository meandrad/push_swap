/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 13:19:06 by meandrad          #+#    #+#             */
/*   Updated: 2025/04/12 12:25:31 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	double_rr(t_node **a, t_node **b, t_node *cheap)
{
	while (*b != cheap->target_node && *a != cheap)
		rr(a, b);
	set_index(*a);
	set_index(*b);
}

void	double_rrr(t_node **a, t_node **b, t_node *cheap)
{
	while (*b != cheap->target_node && *a != cheap)
		rrr(a, b);
	set_index(*a);
	set_index(*b);
}

void	send_a_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;

	cheapest = search_cheapest(*stack_a);
	if (cheapest->above_mediam && cheapest->target_node->above_mediam)
		double_rr(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_mediam)
		&& !(cheapest->target_node->above_mediam))
		double_rrr(stack_a, stack_b, cheapest);
	prep_for_push(stack_a, cheapest, 'a');
	prep_for_push(stack_b, cheapest->target_node, 'b');
	pb(stack_b, stack_a);
}

void	sort(t_node **stack_a, t_node **stack_b)
{
	int	lenght_a;

	lenght_a = stack_len(*stack_a);
	if (lenght_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a);
	if (lenght_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a);
	while (lenght_a-- > 3 && !stack_sorted(*stack_a))
	{
		init_stack_a(*stack_a, *stack_b);
		send_a_to_b(stack_a, stack_b);
	}
	sort_three_nodes(stack_a);
	while (*stack_b)
	{
		init_stack_b(*stack_a, *stack_b);
		prep_for_push(stack_a, (*stack_b)->target_node, 'a');
		pa(stack_a, stack_b);
	}
	set_index(*stack_a);
	put_min_top(stack_a);
}
