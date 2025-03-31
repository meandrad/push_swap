/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:53:14 by meandrad          #+#    #+#             */
/*   Updated: 2025/03/31 19:11:46 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	start_stack_a(&stack_a, argv + 1);
	if (stack_sorted(stack_a) == false)
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a);
		else if (stack_len(stack_a) == 3)
			sort_three_nodes(&stack_a);
		else
			sort(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	return (0);
}
