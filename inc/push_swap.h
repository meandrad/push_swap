/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:56:21 by meandrad          #+#    #+#             */
/*   Updated: 2025/04/17 19:11:26 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

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
}	t_node;

//utils
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		stack_len(t_node *stack);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	put_min_top(t_node **stack_a);
long	ft_atol(const char *s);
bool	stack_sorted(t_node *stack);
t_node	*search_max(t_node *stack);
t_node	*search_min(t_node *stack);
t_node	*search_last_node(t_node *stack);

//instructions
void	push_node(t_node **dest, t_node **src);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_b, t_node **stack_a);
void	reverse_rotate(t_node **head);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	rotate_stack(t_node **head);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	double_rr(t_node **a, t_node **b, t_node *cheap);
void	double_rrr(t_node **a, t_node **b, t_node *cheap);
void	send_a_to_b(t_node **stack_a, t_node **stack_b);
void	sort(t_node **stack_a, t_node **stack_b);
void	sort_three_nodes(t_node **stack);
void	swap_stack(t_node **head);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);

//sources
void	add_node(t_node **stack_a, long n);
void	start_stack_a(t_node **stack_a, char *argv[]);
void	prep_for_push(t_node **stack, t_node *top, char stack_name);
void	set_index(t_node *stack);
void	set_target_a(t_node *stack_a, t_node *stack_b);
void	set_cost(t_node *stack_a, t_node *stack_b);
void	cheapest(t_node *stack);
void	init_stack_a(t_node *stack_a, t_node *stack_b);
void	set_target_b(t_node *stack_a, t_node *stack_b);
void	init_stack_b(t_node *stack_a, t_node *stack_b);
t_node	*search_cheapest(t_node *stack);

//error
int		error_input(char *str);
int		handle_duplicate(t_node *stack, long n);
void	free_stack(t_node **stack);
void	print_error(t_node **stack);

#endif
