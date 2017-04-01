/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 11:59:53 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/01 10:44:05 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# define PARAMS char *s1, char *s2, int ret1, int ret2, int *i
# define PRINT printout(&s1, &s2, ret1, ret2, *i)

# define ANSI_RESET "\033[0m"
# define ANSI_BLUE "\033[34m"
# define ANSI_RED "\033[31m"
# define ANSI_B_BGREEN "\033[42;1m"
# define ANSI_B_YELLOW "\033[43m"

void	printout(char **src1, char **src2, int ret1, int ret2, int count);

void	suite_73_precision_for_cC(int *i);
void	suite_16_conv_c(int *i);
void	suite_17_conv_C(int *i);

#endif
