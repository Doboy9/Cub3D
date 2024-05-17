/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:16:15 by kprigent          #+#    #+#             */
/*   Updated: 2023/12/21 17:04:51 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t	size)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	if (size == 0)
		return (ft_strlen((char *)src));
	while (src[a] != '\0')
		a++;
	while (i < (size - 1) && i < a)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (a);
}
