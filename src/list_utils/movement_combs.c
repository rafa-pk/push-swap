/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_combs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:35:19 by rvaz-da-          #+#    #+#             */
/*   Updated: 2026/01/19 15:21:53 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a, 'a', 0);
	ft_swap(stack_b, 'b', 0);
	ft_printf("ss\n");
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a, 'a', 0);
	ft_rotate(stack_b, 'b', 0);
	ft_printf("rr\n");
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_reverse_rotate(stack_a, 'a', 0);
	ft_reverse_rotate(stack_b, 'b', 0);
	ft_printf("rrr\n");
}
