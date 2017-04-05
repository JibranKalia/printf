/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:55:18 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/04 17:56:32 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include "includes/test.h"

int		main(void)
{
	int		x = 15;
	int		*y;
	int		p = -4;
	int		w = 10;
	int		ret1;
	int		ret2;
	char	*s1;
	char	*s2;
	
	char	str[10] = "Hello";
	char	*str1 = NULL;

	wchar_t Char =  L'字';
	setlocale(LC_CTYPE, "");


	printf("Libc: [%15.10s]\n", str1);
	ft_printf("Mine: [%15.10s]\n", str1);

	//printf("Hello %n", y);
	//printf("%d\n", *y);
	//ft_printf("Mine = %s\n", str1);
//	printf("Char: [%*.10s] [%*.5s]\n", w, str1, w, str, str1);
//	ft_printf("Char: [%*.10s] [%*.5s]\n", w, str1, w, str, str1);
	//printf("Char: [%*.*s]\n", p, w, str1, str1, str1);
	//ft_printf("Char: [%*.*s]\n", p, w, str1, str1, str1);
	//printf("Char: [%s] [%*.*s] [%50.1s] [%.1s]\n", str1, p, w, str1, str1, str1);
	//ft_printf("Char: [%s] [%*.*s] [%50.1s] [%.1s]\n", str1, p, w, str1, str1, str1);
	//ret1 = asprintf(&s1, "Char: [%s]\n", str1, str1, str1);
	//ret2 = ft_asprintf(&s1, "Char: [%s]\n", str1, str1, str1);
	//ret1 = asprintf(&s1, "Char: [%.3s] [%s] [%10.5s]\n", str1, str1, str1);
	//ret2 = ft_asprintf(&s1, "Char: [%.3s] [%s] [%10.5s]\n", str1, str1, str1);
	//ret1 = asprintf(&s1, "Char: [%s] [%l*.*s] [%s] [%.5s]\n", str1, p, str1, str1, str1);
	//ret2 = ft_asprintf(&s2, "Char: [%s] [%l*.*s] [%s] [%.5s]\n", str1, p, str1, str1, str1);
	//printsimple(s1, s2, ret1, ret2);
	return (0);
}











void	printsimple(char *s1, char *s2, int ret1, int ret2)
{
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




**/
