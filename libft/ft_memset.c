/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:21:16 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/15 11:49:25 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*buff;

	i = 0;
	buff = (unsigned char *) s;
	while (i < n)
	{
		buff[i] = c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	buffer[20];

	memset(buffer, 0, sizeof(buffer));
	memset(buffer, '7', 15);
	printf("buffer og: %s\n", buffer);
	
	memset(buffer, 0, sizeof(buffer));
	ft_memset(buffer, 'P', 10);
	printf("buffer mine: %s\n", buffer);
	return (0);
}*/
