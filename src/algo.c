/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:54:30 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/12/04 14:53:45 by rvaz-da-         ###   ########.fr       */
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

//TODO: move calculate_costs here

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;
	
	if (stack_a->head->value > stack_a->head->next->value)
		ft_swap(stack_a, 'a', 1);
	ft_push(stack_a, stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
	while (stack_a->length > 3)
	{
		calculate_costs(stack_a, stack_b);
		cheapest = find_cheapest(stack_a);
		rotate_cheapest(stack_a);
		ft_push(stack_a, stack_b, 'b');
	}
}
