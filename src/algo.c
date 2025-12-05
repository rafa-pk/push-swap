/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:54:30 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/12/05 13:01:12 by rvaz-da-         ###   ########.fr       */
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
//TODO: fix this 
void	calculate_costs(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		index;

	node = stack_a->head;
	index = 0;
	while (node)
	{
		if (index <= stack_a->length / 2)
			node->cost = index;
		else
			node->cost = stack_a->length - index;
		ft_printf("node[%d] cost in A: %d\n", index, node->cost);
		node->cost += destination_moves(node, stack_b);
		ft_printf("prout\n");
		index++;
		node = node->next;
	}
}

t_node	*find_cheapest(t_stack *stack_a, int *index)
{
	t_node	*current;
	t_node	*min;

	min = stack_a->head;
	current = stack_a->head;
	while (current)
	{
		if (current->cost > min->cost)
			min = current;
		(*index)++;
		current = current->next;
	}
	return (current);
}
/*
void	rotate_cheapest(t_stack *stack_a, t_node *cheapest, int index)
{
	t_node	*current;

	current = stack_a->head;
	while ()
	{
		
	}
}
*/
void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;
	t_node	*current;

	current = stack_a->head;
	int		index;
	int		i;
	
	if (stack_a->head->value > stack_a->head->next->value)
		ft_swap(stack_a, 'a', 1);
	ft_push(stack_a, stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
	print_stack(stack_a);
	print_stack(stack_b);
	//while (stack_a->length > 3)
	//{
		index = 0;
		i = 0;
		calculate_costs(stack_a, stack_b);
		while (current)
		{
			ft_printf("cost of node [%d]: %d\n", i, current->cost);
			i++;
			current = current->next;
		}
		cheapest = find_cheapest(stack_a, &index);
		ft_printf("cheapest node is node[%d]: %d", index, cheapest->value);
	//	rotate_cheapest(stack_a, cheapest, index);
	//	ft_push(stack_a, stack_b, 'b');
	//}
}
