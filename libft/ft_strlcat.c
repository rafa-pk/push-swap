/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:51:59 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/15 12:55:31 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	slen;
	size_t	dlen;

	i = 0;
	j = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	j = dlen;
	if (size <= dlen)
		return (size + slen);
	while (src[i] && j < size - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dlen + slen);
}
/*
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char	dst[9] = "pipi";
	char	src[] = "caca";

	printf("dst: %s\nsrc:%s\n\n", dst, src);
	ft_strlcat(dst, src, 0);
	printf("my cat: %s\n", dst);
	//strlcat(dst, src, 0);
	//printf("og cat: %s\n", dst);
	return (0);
}*/
