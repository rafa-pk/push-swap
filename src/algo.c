/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:54:30 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/12/20 19:10:29 by rvaz-da-         ###   ########.fr       */
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
		ft_printf("cost of node[%d] (%d) in stack B: %d\n", index, node->value, b_cost);
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
		ft_printf("node %d cost: %d\n", i, current->cost);
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
	//int		i;
	
	if (stack_a->head->value > stack_a->head->next->value)
		ft_swap(stack_a, 'a', 1);
	ft_push(stack_a, stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
	while (stack_a->length > 3)
	{
		index = 0;
		//i = 0;
		current = stack_a->head;
		calculate_costs(stack_a, stack_b);
		/*while (current)
		{
			ft_printf("cost of node [%d] (%d): %d\n", i, current->value, current->cost);
			i++;
			current = current->next;
		}*/
		cheapest = find_cheapest(stack_a, &index);
		rotate_cheapest(stack_a, cheapest, index);
		ft_push(stack_a, stack_b, 'b');
	}
}
