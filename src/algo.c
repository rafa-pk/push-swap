/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:54:30 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/12/03 17:25:58 by rvaz-da-         ###   ########.fr       */
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

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	s_node	*cheapest
	
	ft_push(stack_a, stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
	while (stack_a->length > 3)
	{
		calculate_costs(stack_a, stack_b);
		cheapest = find_cheapest:
		//rotate
		ft_push(stack_a, stack_b, 'b');
	}

}

//parcourir stack
//trouver element plus grand
//c
