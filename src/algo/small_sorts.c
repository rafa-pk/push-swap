/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:11:53 by rvaz-da-          #+#    #+#             */
/*   Updated: 2026/01/19 15:20:24 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

void	early_sorting(t_stack *stack_a)
{
	if (stack_a->length == 2 && !is_sorted(stack_a))
		ft_swap(stack_a, 'a', 1);
	else if (stack_a->length == 3 && !is_sorted(stack_a))
		sort_3(stack_a);
	final_rotate(stack_a);
	return ;
}

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
		else if (stack->tail->value < current->value
			&& stack->tail->value < current->next->value)
			ft_reverse_rotate(stack, 'a', 1);
		else
			ft_rotate(stack, 'a', 1);
	}
}
