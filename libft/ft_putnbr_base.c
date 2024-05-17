/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:52:00 by kprigent          #+#    #+#             */
/*   Updated: 2024/01/02 20:34:07 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbr_base(unsigned int nb, char *base, int i)
{
	unsigned int	len_base;

	len_base = (unsigned int)ft_strlen(base);
	if (nb >= len_base)
		i = ft_putnbr_base(nb / len_base, base, ++i);
	ft_putcharp(base[nb % len_base]);
	return (i);
}
