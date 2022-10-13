/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:39:28 by revieira          #+#    #+#             */
/*   Updated: 2022/10/13 13:34:27 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

static int	check_after_percent(char *str, va_list args)
{
	int		bytes_writes;
	char	car;

	bytes_writes = 0;
	str++;
	if (*str == 'c')
	{
		car = va_arg(args, int);
		bytes_writes = write(1, &car, 1);
	}
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
			bytes_writes += check_after_percent((char *)format, args);
			format++;
		}
		else
			bytes_writes += write(1, &(*format), 1);
		format++;
	}
	return (bytes_writes);
}

int	main(void)
{
	int	i;
	int	c;

	c = 'd';
	i = ft_printf("algo%calgo\n", c);
	printf("%d\n", i);
	return (0);
}
