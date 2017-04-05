/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unittest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 11:19:09 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/05 16:24:10 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libftprintf.h>
#include <test.h>

#define SUITEINFO(a) { \
	printf(ANSI_B_YELLOW"Test Suite %d"ANSI_RESET, a); \
	printf("\n"); \
	*i = 0; \
}

void	test_c(char *s1, char *s2, int ret1, int ret2, int *i)
{
//	SUITEINFO(16);
//	suite_16_conv_c(i);

	SUITEINFO(17);
	suite_17_conv_C(i);

	SUITEINFO(73);
	suite_73_precision_for_cC(i);
}

void	test_d(char *s1, char *s2, int ret1, int ret2, int *i)
{
	SUITEINFO(3);
	suite_03_conv_d(i);
}

void	test_x(char *s1, char *s2, int ret1, int ret2, int *i)
{
	SUITEINFO(14);
	suite_14_conv_x(i);

	SUITEINFO(15);
	suite_15_conv_X(i);
}

void	test_basic(char *s1, char *s2, int ret1, int ret2, int *i)
{
	SUITEINFO(0)
	suite_00_no_conv(i);
}

int		main(void)
{
	char	*s1;
	char	*s2;
	int		ret1;
	int		ret2;
	int		i;

//	test_basic(s1, s2, ret1, ret2, &i);
	test_c(s1, s2, ret1, ret2, &i);
//	test_d(s1, s2, ret1, ret2, &i);
//	test_x(s1, s2, ret1, ret2, &i);

}
