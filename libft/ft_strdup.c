/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:56:43 by kprigent          #+#    #+#             */
/*   Updated: 2023/12/21 17:04:54 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_len(const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*target;
	int		i;

	target = malloc(sizeof(char) * (ft_len(src) + 1));
	if (target == NULL)
		return (NULL);
	i = 0;
	while (i < ft_len(src))
	{
		target[i] = src[i];
		i++;
	}
	target[i] = '\0';
	return (target);
}
