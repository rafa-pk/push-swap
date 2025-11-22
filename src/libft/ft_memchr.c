/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:32:21 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/22 16:15:01 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*str;

	i = 0;
	ch = (unsigned char) c;
	str = (unsigned char *) s;
	while (i < n)
	{
		if (str[i] == ch)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	unsigned char	str[] = "pipcacazoeprout";
//	int	str[] = {1, 2, 3, 5, 8, 9};
	
	printf("mine: %s\n", (unsigned char *) ft_memchr(str, 0, 0));
	printf("og: %s\n",(unsigned char *) memchr(str, 0, 0));
	return (0);
}*/
