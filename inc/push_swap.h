/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:56:21 by meandrad          #+#    #+#             */
/*   Updated: 2025/03/30 11:59:39 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h> 
# include "../libft/libft.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_mediam;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

int		error_input(char *s);
int		ft_stack_len(t_stack_node *stack);
int		handle_duplicate(t_stack_node *stack, int n);
void	add_node(t_stack_node **a, int n);
void	cheapest(t_stack_node *stack);
void	creat_stack_b(t_stack_node *stack_a, t_stack_node *stack_b);
void	create_stack(t_stack_node *stack_a, t_stack_node *stack_b);
void	free_stack(t_stack_node **stack);
void	print_error(t_stack_node **stack);
void	search_target_a(t_stack_node *stack_a, t_stack_node *stack_b);
void	search_target_b(t_stack_node *stack_a, t_stack_node *stack_b);
void	set_cost(t_stack_node *stack_a, t_stack_node *stack_b);
void	set_index(t_stack_node *stack);
void	start_stack_a(t_stack_node *a, char *argv[]);

void	pa(t_stack_node **stack_a, t_stack_node **stack_b);
void	pb(t_stack_node **stack_a, t_stack_node **stack_b);
void	push_stack(t_stack_node **stack1, t_stack_node **stack2);
void	ra(t_stack_node **stack_a);
void	rb(t_stack_node **stack_b);
void	rr(t_stack_node **stack_a, t_stack_node **stack_b);
void	rotate_stack(t_stack_node **head);
void	rra(t_stack_node **stack_a);
void	rrb(t_stack_node **stack_b);
void	rrr(t_stack_node **stack_a, t_stack_node **stack_b);
void	reverse_rotate(t_stack_node **head);
void	sa(t_stack_node **stack_a);
void	sb(t_stack_node **stack_b);
void	ss(t_stack_node **stack_a, t_stack_node **stack_b);
void	swap_stack(t_stack_node **head);
void	sort_three_nodes(t_stack_node **stack);

#endif
