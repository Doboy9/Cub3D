/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:19:15 by kprigent          #+#    #+#             */
/*   Updated: 2023/12/21 17:06:02 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*stock;

	if (!lst || !f || !del)
		return (NULL);
	lst2 = ft_lstnew(f(lst->content));
	if (!lst2)
		return (NULL);
	stock = lst2;
	lst = lst->next;
	while (lst)
	{
		lst2->next = ft_lstnew(f(lst->content));
		if (!lst2->next)
		{
			ft_lstclear(&stock, del);
			return (0);
		}
		lst2 = lst2->next;
		lst = lst->next;
	}
	lst2->next = NULL;
	return (stock);
}
