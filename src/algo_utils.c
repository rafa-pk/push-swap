/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:55:52 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/12/19 14:22:36 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	get_moves(t_node *node_a, t_stack *stack_b)
{
	int		index_b;
	t_node *node_b;

	index_b = 0;
	node_b = stack_b->head;
	while (node_b)
	{
		if (node_a->value > node_b->value || node_b->next == NULL)
			return (index_b);
		index_b++;
		node_b = node_b->next;
	}
	return (index_b);
}

int	destination_moves(t_node *node_a, t_stack *stack_b)
{
	t_node	*node_b;
	t_node	*node_b2;
	int		index_b;

	index_b = 0;
	if (!stack_b->head)
		return (0);
	node_b = stack_b->head;
	if (stack_b->head && !stack_b->head->next)
	{
		if (node_a->value > node_b->value)
			return (0);
		return (1);
	}
	if (stack_b->head && stack_b->head->next)
	{
		node_b2 = node_b->next;
		if (node_a->value > node_b->value && node_a->value > node_b2->value)
			return (0);
	}
	return (get_moves(node_a, stack_b));
}
