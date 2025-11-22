/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:30:35 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/21 15:37:58 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_return;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	lst_return = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&lst_return, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_return, node);
		lst = lst->next;
	}
	return (lst_return);
}
/*
#include <string.h>
void	*f(void *content)
{
	if (strcmp((char *)content, "caca") != 0)
        return ft_strdup("caca");
    return ft_strdup((char *)content);
}

void	del(void *lst)
{
	free(lst);
}

#include <stdio.h>
int	main(void)
{
	t_list	*lst = NULL;
	t_list	*new;
	t_list	*temp;

	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("premier")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("deuxieme")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("troisieme")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("quatrieme")));

	new = ft_lstmap(lst, f, del);
	temp = new;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	return (0);
}*/
