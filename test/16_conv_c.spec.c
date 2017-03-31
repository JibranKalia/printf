#include <stdio.h>
#include <libftprintf.h>
#include <test.h>

static void test_simple(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "Output = %c\n", 'a');
	ret2 = ft_asprintf(&s2, "Output = %c\n", 'a');
	PRINT;
}

static void test_simple_char(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "%c", 'c');
	ret2 = ft_asprintf(&s2, "%c", 'c');
	PRINT;
}

static void test_two_chars(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "%c%c", '4', '2');
	ret2 = ft_asprintf(&s2, "%c%c", '4', '2');
	PRINT;
}

static void test_ascii_printable_chars(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
	ret2 = ft_asprintf(&s2, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
	PRINT;
}

static void test_zero(PARAMS)
{
	++*i;
	ret1 = asprintf(&s1, "%c", 0);
	ret2 = ft_asprintf(&s2, "%c", 0);
	PRINT;
}	

void	suite_16_conv_c(int *i)
{
	char *s1;
	char *s2;
	int ret1;
	int ret2;

	test_simple_char(s1, s2, ret1, ret2, i);
	test_two_chars(s1, s2, ret1, ret2, i);
	test_ascii_printable_chars(s1, s2, ret1, ret2, i);
	test_zero(s1, s2, ret1, ret2, i);
}
