#include <stdio.h>
#include <libftprintf.h>
#include <test.h>

static void test_simple(PARAMS)
{

	++*i;
	ret1 = asprintf(&s1, "%x", 42);
	ret2 = ft_asprintf(&s2, "%x", 42);
	PRINT;
}

static void test_hex_with_strings(PARAMS)
{

	++*i;
	ret1 = asprintf(&s1, "before %x after", 42);
	ret2 = ft_asprintf(&s2, "before %x after", 42);
	PRINT;
}

static void test_many_hexs(PARAMS)
{

	++*i;
	ret1 = asprintf(&s1, "%x%x%x%x%x",
		1, 100, 999, 42, 999988888);
	ret2 = ft_asprintf(&s2, "%x%x%x%x%x",
		1, 100, 999, 42, 999988888);
	PRINT;
}

static void test_many_hexs_with_strings(PARAMS)
{

	++*i;
	ret1 = asprintf(&s1, "a%xb%xc%xd",
		0, 55555, 100000);
	ret2 = ft_asprintf(&s2, "a%xb%xc%xd",
		0, 55555, 100000);
	PRINT;
}

static void test_uint_max(PARAMS)
{

	++*i;
	ret1 = asprintf(&s1, "%x, %x", 0, UINT_MAX);
	ret2 = ft_asprintf(&s2, "%x, %x", 0, UINT_MAX);
	PRINT;
}

void	suite_14_conv_x(int *i)
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
