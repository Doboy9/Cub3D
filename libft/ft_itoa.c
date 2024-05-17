/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:52:47 by kprigent          #+#    #+#             */
/*   Updated: 2023/12/21 17:06:15 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ssize(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			i;
	char		*tab;
	int			size;
	long int	n1;

	i = 0;
	n1 = n;
	size = ssize(n);
	tab = malloc(sizeof(char) * (size + 1));
	if (tab == NULL)
		return (NULL);
	if (n1 < 0)
	{
		tab[0] = '-';
		i++;
		n1 *= -1;
	}
	tab[size] = '\0';
	while (size > i)
	{
		size--;
		tab[size] = n1 % 10 + '0';
		n1 /= 10;
	}
	return (tab);
}
