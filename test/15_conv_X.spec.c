#include <stdio.h>
#include <libftprintf.h>
#include <test.h>

static void test_simple(PARAMS)
{

	++*i;
	ret1 = asprintf(&s1, "%X", 42);
	ret2 = ft_asprintf(&s2, "%X", 42);
	PRINT;
}

static void test_hex_with_strings(PARAMS)
{

	++*i;
	ret1 = asprintf(&s1, "before %X after", 42);
	ret2 = ft_asprintf(&s2, "before %X after", 42);
	PRINT;
}

static void test_many_hexs(PARAMS)
{

	++*i;
	ret1 = asprintf(&s1, "%X%X%X%X%X",
		1, 100, 999, 42, 999988888);
	ret2 = ft_asprintf(&s2, "%X%X%X%X%X",
		1, 100, 999, 42, 999988888);
	PRINT;
}

static void test_many_hexs_with_strings(PARAMS)
{

	++*i;
	ret1 = asprintf(&s1, "a%Xb%Xc%Xd",
		0, 55555, 100000);
	ret2 = ft_asprintf(&s2, "a%Xb%Xc%Xd",
		0, 55555, 100000);
	PRINT;
}

static void test_uint_max(PARAMS)
{

	++*i;
	ret1 = asprintf(&s1, "%X, %X", 0, UINT_MAX);
	ret2 = ft_asprintf(&s2, "%X, %X", 0, UINT_MAX);
	PRINT;
}

void	suite_15_conv_X(int *i)
{
	char *s1;
	char *s2;
	int ret1;
	int ret2;

	test_simple(PARAMS2);
	test_hex_with_strings(PARAMS2);
	test_many_hexs(PARAMS2);
	test_many_hexs_with_strings(PARAMS2);
	test_uint_max(PARAMS2);
}
