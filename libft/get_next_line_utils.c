/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:27:31 by kprigent          #+#    #+#             */
/*   Updated: 2023/12/21 17:04:40 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
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

char	*ft_strjoing(char const *s1, char const *s2)
{
	char	*tab;

	if (!s1 && s2)
	{
		tab = malloc(sizeof(char) * (ft_strlen(s2) + 1));
		if (tab == NULL)
			return (NULL);
		tab[0] = '\0';
		ft_strcat(tab, (char *)s2);
		return (tab);
	}
	tab = malloc(sizeof(char) * ((ft_strlen(s1)
					+ ft_strlen(s2)) + 1));
	if (!s2 || !tab)
		return (NULL);
	tab [0] = '\0';
	ft_strcat(tab, (char *)s1);
	ft_strcat(tab, (char *)s2);
	return (tab);
}

char	*delet_pos(char *buff)
{
	char	*tmp;
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\0')
	{
		free(buff);
		return (NULL);
	}
	tmp = malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (tmp == NULL)
		return (NULL);
	i++;
	while (buff[i] != '\0')
		tmp[a++] = buff[i++];
	tmp[a] = 0;
	free(buff);
	return (tmp);
}
