/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_p1_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:55:52 by rvaz-da-          #+#    #+#             */
/*   Updated: 2026/01/18 22:09:48 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sort_3(t_stack *stack)
{
	t_node	*current;

	if (is_sorted(stack))
		return ;
	while (!is_sorted(stack))
	{
		current = stack->head;
		if (current->value > current->next->value)
			ft_swap(stack, 'a', 1);
		else if (stack->tail->value < current->value && 
			stack->tail->value < current->next->value)
			ft_reverse_rotate(stack, 'a', 1);
		else
			ft_rotate(stack, 'a', 1);
	}
}

void	final_rotate(t_stack *stack_a)
{
	t_node	*current;
	int		position;

	if (strictly_ascending(stack_a))
		return ;
	current = stack_a->head;
	position = 0;
	while (current->next)
	{
		position++;
		if (current->value > current->next->value)
			break ;
		current = current->next;
	}
	if (position < stack_a->length)
	{
		while (position-- > 0)
			ft_rotate(stack_a, 'a', 1);
	}
	else
	{
		position = stack_a->length - position;
		while (position-- < 0)
			ft_reverse_rotate(stack_a, 'a', 1);
	}
}

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
	ft_printf("[%d] a cost: %d\n", b_node->value, b_node->a_cost);
}

void	rotate_both_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest_node;

	cheapest_node = stack_b->head;
	while (cheapest_node)
	{
		if (cheapest_node->cheapest)
			break ;
		cheapest_node = cheapest_node->next;
	}
	while (cheapest_node->a_cost > 0 && cheapest_node->b_cost > 0)
	{
		ft_rr(stack_a, stack_b);
		cheapest_node->a_cost--;
		cheapest_node->b_cost--;
	}
	while (cheapest_node->b_cost < 0 && cheapest_node->b_cost < 0)
	{
		ft_rrr(stack_a, stack_b);
		cheapest_node->a_cost++;
		cheapest_node->b_cost++;
	}
}

void	rotate_cheapest_node(t_stack *stack_b)
{
	t_node	*cheapest_node;

	cheapest_node = stack_b->head;
	while (cheapest_node)
	{
		if (cheapest_node->cheapest)
			break ;
		cheapest_node = cheapest_node->next;
	}
	while (cheapest_node->b_cost > 0)
	{
		ft_rotate(stack_b, 'b', 1);
		b_cost--;
	}
	while (cheapest_node->b_cost < 0)
	{
		ft_reverse_rotate(stack_b, 'b', 1);
		b_cost++;
	}
}

void	rotate_target_node(t_stack *stack_a, t_stack *stack_b)	//TODO: figure it out
{
	t_node	*cheapest_node;
	t_node	*target_node;

	cheapest_node = stack_b->head;
	target_node = stack_a->head;
	while (cheapest_node)
	{
		if (cheapest_node->cheapest)
			break ;
		cheapest_node = cheapest_node->next;
	}
	while (target_node)
	{
		if (target_node->value == cheapest_node->target->value)
			break ;
		target_node = target_node->next;
	}
	while (cheapest_node->a_cost > 0)
	{
		ft_rotate(stack_a, 'a', 1);
		a_cost--;
	}
	while (cheapest_node->a_cost < 0)
	{
		ft_reverse_rotate()
	}
}
