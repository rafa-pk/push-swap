/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 21:52:06 by rvaz-da-          #+#    #+#             */
/*   Updated: 2026/01/19 15:20:57 by rvaz-da-         ###   ########.fr       */
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

int	ft_isvalid(char c, int ix)
{
	if (ft_isdigit(c))
		return (1);
	if (c == ' ')
		return (1);
	if (ix == 0 && (c == '-' || c == '+'))
		return (1);
	return (0);
}

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
