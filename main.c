#include <stdio.h>
#include <stdlib.h>
#include "includes/ft_printf.h"

int	main(void)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char));
	printf("\nP\n");
	printf("\nreturn: %d\n", printf("%p", ptr));
	printf("\nreturn: %d\n", ft_printf("%p", ptr));
	printf("\nU\n");
	printf("\nreturn: %d\n", printf("%u", 0));
	printf("\nreturn: %d\n", ft_printf("%u", 0));
	printf("\nD\n");
	printf("\nreturn: %d\n", printf("%d", -999999));
	printf("\nreturn: %d\n", ft_printf("%d", -999999));
}
