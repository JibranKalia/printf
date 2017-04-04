/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:55:18 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/04 13:03:51 by jkalia           ###   ########.fr       */
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
//	char	*S1;
//	char	*S2;
//	char	*S3;
	char	*tmp;

	wchar_t Char =  L'猫';

	setlocale(LC_CTYPE, "");
	ret1 = asprintf(&s1, "%C", L'ي');
	ret2 = ft_asprintf(&s2, "%C", L'ي');
	//ret1 = asprintf(&s1, "[%lc]\n", Char, Char, Char);
	//ret2 = ft_asprintf(&s2, "[%lc]\n", Char, Char, Char);

	//ret1 = asprintf(&s1, "Char: [%s] [%lc] [%C] (%x)\n", "猫", Char, Char, Char);
	//ret2 = ft_asprintf(&s2, "Char: [%s] [%lc] [%C] (%x)\n", "猫", Char, Char, Char);

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

	/**
	unsigned char str[3];
	str[0] = 231;
	str[1] = 140;
	str[2] = 171;
	int i = 0;
	S3 = ft_itoa_base(1610, 2, "01");;
	printf("S3 %s\n", S3);
	printf("C0 %s\n,", ft_itoa_base(192, 2, "01"));
	str[0] = (unsigned char)((Char>>6)|0xC0);
	S1 = ft_itoa_base(str[0], 2, "01");;
	S2 = ft_itoa_base(str[1], 2, "01");;
	printf("S1 %s\n", S1);
	printf("S2 %s \n", S2);
	str[1] = (unsigned char)((Char&0x3F)|0x80);
	
	while (i < 3)
	{
		write(1, &str[i], 1);
		i++;
	}
	**/
}


/**
KNOWN ISSUES:

	[%10.#15] no TYPE FIELD?




**/
