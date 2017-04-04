#include <project.h>

static void test_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("%o", 42);
}

static void test_octal_with_strings(t_test *test)
{
	// test->debug = 1;
	assert_printf("before %o after", 42);
}

static void test_many_octals(t_test *test)
{
	// test->debug = 1;
	assert_printf("%o%o%o%o%o",
		1, 100, 999, 42, 999988888);
}

static void test_many_octals_with_strings(t_test *test)
{
	// test->debug = 1;
	assert_printf("a%ob%oc%od",
		0, 55555, 100000);
}

	ret1 = asprintf(&s1, "[Char: [%o] [%.0o] [%#.0o] [%#o] [%#o] [%10.15o] [%.15llhhO]\n", 0, 0, 0, 0, x, x, x);
	ret2 = ft_asprintf(&s2, "[Char: [%o] [%.0o] [%#.0o] [%#o] [%#o] [%10.15o] [%.15llhhO]\n", 0, 0, 0, 0, x, x, x);

void	suite_10_conv_o(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_octal_with_strings);
	SUITE_ADD_TEST(suite, test_many_octals);
	SUITE_ADD_TEST(suite, test_many_octals_with_strings);
}
