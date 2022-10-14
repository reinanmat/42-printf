/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:50:10 by revieira          #+#    #+#             */
/*   Updated: 2022/10/14 17:28:52 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"

int	main(void)
{
	int	return_original;
	int	return_my_func;

	char	*p;

	p = (char *)malloc(sizeof(char));

	return_original = printf("%p\n", p);
	printf("Função orginal: %d\n", return_original);
	return_my_func = ft_printf("%p\n", p);
	printf("Minha função %d\n", return_my_func);
}
