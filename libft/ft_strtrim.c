/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:38:48 by kprigent          #+#    #+#             */
/*   Updated: 2023/12/21 17:04:45 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	is_set(char const *s1, char const *set, int i)
{
	int	a;

	a = 0;
	while (set[a] != '\0')
	{
		if (set [a] == s1[i])
			return (1);
		a++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	start;
	int	end;

	end = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] != '\0' && is_set(s1, set, i) == 1)
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (i >= 0 && is_set(s1, set, i) == 1)
	{
		i--;
		end++;
	}
	return (ft_substr(s1, start, ft_strlen(s1) - start - end));
}
