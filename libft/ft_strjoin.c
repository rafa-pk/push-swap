/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:03:14 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/22 02:35:37 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*jstr;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	jstr = malloc(sizeof(char) * (len + 1));
	if (!jstr)
		return (NULL);
	while (s1[i])
	{
		jstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		jstr[i + j] = s2[j];
		j++;
	}
	jstr[i + j] = '\0';
	return (jstr);
}
/*
#include <stdio.h>
int	main(void)
{
	char	s1[] = "";
	char	s2[] = "";
	char	*joined = ft_strjoin(s1, s2);

	printf("%s\n", joined);
	free(joined);
	return (0);
}*/
