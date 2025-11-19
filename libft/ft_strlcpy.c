/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:56:31 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/15 11:37:05 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;

	i = 0;
	if (dsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{ 
	size_t	len = 0;
	size_t	len2 = 0;
	char	dst[8];
	char	src[] = "Hello WOrld";

	len = ft_strlcpy(dst, src, 5);
	printf("mine: %s\n return: %zu\n\n", dst, len);
	len2 = strlcpy(dst, src, 5); 
	printf("og: %s\n return: %zu\n\n", dst, len2);
	return (0);
}*/
