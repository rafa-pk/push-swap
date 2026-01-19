/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:04:39 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/12/05 11:31:00 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_node	*ft_lstnew(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->value = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (stack->head == NULL)
	{
		stack->head = node;
		stack->tail = node;
		node->prev = NULL;
		node->next = NULL;
	}
	else
	{
		stack->tail->next = node;
		node->prev = stack->tail;
		node->next = NULL;
		stack->tail = node;
	}
	stack->length++;
}

void	ft_lstadd_front(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (stack->head == NULL)
	{
		stack->head = node;
		stack->tail = node;
		node->prev = NULL;
		node->next = NULL;
	}
	else
	{
		node->next = stack->head;
		stack->head->prev = node;
	}
	stack->head = node;
	node->prev = NULL;
	stack->length++;
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	while (stack->head)
	{
		temp = stack->head->next;
		free(stack->head);
		stack->head = temp;
	}
	stack->tail = NULL;
	stack->length = 0;
}
