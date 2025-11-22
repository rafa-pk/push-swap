/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:51:04 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/22 16:29:42 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*lst = NULL;
	t_list	*current;
	t_list	*t1 = ft_lstnew(ft_strdup("deuxieme"));
	t_list	*t2 = ft_lstnew(ft_strdup("quatrieme"));
	t_list	*t3 = ft_lstnew(ft_strdup("troisieme"));
	t_list	*t0 = ft_lstnew(ft_strdup("Hello World!"));	
	if (!t0 || !t1 || !t2 || !t3)
		return (1);

	ft_lstadd_front(&lst, t2);
	ft_lstadd_front(&lst, t3);
	ft_lstadd_front(&lst, t1);
	ft_lstadd_front(&lst, t0);
	current = lst;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
}*/
