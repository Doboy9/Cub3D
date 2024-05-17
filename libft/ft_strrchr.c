/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:05:47 by kprigent          #+#    #+#             */
/*   Updated: 2023/12/21 17:04:45 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*r;
	unsigned char	c1;

	i = 0;
	c1 = c;
	r = (char *)s;
	while (r[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (r[i] == c1)
			return (r + i);
		i--;
	}
	return (0);
}
