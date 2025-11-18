/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:58:05 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/11/18 21:55:11 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char *av[])
{
	if (ac == 1 || !arg_isvalid(av))
		return (write(2, "Error\n", 6), 1);
	stack_a = make_stack(&av[1], ac - 1);

	return (0);
}
