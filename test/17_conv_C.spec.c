#include <libftprintf.h>
#include <stdio.h>

static void test_simple_char()
{
	// test->debug = 1;
	printf("\nExpected:\n");
	printf("%C", 'c');
	printf("\nMine:\n");
	ft_printf("%C", 'c');
}

static void test_two_chars()
{
	// debug_next_a	ssert();
	printf("\nExpected:\n");
	printf("%C%C", '4', '2');
	printf("\nMine:\n");
	ft_printf("%C%C", '4', '2');
}

static void test_ascii_printable_chars()
{
	// test->debug = 1;
	printf("\nExpected:\n");
	printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C \
%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C\
%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C",
' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
	printf("\nMine:\n");
	ft_printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C \
%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C\
%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C",
' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
};

static void test_chinese()
{
	// test->debug = 1;
	printf("\nExpected:\n");
	printf("%C", L'猫');
	printf("\nMine:\n");
	ft_printf("%C", L'猫');
}

static void test_greek()
{
	// test->debug = 1;
	printf("\nExpected:\n");
	printf("%C", L'δ');
	printf("\nMine:\n");
	ft_printf("%C", L'δ');
}


static void test_korean()
{
	// test->debug = 1;
	printf("\nExpected:\n");
	printf("%C", L'요');
	printf("\nMine:\n");
	ft_printf("%C", L'요');
}

static void test_japanese()
{
	// test->debug = 1;
	printf("\nExpected:\n");
	printf("%C", L'莨');
	printf("\nMine:\n");
	ft_printf("%C", L'莨');
}

static void test_arabic()
{
	// test->debug = 1;
	printf("\nExpected:\n");
	printf("%C", L'ي');
	printf("\nMine:\n");
	ft_printf("%C", L'ي');
}

static void test_nullChar()
{
	// test->debug = 1;
	printf("\nExpected:\n");
	printf("%C", 0);
	printf("\nMine:\n");
	ft_printf("%C", 0);
}

void	suite_17_conv_C()
{
	test_simple_char();
	test_two_chars();
	test_ascii_printable_chars();
	test_chinese();
	test_greek();
	test_korean();
	test_japanese();
	test_arabic();
	test_nullChar();
}
