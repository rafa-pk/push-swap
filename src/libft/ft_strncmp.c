/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:17:09 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/22 01:37:52 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char	s1[] = "abc";
	const char	s2[] = "abcdef";
	const char	s1og[] = "abc";
	const char	s2og[] = "abcdef";

	printf("mine: %d\n", ft_strncmp(s1, s2, 5));
	printf("og: %d\n", strncmp(s1og, s2og, 5));
	return (0);
}
*/
