/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:55:18 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/01 21:26:59 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int		main(void)
{
	int		i;
	int		x = 65;
	int		ret[2];
	char	*tmp;


	i = x;
	printf("Libc:\n");
	printf("++++++++++++++++++++++++++++++\n");
	ret[0] = printf("%s [Char: %10.15d %.15lld]\n"ANSI_RESET, ANSI_BLUE, i, i);
	printf("++++++++++++++++++++++++++++++\n");
	printf("ret[0] = %d\n", ret[0]);
	printf("\n\n");

	printf("Mine:\n");
	printf("++++++++++++++++++++++++++++++\n");
	ret[1] = ft_printf("ANSI_BLUE[Char: %10.15d %.15lld]\n"ANSI_RESET, i, i);
	printf("++++++++++++++++++++++++++++++\n");
	printf("ret[1] = %d\n", ret[1]);
	return (0);

}
