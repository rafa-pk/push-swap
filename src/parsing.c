/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:50:55 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/11/21 15:21:20 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

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
		args[nb++] = ft_atoi(av[i++]);
	}
	return (args);
}

int	*argtype(char **av, int ac)
{
	int		i;
	int		*args;
	char	**fake_av;

	i = 0;
	fake_av = NULL;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (!ft_strchr("0123456789 ", av[1][i]))
				return (NULL);
			i++;
		}
		fake_av = ft_split(av[1], ' ');
		if (!fake_av)
			return (NULL);
		args = format_input(fake_av, ac);
	}
	else
		args = format_input(av, ac);
	return (free(fake_av), args);
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

int	arg_is_valid(int *args, int ac)	
{
	int		nb;

	nb = 0;
	if (!args)
		return (write(2, "Error\n", 6), 0);
	while (nb < ac)
	{
		if (args[nb] < INT_MIN || args[nb] > INT_MAX)
			return (free(args), 0);
		if (!check_dups(args, nb, ac))
			return (free(args), 0);
		nb++;
	}
	return (1);
}
/*
t_stack	*make_stack(char **av, int ac)
{
	t_stack	stack;
	t_node	*node;
	int		*args;
	int		i;

	i = 0;
	stack = (t_stack){0};
	args = check_argtype(av, ac);
	if (!args)
		return (write(2, "Error\n", 6), NULL);
	if (!arg_is_valid(args, ac))
		return (write(2, "Error\n", 6), NULL);
	while (i < ac)
	{
		node = ft_lstnew(args[i]);
		if (!node)
			return (free(args), NULL);
		ft_lstadd_back(&node, stack);
		i++;
	}
	stack.length = ac;
	return (free(args), stack);
}
*/
int	main(int ac, char *av[])
{
	int	i;
	int	*args;

	i = 0;
	if (ac == 1)
		return (1);
	args = argtype(av, ac);
	if (args == NULL)
		return (write(2, "Error\n", 6), 1);
	if (!arg_is_valid(args, ac))
		return (write(2, "Error\n", 6), 1);
	ft_printf("stack_a: \n\n");
	while (i < ac)
	{
		ft_printf("%d\n", args[i]);
		i++;
	}
	return (0);
}
