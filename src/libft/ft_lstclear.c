/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:14:50 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/22 02:56:50 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!*lst || !lst)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}
/*
void	del(void *list)
{
	free(list);
}

#include <stdio.h>
int	main(void)
{
	size_t	i = 0;
	t_list	*temp;
	t_list	*prev;
	t_list	*return_l;
	t_list	*lst = NULL;

	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("Quatre")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("Trois")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("Deux")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("Un")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("Zero")));
	temp = lst;
	while (i < 2)
	{
		temp = temp->next;
		i++;
	}
	i = 0;
	prev = lst;
	while (i < 1)
	{
		prev = prev->next;
		i++;
	}
	temp = prev->next;
	prev->next = NULL;
	ft_lstclear(&temp, del);
	return_l = lst;
	while (return_l)
	{
		printf("%s\n", (char *)return_l->content);
		return_l = return_l->next;
	}
	return (0);
}*/
