#include <stdio.h>

void	suite_73_precision_for_cC()
{
	printf("\nExpected:\n");
	printf("--------------\n");
	printf("%.c", 0);
	printf("%.5c", 0);
	printf("%.5c", 42);
	printf("%.C", 0);
	printf("%.5C", 0);
	printf("%.5C", 42);

	printf("\nMine:\n");
	printf("--------------\n");
	printf("%.c", 0);
	ft_printf("%.c", 0);
	ft_printf("%.5c", 0);
	ft_printf("%.5c", 42);
	ft_printf("%.C", 0);
	ft_printf("%.5C", 0);
	ft_printf("%.5C", 42);
}
