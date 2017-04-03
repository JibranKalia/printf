/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:55:18 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/03 13:43:04 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include "includes/test.h"

int		main(void)
{
	int		x = 15;
	int		p = 7;
	int		w = 4;
	int		ret1;
	int		ret2;
	char	*s1;
	char	*s2;
	char	*tmp;

	ret1 = asprintf(&s1, "[%*d] [%*.0d] [%0.*d] [%*.*d] [%**d] [%**.**d] [%10.15d] [%.15llhhd]\n", w, x, w, x, p, x, w, p, x, w, w + 1, x, w, w + 1, p, p + 1, x, x, x );
	ret2 = ft_asprintf(&s2, "[%*d] [%*.0d] [%0.*d] [%*.*d] [%**d] [%**.**d] [%10.15d] [%.15llhhd]\n", w, x, w, x, p, x, w, p, x, w, w + 1, x, w, w + 1, p, p + 1, x, x, x );

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
