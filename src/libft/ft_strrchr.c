/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:18:46 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/26 11:38:21 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	ch;

	i = ft_strlen(s);
	ch = (unsigned char) c;
	while (i > 0)
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i--;
	}
	if (ch == '\0')
		return ((char *) &s[i]);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char	s[] = "Hello World";
	const char	s1[] = "Hello World";

	printf("mine: %s\n", ft_strrchr(s, 'H'));
	printf("og: %s\n", strrchr(s1, 'H'));
	return (0);
}*/
