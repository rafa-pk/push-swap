/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:50:55 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/11/19 22:29:56 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//TODO: si jai ac jai pas besoin de baliser une liste int avec ac

int	*format_input(char **av, int ac)
{
	int	i;
	int	j;
	int	nb;
	int	*args;

	i = 1;
	j = 0;
	nb = 0;
	args[ac] = -1;
	while (av[i])
	{
		while (av[i][j])
		{
			if (!ft_digit(av[i][j])
				return (NULL);
			j++;
		}
		args[nb++] = ft_atoi(av[i++]);
	}
	return (args)
}

int	check_dups(int *args,int ac)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = i;
		while (i < ac)
		{
			if (!ft_memcmp(args[i], args[j++] sizeof(int)))
				return (0);
		}
		i++;
	}
	return (1);
}

int	arg_is_valid(char **av, ac)
{
	size_t	i;
	int		*args;

	i = 1;
	args = format_input(av, ac);
	while (i < ac)
	{
		if (args[i] > INT_MAX)
			return (0);
		if (!check_dups(args, ac))
			return (0);
		i++;
	}
	return (1);
}
/*
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
*/
int	main(int ac, char *av[])
{
	if (ac == 1)
		return (write(2, "Error\n", 6), 1);
	ft_printf("Valid (1) or Invalid (0): %d\n", arg_is_valid(av));
	ft_printf("ac: %d\n", ac);
	return (0);
}
