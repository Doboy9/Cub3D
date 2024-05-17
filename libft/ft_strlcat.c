/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:30:09 by kprigent          #+#    #+#             */
/*   Updated: 2023/12/21 17:04:52 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t count)
{
	size_t	i;
	size_t	a;

	a = 0;
	i = 0;
	if (count == 0)
		return (ft_strlen((char *)src));
	while (dest[i] != '\0' && i < count)
		i++;
	while (src[a] != '\0' && ((i + a) < (count - 1)))
	{
		dest[i + a] = src[a];
		a++;
	}
	if (i < count)
		dest[i + a] = '\0';
	return (i + ft_strlen((char *)src));
}
