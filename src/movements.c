/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 21:24:07 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/12/19 14:13:33 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_swap(t_stack *stack, char flag, int stack_nb)
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
		if (stack_nb == 1)
			ft_printf("s%c\n", flag);
	}
}

void	ft_push(t_stack *src, t_stack *dest, char flag)
{
	t_node	*node;

	if (src->length < 1)
		return ;
	node = src->head;
	src->head = node->next;
	if (src->head)
		src->head->prev = NULL;
	else
		src->tail = NULL;
	src->length--;
	node->next = NULL;
	node->prev = NULL;
	ft_lstadd_front(dest, node);
	ft_printf("p%c\n", flag);
}

void	ft_rotate(t_stack *stack, char flag, int stack_nb)
{
	t_node	*temp;

	if (stack->length < 2)
		return ;
	temp = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	temp->prev = stack->tail;
	temp->next = NULL;
	stack->tail->next = temp;
	stack->tail = temp;
	if (stack_nb == 1)
		ft_printf("r%c", flag);
}

void	ft_reverse_rotate(t_stack *stack, char flag, int stack_nb)
{
	t_node	*temp;

	if (stack->length < 2)
		return ;
	temp = stack->tail;
	stack->tail = stack->tail->prev;
	stack->tail->next = NULL;
	temp->prev = NULL;
	temp->next = stack->head;
	stack->head->prev = temp;
	stack->head = temp;
	if (stack_nb == 1)
		ft_printf("rr%c\n", flag);
}
