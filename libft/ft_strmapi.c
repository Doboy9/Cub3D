/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:03:42 by kprigent          #+#    #+#             */
/*   Updated: 2023/12/21 17:04:48 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*n;

	i = 0;
	if (!s || !f)
		return (NULL);
	n = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (n == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		n[i] = f(i, s[i]);
		i++;
	}
	n[i] = '\0';
	return (n);
}
