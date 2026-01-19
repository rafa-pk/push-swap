/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:19:20 by rvaz-da-          #+#    #+#             */
/*   Updated: 2026/01/19 18:47:39 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	main(int ac, char *av[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	
	if (ac == 1)
		return (1);
	stack_b = (t_stack){NULL, NULL, 0};
	stack_a = make_stack(av, ac);
	if (!stack_a.head)
		return (1);
	if (!checker(&stack_a, &stack_b))
		return (ft_printf("Error\n"), 1);
	if (strictly_ascending(&stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
