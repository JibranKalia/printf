#include <stdio.h>
#include <libftprintf.h>
#include <test.h>

static void test_digit(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "%d", 42);
	ret2 = ft_asprintf(&s2, "%d", 42);
	PRINT;
}

static void test_digit_negative(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "%d", -42);
	ret2 = ft_asprintf(&s2, "%d", -42);
	PRINT;

}

static void test_digit_with_strings(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "before %d after", 42);
	ret2 = ft_asprintf(&s2, "before %d after", 42);
	PRINT;

}

static void test_many_digits(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "%d%d%d%d%d", 1, -2, 3, -4, 5);
	ret2 = ft_asprintf(&s2, "%d%d%d%d%d", 1, -2, 3, -4, 5);
	PRINT;

}

static void test_many_digits_width_strings(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "a%db%dc%dd", 1, -2, 3);
	ret2 = ft_asprintf(&s2, "a%db%dc%dd", 1, -2, 3);
	PRINT;

}

static void test_int_max(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "%d", INT_MAX);
	ret2 = ft_asprintf(&s2, "%d", INT_MAX);
	PRINT;

}

static void test_int_min(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "%d", INT_MIN);
	ret2 = ft_asprintf(&s2, "%d", INT_MIN);
	PRINT;
}

static void basic_conversion(PARAMS)
{
	++*i;
	intmax_t x;
	x = 10;
	while (x < UINTMAX_MAX && x != 0)
	{
		x *= 10;
		ret1 = asprintf(&s1, "%d %hhd %hd %ld %jd %zd", x, x, x, x, x, x);
		ret2 = ft_asprintf(&s2, "%d %hhd %hd %ld %jd %zd", x, x, x, x, x, x);
		if (strcmp(s1, s2) != 0)
			break;
		if (ret1 != ret2)
			break;
	}
		PRINT;
}

static void basic_conversion0(PARAMS)
{
	++*i;
	intmax_t x;
	x = 10;
	while (x < UINTMAX_MAX && x != 0)
	{
		x *= 10;
		ret1 = asprintf(&s1, "%hhhdldjdzd", x, x, x, x, x, x);
		ret2 = ft_asprintf(&s2, "%hhhdldjdzd", x, x, x, x, x, x);
		if (strcmp(s1, s2) != 0)
			break;
		if (ret1 != ret2)
			break;
	}
		PRINT;
}

static void basic_conversion01(PARAMS)
{
	++*i;
	intmax_t x;
	x = 10;
	while (x < UINTMAX_MAX && x != 0)
	{
		x *= 10;
		ret1 = asprintf(&s1, "%hhjhzdlddd", x, x, x, x, x, x);
		ret2 = ft_asprintf(&s2, "%hhjhzdlddd", x, x, x, x, x, x);
		if (strcmp(s1, s2) != 0)
			break;
		if (ret1 != ret2)
			break;
	}
		PRINT;
}

static void basic_conversion1(PARAMS)
{
	int x;

	x = 65;
	++*i;
	ret1 = asprintf(&s1, "[Char: %-010.5d %-10.15d %010.45d %10.45d]\n", x, x, x, x);
	ret2 = ft_asprintf(&s2, "[Char: %-010.5d %-10.15d %010.45d %10.45d]\n", x, x, x, x);
	PRINT;
}

static void prec_ngvnbr(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "[%.5d]\n", -5);
	ret2 = ft_asprintf(&s2, "[%.5d]\n", -5);
	PRINT;
}

static void basic_conversion2(PARAMS)
{
	int x;

	x = 65;
	++*i;
	ret1 = asprintf(&s1, "[Char: %d %.0d %10.15d %.15llhhd]\n", 0, 0, x, x);
	ret2 = ft_asprintf(&s2, "[Char: %d %.0d %10.15d %.15llhhd]\n", 0, 0, x, x);
	PRINT;
}

static void asterisk1(PARAMS)
{
	int		x = 15;
	int		p = 7;
	int		w = 4;

	++*i;
	ret1 = asprintf(&s1, "[%*d] [%*.0d] [%0.*d] [%*.*d] [%**d] [%10.15d] [%.15llhhd]\n", w, x, w, x, p, x, w, p, x, w, w + 1, x, x, x, x );
	ret2 = ft_asprintf(&s2, "[%*d] [%*.0d] [%0.*d] [%*.*d] [%**d] [%10.15d] [%.15llhhd]\n", w, x, w, x, p, x, w, p, x, w, w + 1, x, x, x, x );
	PRINT;
}

static void asterisk2(PARAMS)
{
	int		x = -15;
	int		p = -7;
	int		w = -4;

	++*i;
	ret1 = asprintf(&s1, "[%*d] [%*.0d] [%0.*d] [%*.*d] [%**d] [%10.15d] [%.15llhhd]\n", w, x, w, x, p, x, w, p, x, w, w + 1, x, x, x, x );
	ret2 = ft_asprintf(&s2, "[%*d] [%*.0d] [%0.*d] [%*.*d] [%**d] [%10.15d] [%.15llhhd]\n", w, x, w, x, p, x, w, p, x, w, w + 1, x, x, x, x );
	PRINT;
}

static void asterisk3(PARAMS)
{
	int		x = 15;
	int		p = 7;
	int		w = 4;

	++*i;
	ret1 = asprintf(&s1, "[%5*.**d] [%5*.4*d] [%5**.4d]\n", w, p, w + 1, x, w, p, x, w, p, x);
	ret2 = ft_asprintf(&s2, "[%5*.**d] [%5*.4*d] [%5**.4d]\n", w, p, w + 1, x, w, p, x, w, p, x);
	PRINT;
}

static void asterisk4(PARAMS)
{
	int		x = -15;
	int		p = -7;
	int		w = -4;

	++*i;
	ret1 = asprintf(&s1, "[%5*.**d] [%5*.4*d] [%5**.4d]\n", w, p, w + 1, x, w, p, x, w, p, x);
	ret2 = ft_asprintf(&s2, "[%5*.**d] [%5*.4*d] [%5**.4d]\n", w, p, w + 1, x, w, p, x, w, p, x);
	PRINT;
}

static void asterisk5(PARAMS)
{
	int		x = 15;
	int		p = -10;
	int		w = 5;

	++*i;
	ret1 = asprintf(&s1, "[%.***d]\n", w, w + 5, w - 15, p, p + 5, p + 15,  x, x, x );
	ret2 = ft_asprintf(&s2, "[%.***d]\n", w, w + 5, w - 15, p, p + 5, p + 15, x, x, x );
	PRINT;
}

static void asterisk6(PARAMS)
{
	int		x = 15;
	int		p = -10;
	int		w = 5;

	++*i;
	ret1 = asprintf(&s1, "[%***.**d]\n", w, w + 5, w + 10, p, p + 1, x, x, x );
	ret2 = ft_asprintf(&s2, "[%***.**d]\n", w, w + 5, w + 10, p, p + 1, x, x, x );
	PRINT;
}

void	suite_03_conv_d(int *i)
{
	char *s1;
	char *s2;
	int ret1;
	int ret2;

	test_digit(PARAMS2);
	test_digit_negative(PARAMS2);
	test_digit_with_strings(PARAMS2);
	test_many_digits(PARAMS2);
	test_many_digits_width_strings(PARAMS2);
	test_int_max(PARAMS2);
	test_int_min(PARAMS2);
	basic_conversion(PARAMS2);
	basic_conversion0(PARAMS2);
	basic_conversion01(PARAMS2);
	basic_conversion1(PARAMS2);
	basic_conversion2(PARAMS2);
	prec_ngvnbr(PARAMS2);
	asterisk1(PARAMS2);
	asterisk2(PARAMS2);
	asterisk3(PARAMS2);
	asterisk4(PARAMS2);
	asterisk5(PARAMS2);
	asterisk6(PARAMS2);
}
