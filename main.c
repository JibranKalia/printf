/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:55:18 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/02 21:24:41 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include "includes/test.h"

int		main(void)
{
	int		x = 65;
	int		ret1;
	int		ret2;
	char	*s1;
	char	*s2;
	char	*tmp;

	ret1 = asprintf(&s1, "[Char: %10.15d %.15Ld]\n", x, x);
	ret2 = ft_asprintf(&s2, "[Char: %10.15d %.15Ld]\n", x, x);

	if (strcmp(s1, s2) || ret1 != ret2)
	{
		printf(ANSI_RED"ERROR\n"ANSI_RESET);
		printf("Libc:\n");
		printf("++++++++++++++++++++++++++++++\n");
		printf("%s", s1);
		printf("++++++++++++++++++++++++++++++\n");
		printf("ret1 = %d\n", ret1);
		printf("\n\n");

		printf("Mine:\n");
		printf("++++++++++++++++++++++++++++++\n");
		printf("%s", s2);
		printf("++++++++++++++++++++++++++++++\n");
		printf("ret2 = %d\n", ret2);
	}
	else
		printf(ANSI_GREEN"!!!!WORKED!!!!\n"ANSI_RESET);

	return (0);

}
