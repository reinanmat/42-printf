/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:50:10 by revieira          #+#    #+#             */
/*   Updated: 2022/10/17 13:02:11 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"

int	main(void)
{
	int	return_original;
	int	return_my_func;

	printf("\nTest d\n");
	return_original = printf("%d\n", -1);
	printf("Função orginal: %d\n", return_original);
	return_my_func = ft_printf("%d\n", -1);
	printf("Minha função:   %d\n", return_my_func);
	
	printf("\nTest x\n");
	return_original = printf("%x\n", 1220111);
	printf("Função orginal: %d\n", return_original);
	return_my_func = ft_printf("%x\n", 1220111);
	printf("Minha função:   %d\n", return_my_func);
		
	printf("\nTest p\n");
	char *p;
	//p = (char *)malloc(sizeof(char));
	p = NULL;
	return_original = printf("%p\n", p);
	printf("Função original: %d\n", return_original);
	return_my_func = ft_printf("%p\n", p);
	printf("Minha função:    %d\n", return_my_func);



	return (0);
}
