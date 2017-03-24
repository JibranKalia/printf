/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:55:18 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/24 00:15:58 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int		main(void)
{
	int		i;
	int		ret[2];

	i = 5;
	ret[0] = printf("Libc: %d\n", i);
	printf("ret[0] = %d\n", ret[0]);

	ret[1] = ft_printf("Mine %d aa", 5);
	printf("ret[1] = %d\n", ret[0]);
//	ft_printf("Mine : %d", i);
}
