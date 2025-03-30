/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 13:19:06 by meandrad          #+#    #+#             */
/*   Updated: 2025/03/30 15:14:37 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	double_rotation(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *cheapest)
{
	while (*stack_b != cheapest->target_node && *stack_a != cheapest)
		rr(stack_a, stack_b);
	set_index(*stack_a);
	set_index(*stack_b);
}

static void	double_reverse_rotate(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *cheapest)
{
	while (*stack_b != cheapest->target_node && *stack_a != cheapest)
		rrr(*stack_a, *stack_b);
	set_index(*stack_a);
	set_index(*stack_b);
}

static void	send_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest;

	cheapest = search_cheapest(*stack_a);
	if (cheapest->above_mediam && cheapest->target_node->above_mediam)
		double_rotation(*stack_a, *stack_b, cheapest);
	else if (!(cheapest->above_mediam) && !(cheapest->target_node->above_mediam))
		double_reverse_rotate(*stack_a, *stack_b, cheapest);
	prep_for_push(stack_a, cheapest, 'a');
	prep_for_push(stack_b, cheapest->target_node, 'b');
	pb(stack_b, stack_a);
}
static void	send_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target_node, 'a');
	pa(stack_a, stack_b);
}

static void	put_min_top(t_stack_node **stack_a)
{
	while ((*stack_a)->nbr != search_min(*stack_a)->nbr)
	{
		if (search_min(*stack_a)->above_mediam)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	lenght_a;

	lenght_a = stack_len(*stack_a);
	if (lenght_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a);
	if (lenght_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a);
	while (lenght_a-- > 3 && !stack_sorted(*stack_a))
	{
		create_stack_a(*stack_a, *stack_b);
		send_a_to_b(stack_a, stack_b);
	}
	sort_three_nodes(stack_a);
	while (*stack_b != NULL)
	{
		creat_stack_b(*stack_a, *stack_b);
		send_b_to_a(stack_a, stack_b);
	}
	set_index(*stack_a);
	put_min_top(stack_a);
}