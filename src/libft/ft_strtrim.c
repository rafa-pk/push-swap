/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:24:40 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/22 02:41:08 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (char_in_set(s1[start], set))
		start++;
	while (end >= start && char_in_set(s1[end - 1], set))
		end--;
	trim = malloc(sizeof(char) * (end - start) + 1);
	if (!trim)
		return (NULL);
	while (start < end)
		trim[i++] = s1[start++];
	trim[i] = '\0';
	return (trim);
}
/*
#include <stdio.h>
int	main(void)
{
	char const	s1[] = "xxHelloxx";
	char const	set[] = 'x'; 
	char *result = ft_strtrim(s1, set);

	printf("%s\n", result);
	//printf("%d\n", char_in_set(s1, set));
	free(result);
	return (0);
}
*/
