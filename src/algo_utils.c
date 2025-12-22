/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:55:52 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/12/22 12:51:10 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	get_moves(t_node *node_src, t_stack *stack_dest)
{
	int		index_dest;
	t_node	*node_dest;

	index_dest = 0;
	node_dest = stack_dest->head;
	while (node_dest)
	{
		if (node_src->value > node_dest->value || node_dest->next == NULL)
			return (index_dest);
		index_dest++;
		node_dest = node_dest->next;
	}
	if (index_dest > stack_dest->length / 2)
		index_dest = stack_dest->length - index_dest;
	return (index_dest);
}

int	destination_moves(t_node *node_src, t_stack *stack_dest)
{
	t_node	*node_dest;
	t_node	*node_dest2;
	int		index_dest;

	index_dest = 0;
	if (!stack_dest->head)
		return (0);
	node_dest = stack_dest->head;
	if (stack_dest->head && !stack_dest->head->next)
	{
		if (node_src->value > node_dest->value)
			return (0);
		return (1);
	}
	if (stack_dest->head && stack_dest->head->next)
	{
		node_dest2 = node_dest->next;
		if (node_src->value > node_dest->value && node_src->value > node_dest2->value)
			return (0);
	}
	return (get_moves(node_src, stack_dest));
}

void	rotations(t_stack *stack_a, char *flag, int index)
{
	int	i;

	i = 0;
	if (!ft_strncmp(flag, "ra", 2))
	{
		while (i < index)
		{
			ft_rotate(stack_a, 'a', 1);
			i++;
		}
	}
	else if (ft_strncmp(flag, "rra", 3))
	{
		while (i < index)
		{
			ft_reverse_rotate(stack_a, 'a', 1);
			i++;
		}
	}
}

void	sort_remaining(t_stack *stack_a)
{
	t_node	*current;

	if (is_sorted(stack_a))
		return ;
	while (!is_sorted(stack_a))
	{
		current = stack_a->head;
		if (current->value > current->next->value)
			ft_swap(stack_a, 'a', 1);
		else if (stack_a->tail->value < current->value && 
			stack_a->tail->value < current->next->value)
			ft_reverse_rotate(stack_a, 'a', 1);
		else
			ft_rotate(stack_a, 'a', 1);
	}
}

void	push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->length > 0)
	{
		//push to right place in a
		ft_push(stack_b, stack_a, 'a')
	}
}
