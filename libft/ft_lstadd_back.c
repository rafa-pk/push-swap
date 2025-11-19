/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:28:05 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/22 16:28:20 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*current;
	t_list	*lst = NULL;
	t_list	*t1 = ft_lstnew(ft_strdup("three"));
	t_list	*t2 = ft_lstnew(ft_strdup("two"));
	t_list	*t3 = ft_lstnew(ft_strdup("five"));
	if (!t1 || !t2 || !t3)
		return (0);
	ft_lstadd_back(&lst, t3);
	ft_lstadd_back(&lst, NULL);
	ft_lstadd_back(&lst, t2);
	current = lst;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
}*/
