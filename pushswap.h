/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:38:36 by rvaz-da-          #+#    #+#             */
/*   Updated: 2026/01/19 12:09:07 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_arr
{
	int		*arr;
	int		length;
}	t_arr;

typedef struct s_node
{
	struct s_node	*prev;
	int				value;
	int				a_cost;
	int				b_cost;
	int				total_cost;
	struct s_node	*target;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		length;
}	t_stack;

//LIST_HANDLING
t_node	*ft_lstnew(int content);
void	ft_lstadd_back(t_stack *stck, t_node *node);
void	ft_lstadd_front(t_stack *stk, t_node *node);
void	free_stack(t_stack *stack);

//UTILS
void	print_table(t_stack *stack);
void	free_table(char **table);
int		tab_len(char **tab);
int		ft_isvalid(char c, int ix);
int		is_sorted(t_stack *stack);
int		abs(int value);

//MOVEMENTS
void	ft_swap(t_stack *stack, char flag, int stack_nb);
void	ft_push(t_stack *src, t_stack *dest, char flag);
void	ft_ss(t_stack *stack_a, t_stack *stack_b);
void	ft_rotate(t_stack *stack, char flag, int stack_nb);
void	ft_rr(t_stack *stack_a, t_stack *stack_b);
void	ft_reverse_rotate(t_stack *stack, char flag, int stack_nb);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b);

//PARSING
t_arr	argtype(char **av, int ac);
t_arr	format_input(char **av, int ac);
int		check_dups(t_arr args, int i);
int		arg_is_valid(t_arr args);
t_stack	make_stack(char **av, int ac);

//SORTING
void	print_stack(t_stack *stack);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_3(t_stack *stack);
void	final_rotate(t_stack *stack_a);
int		strictly_ascending(t_stack *stack_a);
void	early_sorting(t_stack *stack_a);
void	assign_target_nodes(t_stack *stack_b, t_stack *stack_a);
void	find_target_node(t_node *node_b, t_stack *stack_a);
void	calculate_costs(t_stack *stack_a, t_stack *stack_b);
void	node_cost_a(t_node *b_node, t_stack *stack_a);
t_node	*find_cheapest_node(t_stack *stack_a, t_stack *stack_b);
void	rotate_stacks_to_place(t_stack *stack_a, t_stack *stack_b, t_node *cheapest);
void	rotate_both_stacks(t_stack *stack_a, t_stack *stack_b, t_node *cheapest);
void	rotate_cheapest_node(t_stack *stack_b, t_node *cheapest);
void	rotate_target_node(t_stack *stack_a, t_stack *stack_b, t_node *cheapest);

#endif
