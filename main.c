/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:55:18 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/30 17:17:01 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int		main(void)
{
	int		i;
	int		ret[2];

	i = 65;
	printf("Libc:\n");
	printf("++++++++++++++++++++++++++++++\n");
	ret[0] = printf("[Char: %10c %d]\n", i, i);
	printf("++++++++++++++++++++++++++++++\n");
	printf("ret[0] = %d\n", ret[0]);
	printf("\n\n");

	printf("Mine:\n");
	printf("%d\n", UINT8_MAX);
	printf("%lld\n", INTMAX_MAX);
	printf("++++++++++++++++++++++++++++++\n");
	ret[1] = ft_printf("[Char: %10c %d]\n", i, i);
	printf("++++++++++++++++++++++++++++++\n");
	printf("ret[1] = %d\n", ret[1]);
	return (0);
}
