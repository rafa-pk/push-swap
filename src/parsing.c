/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:50:55 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/11/23 21:08:02 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

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
			if (!ft_isvalid(av[i][j], j))
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
			if (!ft_strchr("0123456789 -+", av[1][i]))
				return ((t_arr){NULL, 0});
			i++;
		}
		fake_av = ft_split(av[1], ' ');
		if (!fake_av)
			return ((t_arr){NULL, 0});
		args = format_input(fake_av, tab_len(fake_av));
		if (!args.arr || (args.length == 0))
			return (free_table(fake_av), (t_arr){NULL, 0});
		return (free_table(fake_av), args);
	}
	else
		return (format_input(&av[1], ac - 1));
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

t_stack	make_stack(char **av, int ac)
{
	t_stack	stack;
	t_node	*node;
	t_arr	args;
	int		i;

	i =0;
	stack = (t_stack){NULL, NULL, 0};
	args = argtype(av, ac);
	if (!args.arr || args.length == 0)
		return (write(2, "Error\n", 6), (t_stack){NULL, NULL, 0});
	if (!arg_is_valid(args))
		return (write(2, "Error\n", 6), (t_stack){NULL, NULL, 0});
	while (i < args.length)
	{
		node = ft_lstnew(args.arr[i]);
		if (!node)
			return (free(args.arr), free_stack(&stack), (t_stack){NULL, NULL, 0});
		ft_lstadd_back(&stack, node);
		i++;
	}
	free(args.arr);
	return (stack);
}

int	main(int ac, char *av[])
{
	t_node	*current;
	t_stack	stack_a;

	stack_a = (t_stack){NULL, NULL, 0};
	if (ac == 1)
		return (1);
	stack_a = make_stack(av, ac);
	if (!stack_a.head)
		return (1);
	current = stack_a.head;
	ft_printf("stack_a: \n");
	while (current != NULL)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
	free_stack(&stack_a);
	return (0);
}
