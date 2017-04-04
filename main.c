/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:55:18 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/03 18:02:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include "includes/test.h"

int		main(void)
{
	int		x = 15;
	int		p = -10;
	int		w = 5;
	int		ret1;
	int		ret2;
	char	*s1;
	char	*s2;
	char	*tmp;

	ret1 = asprintf(&s1, "[%.5d]\n", -5);
	ret2 = ft_asprintf(&s2, "[%.5d]\n", -5);
	//ret1 = asprintf(&s1, "[%.***d]\n", w, w + 5, w - 15, p, p + 5, p + 15,  x, x, x );
	//ret2 = ft_asprintf(&s2, "[%.***d]\n", w, w + 5, w - 15, p, p + 5, p + 15, x, x, x );
	//ret1 = asprintf(&s1, "[%***.**d]\n", w, w + 5, w + 10, p, p + 1, x, x, x );
	//ret2 = ft_asprintf(&s2, "[%***.**d]\n", w, w + 5, w + 10, p, p + 1, x, x, x );

//	ret1 = asprintf(&s1, "[Char: [%o] [%.0o] [%#.0o] [%#o] [%#o] [%10.15o] [%.15llhhO]\n", 0, 0, 0, 0, x, x, x);
//	ret2 = ft_asprintf(&s2, "[Char: [%o] [%.0o] [%#.0o] [%#o] [%#o] [%10.15o] [%.15llhhO]\n", 0, 0, 0, 0, x, x, x);

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

	return (0);

}


/**
KNOWN ISSUES:

	[%10.#15] no TYPE FIELD?




**/
