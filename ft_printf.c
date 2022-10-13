/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:39:28 by revieira          #+#    #+#             */
/*   Updated: 2022/10/13 19:04:44 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_after_percent(const char *str, va_list args)
{
	int		bytes_writes;

	bytes_writes = 0;
	if (*str == 'c')
		bytes_writes = ft_putchar(va_arg(args, int));
	else if (*str == 's')
		bytes_writes = ft_putstr(va_arg(args, char *));
	else if (*str == 'd' || *str == 'i')
		bytes_writes = ft_putnbr(va_arg(args, int));
	/*else if (*str == 'p')
	 * bytes_writes =*/
	else if (*str == 'u')
		bytes_writes = ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (*str == 'x')
		bytes_writes = convert_hex_lower(va_arg(args, int));
	else if (*str == 'X')
		bytes_writes = convert_hex_upper(va_arg(args, int));
	else if (*str == '%')
		bytes_writes = ft_putchar('%');
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
		if (*format == '%')
		{
			format++;
			bytes_writes += check_after_percent(format, args);
		}
		else
			bytes_writes += ft_putchar(*format);
		format++;
	}
	return (bytes_writes);
}

int	main(void)
{
	int		i1;
	int		i2;
	int		c;
	char	*str;

	str = NULL;
	c = 'd';
	i1 = ft_printf("num: %u\n", 999999999);
	i2 = printf("num: %u\n", 999999999);
	printf("minha função: %d\nFunção orginal: %d", i1, i2);
	return (0);
}
