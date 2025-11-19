/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:05:38 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/17 16:50:40 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*newstr;

	if (!s || !f)
		return (NULL);
	i = 0;
	newstr = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!newstr)
		return (NULL);
	while (s[i])
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
/*
char	f(unsigned int i, char c)
{
	if (i % 2)
		return (c + 2);
	return (c);
}

#include <stdio.h>
int	main(void)
{
	char	s[] = "123456";

	printf("%s\n", ft_strmapi(s, f));
	return (0);
}
*/
