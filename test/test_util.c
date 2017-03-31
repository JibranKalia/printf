/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:27:07 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/31 12:30:06 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test.h>
#include <libftprintf.h>

void	printout(char **src1, char **src2, int ret1, int ret2, int count)
{
	char *s1;
	char *s2;

	s1 = *src1;
	s2 = *src2;
	if (strcmp(s1, s2) != 0)
	{
		printf(ANSI_RED "Test %d Output Error\n" ANSI_RESET, count);
		printf("Expected: %s\n", s1);
		printf("Mine	: %s\n", s2);
	}
	else
		printf(ANSI_BLUE "Test %d Output PASS\n" ANSI_RESET, count);

	if (ret1 != ret2)
	{
		printf(ANSI_RED "Test %d Return Error\n" ANSI_RESET, count);
		printf("Expected: %d\n", ret1);
		printf("Mine	: %d\n", ret2);
	}
	else
		printf(ANSI_BLUE "Test %d Return PASS\n" ANSI_RESET, count);

	ft_bzero(s1, ft_strlen(s1));
	ft_bzero(s2, ft_strlen(s2));
}
