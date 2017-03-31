/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unittest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 11:19:09 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/31 12:27:43 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libftprintf.h>
#include <test.h>


void	test_c(char *s1, char *s2, int ret1, int ret2, int *i)
{
	suite_16_conv_c(i);
}


int		main(void)
{
	char	*s1;
	char	*s2;
	int		ret1;
	int		ret2;
	int		i;

	i = 0;
	test_c(s1, s2, ret1, ret2, &i);
}
