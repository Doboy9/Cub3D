/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:32:42 by kprigent          #+#    #+#             */
/*   Updated: 2024/05/25 13:27:17 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_is_charset(const char *s, char c, int i)
{
	if (s[i] == c)
		return (1);
	else
		return (0);
}

static char	*ft_put_in_chart(const char *s, char c, int i, int end)
{
	char	*tab;
	int		j;
	int		z;

	z = 0;
	j = 0;
	if (i == 0 && s[i] != c)
		z++;
	tab = malloc(sizeof(char) * ((end - i) + z));
	if (tab == NULL)
		return (NULL);
	if (i == 0)
	{
		if (i == 0 && s[i] == c)
			i++;
		while (i < end)
			tab[j++] = s[i++];
	}
	else
	{
		while (i++ < end - 1)
			tab[j++] = s[i];
	}
	tab[j] = '\0';
	return (tab);
}

static int	ft_find_next_charset(const char *s, char c, int i)
{
	int	end;
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	end = i + 1;
	while (s[end] != '\0' && end <= len)
	{
		if (ft_is_charset(s, c, end) == 1)
			return (end);
		end++;
	}
	return (end);
}

static int	ft_size_malloc(const char *s, char c)
{
	int	i;
	int	end;
	int	b;

	b = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_is_charset(s, c, i) == 1
			|| (i == 0 && ft_is_charset(s, c, i) == 0))
		{
			end = ft_find_next_charset(s, c, i);
			if (end - i > 1 || (i == 0 && ft_is_charset(s, c, i) == 0))
				b++;
		}
		i++;
	}
	return (b);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		b;
	int		end;
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_size_malloc(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	b = 0;
	while (s[i] != '\0')
	{
		if (ft_is_charset(s, c, i) == 1 || i == 0)
		{
			end = ft_find_next_charset(s, c, i);
			if (end - i > 1 || (i == 0 && ft_is_charset(s, c, i) == 0))
				tab[b++] = ft_put_in_chart(s, c, i, end);
		}
		i++;
	}
	tab[b] = 0;
	return (tab);
}
