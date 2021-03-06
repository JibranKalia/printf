/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:07:51 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/13 13:54:34 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <wchar.h>
# include "libft.h"
# include "array.h"
# define ISWIDTH(a) (a > 48 && a <= 57)
# define ISSIGN(a) (a == '+' || a == '-')
# define ISFLAG(a) (a == '+' || a == '-' || a == ' ' || a == '#' || a == '0')

int		ft_printf(const char *in, ...);
int		ft_dprintf(int fd, const char *in, ...);
int		ft_sprintf(char *ret, const char *fmt, ...);
int		ft_snprintf(char *ret, size_t size, const char *fmt, ...);
int		ft_asprintf(char **ret, const char *fmt, ...);
int		ft_vprintf(const char *fmt, va_list ap);
int		ft_vsprintf(char *ret, const char *fmt, va_list ap);
int		ft_vdprintf(int fd, const char *fmt, va_list ap);
int		ft_vasprintf(char **ret, const char *fmt, va_list ap);

/*
** Flags
*/

int8_t	ft_printf_flags(t_arr *r, const char **f, t_printf *x, va_list clone);

/*
** Width
*/

int8_t	ft_printf_width(t_arr *r, const char **f, t_printf *x, va_list clone);
int8_t	handle_width(t_printf *x, char c);

/*
** Precision
*/

int8_t	ft_printf_dot(t_arr *ret, const char **fmt, t_printf *x, va_list clone);
int8_t	handle_prec(t_printf *x, intmax_t org);

/*
** Length
*/

int8_t	ft_printf_length(t_arr *r, const char **f, t_printf *x, va_list clone);

/*
** Functions
*/

int		dispatch(char **final, const char *fmt, va_list clone);
int8_t	ft_printf_init(t_printf *x);
int8_t	ft_printf_append(t_arr *ret, const char **fmt, t_printf *x);
int8_t	ft_printf_c(t_arr *ret, const char **fmt, t_printf *x, va_list clone);
int8_t	ft_printf_b(t_arr *ret, const char **fmt, t_printf *x, va_list clone);
int8_t	ft_printf_d(t_arr *ret, const char **fmt, t_printf *x, va_list clone);
int8_t	ft_printf_percent(t_arr *r, const char **f, t_printf *x, va_list cln);
int8_t	ft_printf_p(t_arr *ret, const char **fmt, t_printf *x, va_list clone);
int8_t	ft_printf_s(t_arr *ret, const char **fmt, t_printf *x, va_list clone);
int8_t	ft_printf_o(t_arr *ret, const char **fmt, t_printf *x, va_list clone);
int8_t	ft_printf_u(t_arr *ret, const char **fmt, t_printf *x, va_list clone);
int8_t	ft_printf_n(t_arr *ret, const char **fmt, t_printf *x, va_list clone);
int8_t	ft_printf_x(t_arr *ret, const char **fmt, t_printf *x, va_list clone);
int8_t	ft_printf_f(t_arr *ret, const char **fmt, t_printf *x, va_list clone);
int8_t	ft_printf_color(t_arr *r, const char **f, t_printf *x, va_list clone);
#endif
