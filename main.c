/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:55:18 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/10 18:37:12 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include "includes/test.h"

int		main(void)
{
	int		x = 200;
	int		*y;
	int		p = 15;
	int		w = 30;
	int		ret1 = 0;
	int		ret2 = 0;
	char	*s1 = NULL;
	char	*s2 = NULL;

	ret1 = asprintf(&s1, "{%0.3S}", NULL);
	ret2 = ft_asprintf(&s2, "{%0.3S}", NULL);
//	ret1 = asprintf(&s1, "{%s}", "hello");
//	ret2 = ft_asprintf(&s2, "{%s}", "hello");
//	ret1 = asprintf(&s1, "%d%d%d%d%d%d%d", x, x, x, x, x, x, x, x, x);
//	ret2 = ft_asprintf(&s2, "%d%d%d%d%d%d%d", x, x, x, x, x, x, x, x, x);
	printsimple(s1, s2, ret1, ret2);
	

	/**
	//wchar_t *str = L"字Hello";
	char	*str1 = NULL;
	
	wchar_t Char =  L'字';
	setlocale(LC_CTYPE, "");

	char	*a;
	uintmax_t		b;
	a = ft_strnew(2);
	b = (uintmax_t)a;
	ret1 = asprintf(&s1, "%*.*p\n", w, p, a);
	ret2 = ft_asprintf(&s2, "%*.*p\n", w, p, a);

	//ret1 = asprintf(&s1, "[%0.*ls]\n", p, str);
	//ret2 = ft_asprintf(&s2,"[%0.*ls]\n", p, str);

	//printf("Hello %n", y);
	return (0);
	**/
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
