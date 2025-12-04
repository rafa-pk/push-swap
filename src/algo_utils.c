/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:55:52 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/12/04 12:08:33 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	destination_moves(t_node *node_a, t_stack *stack_b)
{
	t_node	*node_b;
	int		index_b;

	node_b = stack_b->head;
	index_b = 0;
	if (stack_b->size < 2)
		return (0);
	if (stack_b->size == 2)
	{
		if (node_a->value > node_b->value && node_a > node_b->next->value)
			return ();
		if (node_a->value < node_b->value && node_a < node_b->next->value)
			return ();
		else
			break;	
	}
	while (node)
	{
		if (node_a->value > node_b->value || node_b->next == NULL)
			return (index_b);
		index_b++;
		node = node->next;
	}
	return (index_b)
}

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
		node->cost = stack_a->length - index;
		node->cost += destination_moves(&node, stack_b);
		index++;
		node = node->next;
	}
}
