/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:39:28 by revieira          #+#    #+#             */
/*   Updated: 2022/10/14 15:34:02 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	bytes_writes;

	bytes_writes = 0;
	if (!str)
		return (ft_print_str("(null)"));
	while (*str)
	{
		bytes_writes += ft_print_char(*str);
		str++;
	}
	return (bytes_writes);
}

int	ft_print_point(unsigned long n)
{
	int	bytes_writes;

	bytes_writes = ft_print_str("0x");
	bytes_writes += convert_hex_lower(n);
	return (bytes_writes);
}

int	check_after_percent(const char *str, va_list ap)
{
	int		bytes_writes;

	bytes_writes = 0;
	if (*str == 'c')
		bytes_writes = ft_print_char(va_arg(ap, int));
	else if (*str == 's')
		bytes_writes = ft_print_str(va_arg(ap, char *));
	else if (*str == 'd' || *str == 'i')
		bytes_writes = ft_putnbr(va_arg(ap, int));
	else if (*str == 'p')
		bytes_writes = ft_print_point(va_arg(ap, unsigned long));
	else if (*str == 'u')
		bytes_writes = ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (*str == 'x')
		bytes_writes = convert_hex_lower(va_arg(ap, int));
	else if (*str == 'X')
		bytes_writes = convert_hex_upper(va_arg(ap, int));
	else if (*str == '%')
		bytes_writes = ft_print_char('%');
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
			bytes_writes += ft_print_char(*format);
		format++;
	}
	return (bytes_writes);
}

/*int	main(void)
{
	int		i1;
	int		i2;
	int		c;
	char	*p;
	char	*str;

	p = (char *)malloc(sizeof(char));
	str = NULL;
	c = 'd';
	i1 = ft_printf("num: %p\n", p);
	i2 = printf("num: %p\n", p);
	printf("minha função: %d\nFunção orginal: %d", i1, i2);
	return (0);
}*/
