#include <libftprintf.h>
#include <stdio.h>
#include <stdlib.h>
#include <test.h>

static void test_simple_char(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "%C", 'c');
	ret2 = ft_asprintf(&s2, "%C", 'c');
	PRINT;
}

static void test_two_chars(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "%C%C", '4', '2');
	ret2 = ft_asprintf(&s2, "%C%C", '4', '2');
	PRINT;
}

static void test_ascii_printable_chars(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C \
%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C\
%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C",
' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
	ret2 = ft_asprintf(&s2, "%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C \
%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C\
%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C",
' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
	PRINT;
};

static void test_chinese(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "%C", L'猫');
	ret2 = ft_asprintf(&s2, "%C", L'猫');
	PRINT;
}

static void test_greek(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "%C", L'δ');
	ret2 = ft_asprintf(&s2, "%C", L'δ');
	PRINT;
}


static void test_korean(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "%C", L'요');
	ret2 = ft_asprintf(&s2, "%C", L'요');
	PRINT;
}

static void test_japanese(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "%C", L'莨');
	ret2 = ft_asprintf(&s2, "%C", L'莨');
	PRINT;
}

static void test_arabic(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "%C", L'ي');
	ret2 = ft_asprintf(&s2, "%C", L'ي');
	PRINT;
}

static void test_nullChar(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "%C", 0);
	ret2 = ft_asprintf(&s2, "%C", 0);
	PRINT;
}

void	suite_17_conv_C(int *i)
{
	char *s1;
	char *s2;
	int ret1;
	int ret2;

	setlocale(LC_CTYPE, "");

	test_simple_char(s1, s2, ret1, ret2, i);
	test_two_chars(PARAMS2);
	test_ascii_printable_chars(PARAMS2);
	test_chinese(PARAMS2);
	test_greek(PARAMS2);
	test_korean(PARAMS2);
	test_japanese(PARAMS2);
	test_arabic(PARAMS2);
	test_nullChar(PARAMS2);
}
