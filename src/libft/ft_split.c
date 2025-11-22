/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:02:52 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/21 22:41:10 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char c)
{
	int	i;
	int	word;
	int	count;

	i = 0;
	word = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			if (!word)
			{
				count++;
				word = 1;
			}
		}
		else
			word = 0;
		i++;
	}
	return (count);
}

static char	*ft_strndup(char *str, char c, int *ix)
{
	int		i;
	int		len;
	char	*substr;

	i = 0;
	len = 0;
	while (str[*ix] && str[*ix] == c)
		(*ix)++;
	while (str[*ix + len] && str[*ix + len] != c)
		len++;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = str[*ix];
		(*ix)++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	**ft_split(char *str, char c)
{
	int		i;
	int		ix;
	int		strnum;
	char	**split;

	if (!str)
		return (NULL);
	i = 0;
	ix = 0;
	strnum = count_words(str, c);
	split = malloc(sizeof(char *) * (strnum + 1));
	if (!split)
		return (NULL);
	while (i < strnum)
	{
		split[i] = ft_strndup(str, c, &ix);
		i++;
	}
	split[i] = NULL;
	return (split);
}
/*
#include <stdio.h>
int	main(void)
{
	int		i = 0;
	char	*str = "........pipi.caca.       .pipicaca.....";
	char	**result = ft_split(str, '.');
	
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}*/
