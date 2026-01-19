/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_p1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:54:30 by rvaz-da-          #+#    #+#             */
/*   Updated: 2026/01/19 12:16:35 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	early_sorting(t_stack *stack_a)
{
	if (stack_a->length == 2 && !is_sorted(stack_a))
		ft_swap(stack_a, 'a', 1);
	else if (stack_a->length == 3 && !is_sorted(stack_a))
		sort_3(stack_a);
	final_rotate(stack_a);
	return ;
}

void	assign_target_nodes(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*node_b;

	node_b = stack_b->head;
	while (node_b)
	{
		find_target_node(node_b, stack_a);
		node_b = node_b->next;
	}
}

void	calculate_costs(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	int		index;

	current = stack_b->head;
	index = 0;
	while(current)
	{
		if (index <= stack_b->length / 2)
			current->b_cost = index;
		else
			current->b_cost = -(stack_b->length - index);
		//ft_printf("[%d] b cost: %d\n", current->value, current->b_cost);
		node_cost_a(current, stack_a);
		current->total_cost = abs(current->a_cost) + abs(current->b_cost);
		//ft_printf("[%d] total cost: %d\n", current->value, current->total_cost);
		index++;
		current = current->next;
	}
}

t_node	*find_cheapest_node(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_node	*cheapest;

	current = stack_b->head;
	cheapest = stack_b->head;
	while (current)
	{
		if (current->total_cost < cheapest->total_cost)
			cheapest = current;
		current = current->next;
	}
	//ft_printf("cheapest node: [%d]: %d moves\n", cheapest->value, cheapest->total_cost);
	return (cheapest);
}

void	rotate_stacks_to_place(t_stack *stack_a, t_stack *stack_b, t_node *cheapest_node)
{
	rotate_both_stacks(stack_a, stack_b, cheapest_node);
	rotate_cheapest_node(stack_b, cheapest_node);
	rotate_target_node(stack_a, stack_b, cheapest_node);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest_node;

	if (stack_a->length <= 3)
		return (early_sorting(stack_a));
	while (stack_a->length > 3)
		ft_push(stack_a, stack_b, 'b');
	sort_3(stack_a);
	while (stack_b->length > 0)
	{
		assign_target_nodes(stack_b, stack_a);
		calculate_costs(stack_a, stack_b);
		cheapest_node = find_cheapest_node(stack_a, stack_b);
		rotate_stacks_to_place(stack_a, stack_b, cheapest_node);
		ft_push(stack_b, stack_a, 'a');
	}
	final_rotate(stack_a);
}

