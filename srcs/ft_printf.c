/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:39:28 by revieira          #+#    #+#             */
/*   Updated: 2022/10/17 13:20:49 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_valided_specifier(char c, const char *format)
{
	while (*format)
	{
		if (*format == c)
			return (1);
		format++;
	}
	return (0);
}

int	check_after_percent(char specifier, va_list ap)
{
	int	bytes_writes;

	bytes_writes = 0;
	if (specifier == 'c')
		bytes_writes = print_char(va_arg(ap, int));
	else if (specifier == 's')
		bytes_writes = print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		bytes_writes = putnbr_base(va_arg(ap, int), BASE_DEC);
	else if (specifier == 'p')
		bytes_writes = print_point(va_arg(ap, unsigned long));
	else if (specifier == 'u')
		bytes_writes = putnbr_base(va_arg(ap, unsigned int), BASE_DEC);
	else if (specifier == 'x')
		bytes_writes = putnbr_base(va_arg(ap, unsigned long), BASE_HEX_LOW);
	else if (specifier == 'X')
		bytes_writes = putnbr_base(va_arg(ap, unsigned long), BASE_HEX_UPP);
	else if (specifier == '%')
		bytes_writes = print_char('%');
	return (bytes_writes);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		bytes_writes;

	va_start(args, format);
	bytes_writes = 0;
	while (*format)
	{
		if (*format == '%' && check_valided_specifier(*format, FORMATS))
		{
			format++;
			bytes_writes += check_after_percent(*format, args);
		}
		else
			bytes_writes += print_char(*format);
		format++;
	}
	return (bytes_writes);
}