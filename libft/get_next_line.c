/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:58:48 by kprigent          #+#    #+#             */
/*   Updated: 2024/01/02 20:39:09 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchrg(const char *s, int c)
{
	int				i;
	char			*r;
	unsigned char	c1;

	i = 0;
	c1 = c;
	r = (char *)s;
	while (r[i] != '\0' || c1 == 0)
	{
		if (r[i] == c1 || r[i] == '\0')
			return (r + i);
		i++;
	}
	return (0);
}

char	*put_in_chart(char *buff)
{
	char	*tab;
	int		i;
	int		k;

	i = 0;
	if (!buff)
		return (NULL);
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\n')
		i++;
	tab = malloc(sizeof(char) * (i + 1));
	if (tab == NULL)
		return (NULL);
	k = 0;
	while (k < i)
	{
		tab[k] = buff[k];
		k++;
	}
	tab[k] = '\0';
	return (tab);
}

char	*joinandfree(char *tab, char *buff)
{
	char	*tmp;

	tmp = ft_strjoing(tab, buff);
	free(tab);
	return (tmp);
}

char	*read_document(int fd, char *tab)
{
	char	*buff;
	int		size;

	size = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	while (size > 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == -1)
		{
			free(tab);
			free(buff);
			return (NULL);
		}
		buff[size] = '\0';
		tab = joinandfree(tab, buff);
		if (ft_strchrg(buff, '\n'))
			break ;
	}
	free(buff);
	return (tab);
}

char	*get_next_line(int fd)
{
	static char		*buff = NULL;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = read_document(fd, buff);
	if (!buff || buff[0] == '\0')
	{
		if (buff)
		{
			free(buff);
			buff = NULL;
		}
		return (NULL);
	}
	line = put_in_chart(buff);
	buff = delet_pos(buff);
	return (line);
}
