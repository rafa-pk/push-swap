/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:50:55 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/11/20 12:13:06 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*format_input(char **av, int ac)
{
	int	i;
	int	j;
	int	nb;
	int	*args;

	i = 1;
	j = 0;
	nb = 0;
	args = ft_calloc(ac, sizeof(int));
	if (!args)
		return (NULL);
	while (av[i])
	{
		j = 0;
		if (av[i][0] == '\0')
			return (free(args), NULL);
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (free(args), NULL);
			j++;
		}
		ft_printf("nb %d was a digit\n", i);
		args[nb++] = ft_atoi(av[i++]);
	}
	return (args);
}

int	check_dups(int *args, int ix, int ac)
{
	int	i;

	i = ix++;
	if (ac == 2)
		return (1);
	while (i < ac)
	{
		if (args[ix] == args[i])
			return (0);
		i++;
	}
	return (1);
}

int	arg_is_valid(char **av, int ac)
{
	int		i;
	int		*args;

	i = 0;
	args = format_input(av, ac);
	if (!args)
		return (0);
	while (i < ac)
	{
		if (args[i] < INT_MIN || args[i] > INT_MAX)
			return (free(args), 0);
		ft_printf("nb %d within bounds\n", i);
		if (!check_dups(args, i, ac))
			return (free(args), 0);
		ft_printf("no dups\n");
		i++;
	}
	return (1);
}
/*
t_stack	make_stack(char **av, int ac)
{
	t_stack	stack;
	t_node	*node;
	int		*args;
	int		i;

	i = 0;
	stack = (t_stack){0};
	args = format_input(av, ac);
	if (!arg_is_valid(args, ac))
		return (write(2, "Error\n", 6), NULL);
	while (i < ac)
	{
		node = ft_lst_new(args[i]);
		if (!node)
			return (free(args), NULL);
		ft_lstadd_back(&node, stack);
		i++;
	}
	return (free(args), stack);
}
*/
int	main(int ac, char *av[])
{
	if (ac == 1)
		return (write(2, "Error\n", 6), 1);
	ft_printf("Valid (1) or Invalid (0): %d\n", arg_is_valid(av, ac));
	ft_printf("ac: %d\n", ac);
	return (0);
}
