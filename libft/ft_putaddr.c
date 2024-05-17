/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:52:00 by kprigent          #+#    #+#             */
/*   Updated: 2024/01/02 20:35:44 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_putnbr_adr(unsigned long int nb, char *base, int i)
{
	unsigned long int	len_base;

	len_base = ft_strlen(base);
	if (nb >= len_base)
		i = ft_putnbr_adr(nb / len_base, base, ++i);
	ft_putcharp(base[nb % len_base]);
	return (i);
}

int	ft_putaddr(void *ptr)
{
	int	i;

	i = 2;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	i = ft_putnbr_adr((unsigned long)ptr, "0123456789abcdef", i);
	return (i + 1);
}
