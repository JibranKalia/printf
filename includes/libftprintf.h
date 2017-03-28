/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:07:51 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/27 20:46:28 by jkalia           ###   ########.fr       */
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

# include "libft.h"

typedef struct		s_arr
{
	char			*ptr;
	size_t			len;
	size_t			cap;
}					t_arr;

typedef struct		s_printf
{
	t_arr			extra;
	u_int8_t		flags;
	int				prec; //This is the precision specified. The value is -1 if no precision was specified.
	int				width; //This is the minimum field width specified. The value is 0 if no width was specified.

	//Padding. Conversion Specifier
}					t_printf;

int		ft_printf(const char *in, ...);
int		ft_vasprintf(char **ret, const char *fmt, va_list ap);
int		dispatch(char **final, const char *fmt, va_list clone);


/*
** Arrays
*/

int8_t	ft_arr_init(t_arr *src, size_t cap);
int8_t	ft_arr_append_str(t_arr *dst, char *src);
int8_t	ft_arr_append_strn(t_arr *dst, char *src, size_t n);
int8_t	ft_arr_append_arr(t_arr *dst, t_arr *src);
char	*ft_arrtostr(t_arr *src);
void	ft_arr_del(t_arr *src);

/*
** Flags
*/

# define MASK 0x80
# define NGV 0x1
# define PSV 0x2
# define SPC 0x4
# define HSH 0x8
# define ZRO 0x10

int		ft_printf_flags(const char **fmt, t_printf *x);

#endif
