#include <stdio.h>
#include <test.h>

void	suite_73_precision_for_cC(int *i)
{
	char *s1;
	char *s2;
	int ret1;
	int ret2;

	++*i;
	asprintf(&s1, "%.c %.5c %.c %.5c", 0, 0, 42, 42);
	ft_asprintf(&s2, "%.c %.5c %.c %.5c", 0, 0, 42, 42);
	PRINT;

	++*i;
	asprintf(&s1, "%.C %.5C %.C %.5C", 0, 0, 42, 42);
	ft_asprintf(&s2, "%.C %.5C %.C %.5C", 0, 0, 42, 42);
	PRINT;

	/*
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
	**/
}
