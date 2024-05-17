/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:22:17 by kprigent          #+#    #+#             */
/*   Updated: 2023/12/21 17:04:44 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			a;
	size_t			i;
	unsigned char	*f;

	i = 0;
	a = 0;
	if (!s)
		return (NULL);
	if (len + start > (unsigned int)ft_strlen((char *)s))
		len = ft_strlen((char *)s) - start;
	if ((size_t)start > ft_strlen((char *)s) || (int)len < 0)
		f = malloc(sizeof(char) * 1);
	else
		f = malloc(sizeof(char) * (len + 1));
	if (f == NULL)
		return (NULL);
	while (s[i] != '\0' && (size_t)start < ft_strlen((char *)s))
	{
		if (i >= start && a < len)
			f[a++] = s[i];
		i++;
	}
	f[a] = '\0';
	return ((char *)f);
}
