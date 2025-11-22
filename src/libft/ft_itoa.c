/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:21:40 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/21 22:39:03 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_count(long int nb)
{
	int	count;

	count = 1;
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	if (nb >= 10)
		count += int_count(nb / 10);
	return (count);
}

char	*ft_itoa(int n)
{
	long int	nb;
	int			len;
	char		*str;

	nb = n;
	len = int_count(nb);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb >= 10)
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	str[len] = nb + '0';
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	return (0);
}
*/
