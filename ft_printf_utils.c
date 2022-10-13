/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:23:03 by revieira          #+#    #+#             */
/*   Updated: 2022/10/13 19:02:45 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	bytes_writes;

	bytes_writes = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
	{
		bytes_writes += ft_putchar(*str);
		str++;
	}
	return (bytes_writes);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	bytes_writes;

	bytes_writes = 0;
	if (n < 10)
		bytes_writes += ft_putchar(n + 48);
	else
	{
		bytes_writes += ft_putnbr_unsigned(n / 10);
		bytes_writes += ft_putnbr_unsigned(n % 10);
	}
	return (bytes_writes);
}

int	ft_putnbr(int n)
{
	int	bytes_writes;

	bytes_writes = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n < 0)
	{
		bytes_writes += ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
		bytes_writes += ft_putchar(n + 48);
	else
	{
		bytes_writes += ft_putnbr(n / 10);
		bytes_writes += ft_putnbr(n % 10);
	}
	return (bytes_writes);
}

int	convert_hex_upper(int n)
{
	char	str[10];
	int		temp;
	int		i;

	i = n;
	temp = 0;
	if (n == 0)
		return (ft_putchar('0'));
	while (i != 0)
	{
		i /= 16;
		temp++;
	}
	i = temp;
	str[i] = '\0';
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			str[--i] = temp + 48;
		else
			str[--i] = temp + 55;
		n /= 16;
	}
	return (ft_putstr(str));
}

int	convert_hex_lower(int n)
{
	char	str[10];
	int		temp;
	int		i;

	i = n;
	temp = 0;
	if (n == 0)
		return (ft_putchar('0'));
	while (i != 0)
	{
		i /= 16;
		temp++;
	}
	i = temp;
	str[i] = '\0';
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			str[--i] = temp + 48;
		else
			str[--i] = temp + 87;
		n /= 16;
	}
	return (ft_putstr(str));
}


