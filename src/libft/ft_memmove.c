/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:39:33 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/14 15:45:44 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (d < s || d >= s + n)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
		while (n-- > 0)
			d[n] = s[n];
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	buff[12] = "pipicaca";
//	char	dest[10];

//	printf("mine:%s\n", (unsigned char *)ft_memmove(buff + 4, buff + 8, 4));
	printf("og: %s\n", (unsigned char *)ft_memmove(buff + 4, buff + 8, 4));
	return (0);
}*/
