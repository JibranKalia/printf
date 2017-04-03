/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:07:51 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/02 18:35:31 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <wchar.h> //needed for wchar_t in %c
# include <stdio.h>  //Don't Forget to Remove!!!!

# include "libft.h"
# include "test.h"

typedef struct		s_arr
{
	char			*ptr;
	size_t			len;
	size_t			cap;
}					t_arr;

/*
**					1 hh;
**					2 h;
**					3 l;
**					4 ll;
**					5 j;
**					6 z;
**					7 L;
*/

typedef struct		s_printf
{
	t_arr			extra;
	unsigned int 	is_prec:1;       /* Whether precision is a factor or not. */
	unsigned int 	prec;            /* Precision. Default is -1??? */
	unsigned int 	width;           /* Width. Default is 0 */
	wchar_t 		spec;            /* Format letter.  */ //NOT SURE IF KEEPING
	unsigned int 	left:1;          /* - flag.  */
	unsigned int 	showsign:1;      /* + flag.  */
	unsigned int 	space:1;         /* Space flag.  */
	unsigned int 	zero:1;          /* Zero flag.  */
	unsigned int 	alt:1;           /* # flag.  */
	uint8_t			len_mod;         /* Change below */
	char	 		pad;             /* Padding character.  The value is '0' if the ‘0’ flag was specified, and ' ' otherwise.*/

}					t_printf;

typedef int8_t FUNC(t_arr *, const char **, t_printf *, va_list);

int					ft_printf(const char *in, ...);
int					ft_vasprintf(char **ret, const char *fmt, va_list ap);
int					ft_asprintf(char **ret, const char *fmt, ...);


/*
** Arrays
*/

int8_t				ft_arr_init(t_arr *src, size_t cap);
int8_t				ft_arr_append(t_arr *dst, const void *src);
int8_t				ft_arr_appendn(t_arr *dst, const void *src, size_t n);
int8_t				ft_arr_append_arr(t_arr *dst, t_arr *src);
int8_t				ft_arr_resize(t_arr *src, size_t sze);
int8_t				ft_arr_insert(t_arr *dst, size_t index, const void *src);
int8_t				ft_arr_insertn(t_arr *dst, size_t index, const void *src, size_t src_len);
void				ft_arr_del(t_arr *src);
char				*ft_arrtostr(t_arr *src);

/*
** Flags
*/

# define MASK 0x80
# define NGV 0x1
# define PSV 0x2
# define SPC 0x4
# define HSH 0x8
# define ZRO 0x10

int					ft_printf_flags(const char **fmt, t_printf *x);

/*
** Width
*/

# define ISWIDTH(a) (a > 48 && a <= 57)
//int8_t			ft_printf_width(const char **fmt, t_printf *x)
int8_t				ft_printf_width(t_arr *ret, const char **fmt, t_printf *x, va_list clone);

/*
** Precision
*/
int8_t				ft_printf_dot(const char **fmt, t_printf *x);

/*
** Length
*/

int8_t				ft_printf_length(const char **fmt, t_printf *x);

/*
** Functions
*/

int8_t				ft_printf_d(t_arr *ret, const char **fmt, t_printf *x, va_list clone);
int8_t				ft_printf_c(t_arr *ret, const char **fmt, t_printf *x, va_list clone);
int8_t				ft_printf_append(t_arr *ret, const char **fmt, t_printf *x);
int					dispatch(char **final, const char *fmt, va_list clone);

#endif
