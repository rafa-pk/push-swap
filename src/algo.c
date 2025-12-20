/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:54:30 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/12/20 20:56:17 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	calculate_costs(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		index;
	int		b_cost = 0;			//TODO: dont forget to del it

	node = stack_a->head;
	index = 0;
	while (node)
	{
		if (index <= stack_a->length / 2)
			node->cost = index;
		else
			node->cost = stack_a->length - index;
		b_cost = destination_moves(node, stack_b);
		node->cost += b_cost;
		index++;
		node = node->next;
	}
}

t_node	*find_cheapest(t_stack *stack_a, int *index)
{
	t_node	*current;
	t_node	*min;
	int		i;

	i = 0;
	min = stack_a->head;
	current = stack_a->head;
	while (current)
	{
		if (current->cost <  min->cost)
		{
			min = current;
			*index = i;
		}
		i++;
		current = current->next;
	}
	return (min);
}

void	rotate_cheapest(t_stack *stack_a, t_node *cheapest, int index)
{
	if (index == 0)
		return ;
	if (index > stack_a->length / 2)
		rotations(stack_a, "ra" , index);
	else
		rotations(stack_a, "rra", index);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;
	t_node	*current;
	int		index;
	
	if (stack_a->head->value > stack_a->head->next->value)
		ft_swap(stack_a, 'a', 1);
	ft_push(stack_a, stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
	while (stack_a->length > 3)
	{
		index = 0;
		calculate_costs(stack_a, stack_b);
		cheapest = find_cheapest(stack_a, &index);
		rotate_cheapest(stack_a, cheapest, index);
		ft_push(stack_a, stack_b, 'b');
		current = stack_a->head;
	}
	sort_remaining(stack_a);
	push_to_b(stack_a, stack_b);
}
