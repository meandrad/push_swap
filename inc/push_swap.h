/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:56:21 by meandrad          #+#    #+#             */
/*   Updated: 2025/03/25 19:42:01 by meandrad         ###   ########.fr       */
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

// ./
int		error_input(char *s);
int		ft_stack_len(t_stack_node *stack);
int		handle_duplicate(t_stack_node *a, int n);
int		main(int argc, char *argv[]);
void	add_node(t_stack_node **a, int n);
void	free_stack(t_stack_node **a);
void	print_error(t_stack_node **a);
void	start_stack_a(t_stack_node *a, char *argv[]);

// instructions/
void	pa(t_stack_node **stack_a, t_stack_node **stack_b);
void	pb(t_stack_node **stack_a, t_stack_node **stack_b);
void	push_stack(t_stack_node **stack1, t_stack_node **stack2);
void	ra(t_stack_node **stack_a);
void	rb(t_stack_node **stack_b);
void	reverse_rotate(t_stack_node **head);
void	rotate_stack(t_stack_node **head);
void	rr(t_stack_node **stack_a, t_stack_node **stack_b);
void	rra(t_stack_node **stack_a);
void	rrb(t_stack_node **stack_b);
void	rrr(t_stack_node **stack_a, t_stack_node **stack_b);
void	sa(t_stack_node **stack_a);
void	sb(t_stack_node **stack_b);
void	sort_tree_nodes(t_stack_node **stack);
void	ss(t_stack_node **stack_a, t_stack_node **stack_b);
void	swap_stack(t_stack_node **head);

#endif
