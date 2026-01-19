/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42begium.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:21:35 by rvaz-da-          #+#    #+#             */
/*   Updated: 2026/01/19 17:56:36 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

#include "../pushswap.h"

int		checker(t_stack *stack_a, t_stack *stack_b);
int		move_exists(char *move);
void	execute_moves(char *move, t_stack *stack_a, t_stack *stack_b);

# endif
