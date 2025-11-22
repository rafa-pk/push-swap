/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:26:17 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/22 16:31:41 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst && lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*lst = NULL;

	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("Premier")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("Deuxieme")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("Troisieme")));

	printf("%d\n", ft_lstsize(lst));
	free(lst);
	return (0);
}*/
