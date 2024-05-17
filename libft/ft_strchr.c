/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:16:50 by kprigent          #+#    #+#             */
/*   Updated: 2023/12/21 17:04:54 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*r;
	unsigned char	c1;

	i = 0;
	c1 = c;
	r = (char *)s;
	while (r[i] != '\0' || c1 == 0)
	{
		if (r[i] == c1)
			return (r + i);
		i++;
	}
	return (0);
}
