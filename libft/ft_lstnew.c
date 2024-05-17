/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:33:51 by kprigent          #+#    #+#             */
/*   Updated: 2023/12/21 17:05:59 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*p;

	p = malloc(sizeof(t_list) * 1);
	if (p == NULL)
		return (NULL);
	p->content = content;
	p->next = NULL;
	return (p);
}
