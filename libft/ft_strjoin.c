/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:27:31 by kprigent          #+#    #+#             */
/*   Updated: 2023/12/21 17:04:52 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;

	if (!s1 || !s2)
		return (NULL);
	tab = malloc(sizeof(char) * ((ft_strlen(s1)
					+ ft_strlen(s2)) + 1));
	if (tab == NULL)
		return (NULL);
	tab [0] = '\0';
	ft_strcat(tab, (char *)s1);
	ft_strcat(tab, (char *)s2);
	return (tab);
}
