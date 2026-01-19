/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:37:11 by rvaz-da-          #+#    #+#             */
/*   Updated: 2026/01/19 19:19:12 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	move_exists(char *move)
{
	if (ft_strncmp(move, "pa", 2) == 0)
		return (1);
	else if (ft_strncmp(move, "pb", 2) == 0)
		return (1);
	else if (ft_strncmp(move, "sa", 2) == 0)
		return (1);
	else if (ft_strncmp(move, "sb", 2) == 0)
		return (1);
	else if (ft_strncmp(move, "ss", 2) == 0)
		return (1);
	else if (ft_strncmp(move, "ra", 2) == 0)
		return (1);
	else if (ft_strncmp(move, "rb", 2) == 0)
		return (1);
	else if (ft_strncmp(move, "rr", 2) == 0)
		return (1);
	else if (ft_strncmp(move, "rra", 3) == 0)
		return (1);
	else if (ft_strncmp(move, "rrb", 3) == 0)
		return (1);
	else if (ft_strncmp(move, "rrr", 3) == 0)
		return (1);
	return (0);
}

void	execute_moves(char *move, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(move, "pa", 2) == 0)
		ft_push(stack_b, stack_a, 'a');
	else if (ft_strncmp(move, "pb", 2) == 0)
		ft_push(stack_a, stack_b, 'b');
	else if (ft_strncmp(move, "sa", 2) == 0)
		ft_swap(stack_a, 'a', 0);
	else if (ft_strncmp(move, "sb", 2) == 0)
		ft_swap(stack_b, 'b', 0);
	else if (ft_strncmp(move, "ss", 2) == 0)
		ft_ss(stack_a, stack_b);
	else if (ft_strncmp(move, "ra", 2) == 0)
		ft_rotate(stack_a, 'a', 0);
	else if (ft_strncmp(move, "rb", 2) == 0)
		ft_rotate(stack_b, 'b', 0);
	else if (ft_strncmp(move, "rr", 2) == 0)
		ft_rr(stack_a, stack_b);
	else if (ft_strncmp(move, "rra", 3) == 0)
		ft_reverse_rotate(stack_a, 'a', 0);
	else if (ft_strncmp(move, "rrb", 3) == 0)
		ft_reverse_rotate(stack_b, 'b', 0);
	else if (ft_strncmp(move, "rrr", 3) == 0)
		ft_rrr(stack_a, stack_b);
}

int	checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		if (!move_exists(move))
			return (ft_printf("Error\n"), free(move), 0);
		execute_moves(move, stack_a, stack_b);
		free(move);
		move = get_next_line(0);
	}
	return (1);
}
