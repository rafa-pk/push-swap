/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:30:33 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/21 11:29:25 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}
/*
#include <string.h>
void	f(void *content)
{
	if (strcmp((char *)content, "pipi") == 0)
		strcpy((char *)content, "caca");
}

#include <stdio.h>
int	main(void)
{
	t_list	*lst = NULL;
	t_list	*temp;
	
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("3")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("pipi")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("caca")));
	ft_lstiter(lst, f);
	temp = lst;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	return (0);
}*/
