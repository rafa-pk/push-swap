/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:01:44 by rvaz-da-          #+#    #+#             */
/*   Updated: 2026/01/18 16:31:00 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	strictly_ascending(t_stack *stack_a)
{
	t_node	*current;

	current = stack_a->head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	int		i;
	t_node	*current;
	int		rot;

	i = 0;
	current = stack->head;
	rot = 0;
	while (i < stack->length - 1)
	{
		if (current->value > current->next->value)
		{
			rot++;
			if (rot > 1)
				return (0);
		}
		i++;
		current = current->next;
	}
	if (current->value > stack->head->value)
		rot++;
	return (rot <= 1);
}

int	abs(int value)
{
	if (value < 0)
		return (value *= -1);
	else
		return (value);
}
