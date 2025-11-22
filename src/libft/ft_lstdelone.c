/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:53:20 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/20 12:06:03 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}

void	del(void *list)
{
	free(list);
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*delnode;
	t_list	*lst = NULL;

	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("Premier")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("Deuxieme")));
	delnode = lst->next;
	lst->next = delnode->next;
	ft_lstdelone(delnode, del);
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
	return (0);
}*/
