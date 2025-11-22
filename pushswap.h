/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:38:36 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/11/22 14:30:32 by rvaz-da-         ###   ########.fr       */
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
	int		length;
	t_node	*head;
	t_node	*tail;
}	t_stack;

//UTILS
void	free_table(char **table);
int		tab_len(char **tab);

//PARSING
t_arr	argtype(char **av, int ac);
t_arr	format_input(char **av, int ac);
int		ft_isvalid(char c, int ix);
int		check_dups(t_arr args, int i);
int		arg_is_valid(t_arr args);
t_stack	*make_stack(char **av, int ac);

#endif
