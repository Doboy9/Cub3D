/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:52:19 by kprigent          #+#    #+#             */
/*   Updated: 2024/01/02 20:35:27 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_next(int n)
{
	if (n == -2147483648)
		ft_putstrp("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putcharp('-');
			n = n * -1;
		}
		if (n > 9)
		{
			ft_putnbrp(n / 10);
		}
		ft_putcharp((n % 10) + '0');
	}
}

int	ft_putnbrp(int n)
{
	int	len;
	int	nb;
	int	neg;

	neg = 0;
	len = 1;
	nb = n;
	ft_putnbr_next(n);
	if (n == -2147483648)
		return (11);
	if (nb < 0)
	{
		nb *= -1;
		neg++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	return (len + neg);
}
