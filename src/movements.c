/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 21:24:07 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/11/25 13:42:04 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_swap(t_stack *stack, char flag)
{
	t_node	*temp;

	if (stack->length < 2)
		return ;
	else
	{
		temp = stack->head->next;
		stack->head->next = temp->next;
		temp->next = stack->head;
		stack->head = temp;
		ft_printf("s%c\n", flag);
	}
}

void	ft_push(t_stack *src, t_stack *dest, char flag)
{
	if (src->length == 0)
		return ;
	else
	{
		dest->head->value = src->head->value;
		ft_lstdelone(&src, src->head);
	}
	ft_printf("p%c\n", flag);
}
