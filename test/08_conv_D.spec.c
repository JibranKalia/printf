#include <test.h>

static void test_simple()
{
	assert_printf("%D", 0L);
	assert_printf("%D", 1L);
	assert_printf("%D", -1L);
	assert_printf("%D", 42L);
}

static void test_long_max()
{
	assert_printf("%D", LONG_MAX);
}

static void test_long_min()
{
	assert_printf("%D", LONG_MIN);
}

static void test_with_strings()
{
	assert_printf("Coucou les %D!", 42);
}

void	suite_08_conv_D()
{
	test_simple();
	test_long_max();
	test_long_min();
	test_with_strings();
}
