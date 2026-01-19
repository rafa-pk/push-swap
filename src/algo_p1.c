/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_p1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:54:30 by rvaz-da-          #+#    #+#             */
/*   Updated: 2026/01/18 22:09:12 by rvaz-da-         ###   ########.fr       */
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

void	calculate_costs(t_stack *stack_a, t_stack *stack_b, int *index)
{
	t_node	*current;

	current = stack_b->head;
	*index = 0;
	while(current)
	{
		if ((*index) <= stack_b->length / 2)
			current->b_cost = *index;
		else
			current->b_cost = -(stack_b->length - *index);
		ft_printf("[%d] b cost: %d\n", current->value, current->b_cost);
		node_cost_a(current, stack_a);
		current->total_cost = abs(current->a_cost) + abs(current->b_cost);
		(*index)++;
		current = current->next;
	}
}

void	find_cheapest_node(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	int		min;

	current = stack_b->head;
	min = current->total_cost;
	while (current)
	{
		if (current->total_cost < min)
			min = current->total_cost;
		current = current->next;
	}
	current = stack_b->head;
	while (current)
	{
		if (current->total_cost == min)
			current->cheapest = 1;
		current = current->next;
	}
}

void	rotate_stacks_to_place(t_stack *stack_a, t_stack *stack_b)
{
	rotate_both_stacks(stack_a, stack_b);
	rotate_cheapest_node(stack_b);
	rotate_target_node(stack_a, stack_b);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;
	int		index;

	index = 0;
	if (stack_a->length <= 3)
		return (early_sorting(stack_a));
	while (stack_a->length > 3)
		ft_push(stack_a, stack_b, 'b');
	sort_3(stack_a);
	//while (stack_b->length > 0)
	//{
		print_stack(stack_a);
		print_stack(stack_b);
		ft_printf("\n\n\n");
		assign_target_nodes(stack_b, stack_a);
		calculate_costs(stack_a, stack_b, &index);
		cheapest = find_cheapest_node(stack_a, stack_b);
		//rotate_stacks_to_place(stack_a, stack_b, cheapest);
		//ft_push(stack_b, stack_a, 'a');
	//}
	final_rotate(stack_a);
}

