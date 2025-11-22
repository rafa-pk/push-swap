/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:04:16 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/11/22 00:44:40 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

void	free_table(char **table)
{
	int	i;

	if (!table)
		return ;
	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}
