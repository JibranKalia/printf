/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:55:18 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/13 13:23:03 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <stdio.h>
# define ANSI_RESET "\033[0m"
# define ANSI_BLUE "\033[34m"
# define ANSI_CYAN "\033[36m"
# define ANSI_RED "\033[31m"
# define ANSI_GREEN "\033[32m"
# define ANSI_B_BGREEN "\033[42;1m"
# define ANSI_B_YELLOW "\033[43m"

void	printsimple(char *s1, char *s2, int ret1, int ret2);

int		main(void)
{
	int		ret1;
	int		ret2;
	char	*s1;
	char	*s2;
	intmax_t	n = 999;

	ft_printf("%20.15d\n", 54321);


	/**
	char str1[100];
	char str2[100];
	ret1 = snprintf(str1, 14, "Hello world %s, you are number %d\n", "Giaco" ,5);
	ret2 = ft_snprintf(str2, 14, "Hello world %s, you are number %d\n", "Giaco" ,5);
	printf("Libc: %s\n", str1);
	printf("Mine: %s\n", str2);
	printf("Ret1: %d\n", ret1);
	printf("Ret2: %d\n", ret2);
	ret1 = sprintf(str1, "", "Giaco", 5);
	ret2 = ft_sprintf(str2, "", "Giaco", 5);
	printf("Libc: %s\n", str1);
	printf("Mine: %s\n", str2);
	printf("Ret1: %d\n", ret1);
	printf("Ret2: %d\n", ret2);
	ret1 = snprintf(str1, 1, "Hello world %s, you are number %d\n", "Giaco" , 5);
	ret2 = ft_snprintf(str2, 1, "Hello world %s, you are number %d\n", "Giaco" ,5);
	printf("Libc: %s\n", str1);
	printf("Mine: %s\n", str2);
	printf("Ret1: %d\n", ret1);
	printf("Ret2: %d\n", ret2);
	**/

/**

//	setlocale(LC_CTYPE, "");
//	wchar_t *str1 = L"字Hello";
//	char *str2 = "Hello";

	//ft_printf("Binary: %.5b\n", 0);
	ret1 = asprintf(&s1, "% .5d", 0);
	ret2 = ft_asprintf(&s2, "% .5d", 0);
	printsimple(s1, s2, ret1, ret2);
	
	ret1 = asprintf(&s1, "{%4.15d}", -42);
	ret2 = ft_asprintf(&s2, "{%4.15d}", -42);
	printsimple(s1, s2, ret1, ret2);

	//ft_printf("%{red}Here: %{eoc}");
	ret1 = asprintf(&s1, "{%4.15d}", 42);
	ret2 = ft_asprintf(&s2, "{%4.15d}", 42);
	printsimple(s1, s2, ret1, ret2);
**/
	/**
	ret1 = asprintf(&s1, "%#020.3x", 44);
	ret2 = ft_asprintf(&s2, "%#020.3x", 44);
	printsimple(s1, s2, ret1, ret2);

	ret1 = asprintf(&s1, "%#09x", INT8_MAX);
	ret2 = ft_asprintf(&s2, "%#09x", INT8_MAX);
	printsimple(s1, s2, ret1, ret2);

	ret1 = asprintf(&s1, "{%010.0x}", INT8_MAX);
	ret2 = ft_asprintf(&s2, "{%010.0x}", INT8_MAX);
	printsimple(s1, s2, ret1, ret2);

	ret1 = asprintf(&s1, "{%010.0x}", 0);
	ret2 = ft_asprintf(&s2, "{%010.0x}", 0);
	printsimple(s1, s2, ret1, ret2);
	**/
	return (0);
}




/**
	S Tests:
	ret1 = asprintf(&s1, "Mine = %s\n", str1);
	ret2 = ft_asprintf(&s2, "Mine = %s\n", str1);
	ret1 = asprintf(&s1, "Char: [%*.10s] [%*.5s]\n", w, str1, w, str, str1);
	ret2 = ft_asprintf(&s2, "Char: [%*.10s] [%*.5s]\n", w, str1, w, str, str1);
	ret1 = asprintf(&s1, "Char: [%s]\n", str1, str1, str1);
	ret2 = ft_asprintf(&s2, "Char: [%s]\n", str1, str1, str1);
	ret1 = asprintf(&s1, "Char: [%.3s] [%s] [%10.5s]\n", str1, str1, str1);
	ret2 = ft_asprintf(&s2, "Char: [%.3s] [%s] [%10.5s]\n", str1, str1, str1);
	ret1 = asprintf(&s1, "Char: [%s] [%*.*s] [%s] [%.5s]\n", str1, w, p, str1, str1, str1);
	ret2 = ft_asprintf(&s2, "Char: [%s] [%*.*s] [%s] [%.5s]\n", str1, w, p, str1, str1, str1);
	ret1 = asprintf(&s1, "Char: [%s] [%*.*s] [%11.1s] [%.1s]\n", str1, p, w, str1, str1, str1);
	ret2 = ft_asprintf(&s2, "Char: [%s] [%*.*s] [%11.1s] [%.1s]\n", str1, p, w, str1, str1, str1);
	ret1 = asprintf(&s1, "Char: [%*.*s]\n", w, p, str1, str1, str1);
	ret2 = ft_asprintf(&s2, "Char: [%*.*s]\n", w, p, str1, str1, str1);
**/






void	printsimple(char *s1, char *s2, int ret1, int ret2)
{
	if (s1 == NULL)
	{
		printf("S1 is NULL\n");
		return ;
	}

	if (s2 == NULL)
	{
		printf("S2 is NULL\n");
		return ;
	}

	if (strcmp(s1, s2) || ret1 != ret2)
	{
		printf(ANSI_RED"ERROR\n"ANSI_RESET);
		printf("Libc:\n");
		printf("++++++++++++++++++++++++++++++\n");
		printf("%s\n", s1);
		printf("++++++++++++++++++++++++++++++\n");
		printf("ret1 = %d\n", ret1);
		printf("\n\n");

		printf("Mine:\n");
		printf("++++++++++++++++++++++++++++++\n");
		printf("%s\n", s2);
		printf("++++++++++++++++++++++++++++++\n");
		printf("ret2 = %d\n", ret2);
	}
	else
	{
		printf(ANSI_GREEN"!!!!WORKED!!!!\n"ANSI_RESET);
		printf("%s\n", s2);
	}
}


/**
KNOWN ISSUES:

	[%10.#15] no TYPE FIELD?
	ft_printf("[%0 5.3s]\n", str1); //Padding is done with 0 eventhough precision is specified




**/
