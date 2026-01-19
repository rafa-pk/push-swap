/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:55:52 by rvaz-da-          #+#    #+#             */
/*   Updated: 2026/01/19 15:27:00 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

void	find_target_node(t_node *b_node, t_stack *stack_a)
{
	t_node	*a_node;
	t_node	*min;
	t_node	*best;

	a_node = stack_a->head;
	min = stack_a->head;
	best = NULL;
	while (a_node)
	{
		if (a_node->value < min->value)
			min = a_node;
		if (a_node->value > b_node->value)
		{
			if (!best || a_node->value < best->value)
				best = a_node;
		}
		a_node = a_node->next;
	}
	if (best)
		b_node->target = best;
	else
		b_node->target = min;
}

void	node_cost_a(t_node *b_node, t_stack *stack_a)
{
	int		index;
	int		target_index;
	t_node	*current;

	index = 0;
	current = stack_a->head;
	while (current)
	{
		if (current->value == b_node->target->value)
			target_index = index;
		index++;
		current = current->next;
	}
	if (target_index <= stack_a->length / 2)
		b_node->a_cost = target_index;
	else
		b_node->a_cost = -(stack_a->length - target_index);
}

void	rotate_both_stacks(t_stack *stack_a, t_stack *stack_b,
		t_node *cheapest_node)
{
	while (cheapest_node->a_cost > 0 && cheapest_node->b_cost > 0)
	{
		ft_rr(stack_a, stack_b);
		cheapest_node->a_cost--;
		cheapest_node->b_cost--;
	}
	while (cheapest_node->a_cost < 0 && cheapest_node->b_cost < 0)
	{
		ft_rrr(stack_a, stack_b);
		cheapest_node->a_cost++;
		cheapest_node->b_cost++;
	}
}

void	rotate_cheapest_node(t_stack *stack_b, t_node *cheapest_node)
{
	while (cheapest_node->b_cost > 0)
	{
		ft_rotate(stack_b, 'b', 1);
		cheapest_node->b_cost--;
	}
	while (cheapest_node->b_cost < 0)
	{
		ft_reverse_rotate(stack_b, 'b', 1);
		cheapest_node->b_cost++;
	}
}

void	rotate_target_node(t_stack *stack_a, t_stack *stack_b,
		t_node *cheapest_node)
{
	while (cheapest_node->a_cost > 0)
	{
		ft_rotate(stack_a, 'a', 1);
		cheapest_node->a_cost--;
	}
	while (cheapest_node->a_cost < 0)
	{
		ft_reverse_rotate(stack_a, 'a', 1);
		cheapest_node->a_cost++;
	}
}
