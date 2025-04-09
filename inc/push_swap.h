/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:56:21 by meandrad          #+#    #+#             */
/*   Updated: 2025/04/08 21:56:38 by meandrad         ###   ########.fr       */
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
bool			stack_sorted(t_stack_node *stack);
void			free_args(char *argv[]);
int				error_input(char *s);
int				handle_duplicate(t_stack_node *stack, long n);
int				stack_len(t_stack_node *stack);
void			add_node(t_stack_node **stack_a, long n);
void			cheapest(t_stack_node *stack);
void			init_stack_b(t_stack_node *stack_a, t_stack_node *stack_b);
void			init_stack_a(t_stack_node *stack_a, t_stack_node *stack_b);
void			free_stack(t_stack_node **stack);
void			prep_for_push(t_stack_node **stack, t_stack_node *top, char stack_name);
void			print_error(t_stack_node **stack);
void			put_min_top(t_stack_node **stack_a);
void			set_target_a(t_stack_node *stack_a, t_stack_node *stack_b);
void			set_target_b(t_stack_node *stack_a, t_stack_node *stack_b);
void			set_cost(t_stack_node *stack_a, t_stack_node *stack_b);
void			set_index(t_stack_node *stack);
void			start_stack_a(t_stack_node **stack_a, char *argv[]);
t_stack_node	*search_max(t_stack_node *stack);
t_stack_node	*search_min(t_stack_node *stack);
t_stack_node	*search_cheapest(t_stack_node *stack);
t_stack_node	*search_last_node(t_stack_node *stack);

// instructions/
void			double_rr(t_stack_node **a, t_stack_node **b, t_stack_node *cheap);
void			double_rrr(t_stack_node **a, t_stack_node **b, t_stack_node *cheap);
void			pa(t_stack_node **stack_a, t_stack_node **stack_b);
void			pb(t_stack_node **stack_a, t_stack_node **stack_b);
void			push_node(t_stack_node **stack1, t_stack_node **stack2);
void			ra(t_stack_node **stack_a);
void			rb(t_stack_node **stack_b);
void			reverse_rotate(t_stack_node **head);
void			rotate_stack(t_stack_node **head);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b);
void			rra(t_stack_node **stack_a);
void			rrb(t_stack_node **stack_b);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b);
void			sa(t_stack_node **stack_a);
void			sb(t_stack_node **stack_b);
void			send_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b);
void			send_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b);
void			sort(t_stack_node **stack_a, t_stack_node **stack_b);
void			sort_three_nodes(t_stack_node **stack);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b);
void			swap_stack(t_stack_node **head);

#endif
