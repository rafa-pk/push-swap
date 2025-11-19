/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:50:55 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/11/19 14:02:35 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	arg_is_valid(char **av)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		if (ft_atoi(av[i]) > INT_MAX)
			return (0);
		if (!check_dups(av, ac))
			return (0);
		i++;
	}
	return (1);
}

t_stack	make_stack(char **av, int ac)
{
	t_stack	stack;
	t_node	*node;
	int		nb;
	int		i;

	i = 1;
	stack = (t_stack){0};
	while (i < argc)
	{
		nb = ft_atoi(av[i]);	//TODO: add INT_MAX / INT_MIN check to atoi
		node = ft_lst_new(nb);
		if (!node)
			return (NULL);
		ft_lstadd_back(&node, stack);
		i++;
	}
	//stack.length = i; ?
	return (stack);
}
