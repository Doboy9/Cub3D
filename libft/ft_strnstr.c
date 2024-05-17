/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:17:03 by kprigent          #+#    #+#             */
/*   Updated: 2023/12/21 17:04:46 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	a;
	size_t	b;

	i = 0;
	a = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	if (s1 == NULL && n == 0)
		return (NULL);
	while (s2[a] != '\0')
		a++;
	while (s1[i] != '\0' && i + a <= n)
	{
		b = 0;
		while (s1[i + b] == s2[b] && b < a)
		{
			b++;
			if (b == a)
				return (&((char *)s1)[i]);
		}
		i++;
	}
	return (0);
}
