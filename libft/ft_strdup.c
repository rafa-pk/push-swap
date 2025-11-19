/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:56:50 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/21 22:50:34 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*duplicate;

	i = 0;
	if (!str)
		return (NULL);
	duplicate = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!duplicate)
		return (NULL);
	while (str[i])
	{
		duplicate[i] = str[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}
/*
#include <stdio.h>
int	main(int ac, char *av[])
{
	(void)ac;
	printf("%s\n", ft_strdup(av[1]));
	return (0);
}*/
