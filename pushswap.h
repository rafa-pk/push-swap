/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:38:36 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/11/18 21:45:15 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct	s_node
{
	struct s_node	*prev;
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct	s_stack
{
	int	length;
	t_node	*head;
	t_node	*tail
}	t_node;

#endif
