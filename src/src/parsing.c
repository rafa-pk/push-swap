/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:50:55 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/11/22 01:01:24 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

//TODO: fix les leaks — free de pointeurs non-alloués
//format_input prends le vrai av mais aussi fake_av, lui alloué
//du coup il ne peut pas free de la même manière
//faut un flag (un bool passé en fonction ou une entrée de la struct)

t_arr	format_input(char **av, int ac)
{
	int		i;
	int		j;
	int		nb;
	t_arr	args;

	i = 0;
	j = 0;
	nb = 0;
	args.arr = ft_calloc(ac, sizeof(int));
	if (!args.arr)
		return ((t_arr){NULL, 0});
	while (av[i])
	{
		j = -1;
		if (av[i][0] == '\0')
			return (free(args.arr), (t_arr){NULL, 0});
		while (av[i][++j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' '
				&& !(j == 0 && av[i][j] == '-'))
				return (free(args.arr), (t_arr){NULL, 0});
		}
		args.arr[nb++] = ft_atoi(av[i++]);
	}
	args.length = nb;
	return (args);
}

t_arr	argtype(char **av, int ac)
{
	int		i;
	t_arr	args;
	char	**fake_av;

	i = 0;
	fake_av = NULL;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (!ft_strchr("0123456789 -", av[1][i]))
				return ((t_arr){NULL, 0});
			i++;
		}
		fake_av = ft_split(av[1], ' ');			//TODO: protéger split
		if (!fake_av)
			return ((t_arr){NULL, 0});
		args = format_input(fake_av, tab_len(fake_av), false);
		if (!args.arr || (args.length == 0))
			return (free_table(fake_av), (t_arr){NULL, 0});
		return (free_table(fake_av), args);
	}
	return (format_input(&av[1], ac));			//TODO: source des leaks
}

int	check_dups(t_arr args, int ix)
{
	int	i;

	i = ix + 1;
	if (args.length == 1)
		return (1);
	while (i < args.length)
	{
		if (args.arr[ix] == args.arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	arg_is_valid(t_arr args)
{
	int		nb;

	nb = 0;
	if (!args.arr || (args.length == 0))
		return (write(2, "Error\n", 6), 0);
	while (nb < args.length)
	{
		if (args.arr[nb] < INT_MIN || args.arr[nb] > INT_MAX)
			return (free(args.arr), 0);
		if (!check_dups(args, nb))
			return (free(args.arr), 0);
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
	args = argtype(av, ac);
	if (!args.arr || args.length == 0)
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
	int		i;
	t_arr	args;

	i = 0;
	if (ac == 1)
		return (1);
	args = argtype(av, ac);
	if (!args.arr || (args.length == 0))
		return (write(2, "Error\n", 6), 1);
	if (!arg_is_valid(args))
		return (write(2, "Error\n", 6), 1);
	ft_printf("stack_a: \n");
	while (i < args.length)
	{
		ft_printf("%d\n", args.arr[i]);
		i++;
	}
	free(args.arr);
	return (0);
}
