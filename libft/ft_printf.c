/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:49:37 by kprigent          #+#    #+#             */
/*   Updated: 2024/01/02 20:32:40 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_format(const char *format, va_list args)
{
	int		tt_len;
	int		i;

	i = 1;
	tt_len = 0;
	if (*format == 'c')
		tt_len = ft_putcharp(va_arg(args, int));
	else if (*format == 's')
		tt_len = ft_putstrp(va_arg(args, const char *));
	else if (*format == 'p')
		tt_len = ft_putaddr(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i')
		tt_len = ft_putnbrp(va_arg(args, long int));
	else if (*format == 'u')
		tt_len = ft_putnbr_unsigned(va_arg(args, unsigned int),
				"0123456789", i);
	else if (*format == 'x')
		tt_len = ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789abcdef", i);
	else if (*format == 'X')
		tt_len = ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789ABCDEF", i);
	else if (*format == '%')
		tt_len = ft_putcharp('%');
	return (tt_len);
}

int	check_next(const char *format, int a)
{
	if (format[a] == '%' && (format[a + 1] == 'c' || format[a + 1] == 's'
			|| format[a + 1] == 'p' || format[a + 1] == 'd'
			|| format[a + 1] == 'i' || format[a + 1] == 'u'
			|| format[a + 1] == 'x' || format[a + 1] == 'X'
			|| format[a + 1] == '%'))
		return (1);
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	int		num_args;
	va_list	args;
	int		a;
	int		b;
	int		tt_len;

	num_args = ft_strlen(format);
	b = 0;
	a = 0;
	tt_len = 0;
	va_start(args, format);
	while (a < num_args)
	{
		if (check_next(format, a) == 1)
		{
			a++;
			b++;
			tt_len += ft_format(&format[a], args);
		}
		else
			ft_putcharp((char)format[a]);
		a++;
	}
	va_end(args);
	return (tt_len + (a - 2 * b));
}
