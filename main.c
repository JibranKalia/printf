/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:55:18 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/02 21:06:21 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int		main(void)
{
	int		x = 65;
	int		ret1;
	int		ret2;
	char	*tmp;


	printf("Libc:\n");
	printf("++++++++++++++++++++++++++++++\n");
	ret1 = printf("[Char: %10.15d %.15llhhd]\n", x, x);
	printf("++++++++++++++++++++++++++++++\n");
	printf("ret1 = %d\n", ret1);
	printf("\n\n");

	printf("Mine:\n");
	printf("++++++++++++++++++++++++++++++\n");
	ret2 = ft_printf("[Char: %10.15d %.15llhhd]\n", x, x);
	printf("++++++++++++++++++++++++++++++\n");
	printf("ret2 = %d\n", ret2);
	return (0);

}
