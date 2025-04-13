/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:53:14 by meandrad          #+#    #+#             */
/*   Updated: 2025/04/13 11:54:39 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

bool	stack_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	args = argv + 1;
	start_stack_a(&stack_a, args);
	if (!stack_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a);
		else if (stack_len(stack_a) == 3)
			sort_three_nodes(&stack_a);
		else
			sort(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	if (argc == 2 && args != argv + 1)
		free_args(argv);
	return (0);
}
