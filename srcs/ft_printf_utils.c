/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:23:03 by revieira          #+#    #+#             */
/*   Updated: 2022/10/18 15:37:16 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_strlen(char	*str)
{
	int	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

int	putnbr_base(long long n, char *base)
{
	int	bytes_writes;
	int	len_base;

	len_base = ft_strlen(base);
	bytes_writes = 0;
	if (n < 0)
	{
		bytes_writes += print_char('-');
		n *= -1;
	}
	if (n < len_base)
		bytes_writes += print_char(base[n]);
	else
	{
		bytes_writes += putnbr_base(n / len_base, base);
		bytes_writes += putnbr_base(n % len_base, base);
	}
	return (bytes_writes);
}
int	unsigned_putnbr(unsigned long long n, char *base)
{
	int					bytes_writes;
	unsigned long long	len_base;

	len_base = ft_strlen(base);
	bytes_writes = 0;
	if (n < len_base)
		bytes_writes += print_char(base[n]);
	else
	{
		bytes_writes += putnbr_base(n / len_base, base);
		bytes_writes += putnbr_base(n % len_base, base);
	}
	return (bytes_writes);
}

int	print_point(unsigned long long n)
{
	int	bytes_writes;

	if (!n)
		return (print_str("(nil)"));
	bytes_writes = print_str("0x");
	bytes_writes += unsigned_putnbr(n, BASE_HEX_LOW);
	return (bytes_writes);
}
