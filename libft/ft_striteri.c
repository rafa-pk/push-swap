/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 09:59:17 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/22 16:34:16 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	f(unsigned int i, char *s)
{
	if (i < 8)
		*s += 2;
}

#include <stdio.h>
int	main(void)
{
	char	s[] = "123456";
	
	ft_striteri(s, f);
	printf("%s\n", s);
	return (0);
}*/
