/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:07:51 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/24 14:38:47 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <unistd.h>

# include <stdio.h>  //Don't Forget to Remove!!!!

#  include "libft.h"

typedef struct		s_arr
{
	char			*ptr;
	size_t			len;
	size_t			cap;
}					t_arr;

int		ft_printf(const char *in, ...);
int		ft_vasprintf(char **ret, const char *fmt, va_list ap);

#endif
