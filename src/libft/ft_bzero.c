/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:21:27 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/22 01:46:53 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*buff;

	i = 0;
	buff = (unsigned char *) s;
	while (i < n)
	{
		buff[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	buff[] = "2vfjh124h";

	ft_bzero(buff, 5);
	printf("mine: %s\n", buff);

	bzero(buff, 5);
	printf("og: %s\n", buff);
	return (0);
}
*/
