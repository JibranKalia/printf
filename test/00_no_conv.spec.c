#include <stdio.h>
#include <libftprintf.h>
#include <test.h>

static void simple_string(PARAMS)
{

	++*i;
	ret1 = asprintf(&s1, "This is a simple test.");
	ret2 = ft_asprintf(&s2, "This is a simple test.");
	PRINT;
}

static void simple_string_with_newline(PARAMS)
{

	++*i;
	ret1 = asprintf(&s1, "This is a simple test.\nSecond sentence.\n");
	ret2 = ft_asprintf(&s2, "This is a simple test.\nSecond sentence.\n");
	PRINT;
}

static void empty_string(PARAMS)
{

	++*i;
	printf(&s1, "");
	ft_printf(&s2, "");
	//PRINT;
}

static void simple_newline(PARAMS)
{

	++*i;
	ret1 = asprintf(&s1, "\n");
	ret2 = ft_asprintf(&s2, "\n");
	PRINT;
}

void	suite_00_no_conv(int *i)
{
	char *s1;
	char *s2;
	int ret1;
	int ret2;

	simple_string(PARAMS2);
	simple_string_with_newline(PARAMS2);
	empty_string(PARAMS2);
	simple_newline(PARAMS2);
}
