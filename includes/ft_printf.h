/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:37:37 by revieira          #+#    #+#             */
/*   Updated: 2022/10/17 13:20:07 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

# define FORMATS		"cspdiuxX%"
# define BASE_DEC		"0123456789"
# define BASE_HEX_LOW	"0123456789abcdef"
# define BASE_HEX_UPP	"0123456789ABCDEF"

int	ft_printf(const char *format, ...);
int	check_valided_specifier(char c, const char *format);
int	check_after_percent(char spec, va_list args);
int	print_char(char c);
int	print_point(unsigned long n);
int	print_str(char *str);
int	putnbr_base(long long n, char *base);
int	ft_strlen(char *str);

#endif
