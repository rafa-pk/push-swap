/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:53:06 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/15 22:57:41 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*cal;
	size_t			i;
	size_t			buff_s;

	buff_s = nmemb * size;
	if (size != 0 && nmemb > (size_t)-1 / size)
		return (0);
	cal = malloc(sizeof(unsigned char) * buff_s);
	if (!cal)
		return (NULL);
	i = 0;
	while (cal[i])
	{
		cal[i] = 0;
		i++;
	}
	return ((void *)cal);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	char	*ft_buff = ft_calloc(9, 4);
	char	*buff = calloc(9, 4);
	
	for (int i = 0; i < 9; i++)
    	ft_buff[i] = i;
	for (int i = 0; i < 9; i++)
    	buff[i] = i;
	printf("my malloc: ");
	for (int i = 0; i < 9; i++)
    	printf("%d ", ft_buff[i]);
	printf("\n");
	printf("og calloc: ");
	for (int i = 0; i < 9; i++)
    	printf("%d ", buff[i]);
	printf("\n");
	return (0);
}*/
