/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:38:36 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/11/23 21:02:23 by rvaz-da-         ###   ########.fr       */
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
void	free_table(char **table);
int		tab_len(char **tab);

//PARSING
t_arr	argtype(char **av, int ac);
t_arr	format_input(char **av, int ac);
int		ft_isvalid(char c, int ix);
int		check_dups(t_arr args, int i);
int		arg_is_valid(t_arr args);
t_stack	make_stack(char **av, int ac);

#endif
