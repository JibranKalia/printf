/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:42:59 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/10 13:07:54 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#define ISSIGN(a) (a == '+' || a == '-')
#define ISFLAG(a) (a == '+' || a == '-' || a == ' ' || a == '#' || a == '0')

/*
** Flag '0' is ignored if flag '-' is present.
** flag ' ' is ignored if '+' is present.
*/

int8_t	ft_printf_flags(t_arr *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	(void)ret;
	(void)clone;
	while (*fmt && ISFLAG(**fmt))
	{
		if (**fmt == '-')
			x->left = 1;
		else if (**fmt == '+')
			x->showsign = 1;
		else if (**fmt == ' ')
			x->space = 1;
		else if (**fmt == '#')
			x->alt = 1;
		else if (**fmt == '0')
			x->zero = 1;
		++*fmt;
		++x->extra.len;
	}
	x->zero = (x->left == 0) ? x->zero : 0;
	x->space = (x->showsign == 0) ? x->space : 0;
	x->pad = (x->zero) ? '0' : ' ';
	return (0);
}

/*
** If prec is set. '0' is ignored.
*/

int8_t	handle_width(t_printf *x, char c)
{
	char	*tmp;
	int		diff;
	size_t	index;

	if (x->is_prec == 1)
		x->pad = ' ';
	diff = x->width - x->extra.len;
	index = (x->left == 1) ? x->extra.len : 0;
	if (c == 'x' && x->left == 0)
		index = (ft_strstr(x->extra.ptr, "0x") != NULL) ? 2 : 0;
	if (x->pad == '0' && ISSIGN(x->extra.ptr[index]))
		++index;
	if (diff > 0)
	{
		CHK((tmp = ft_strnew(diff)) == 0, -1);
		ft_memset((void *)tmp, (int)x->pad, (size_t)diff);
		ft_arr_insertn(&x->extra, index, tmp, diff);
		free(tmp);
	}
	return (0);
}

/*
** Width takes the value of the last asterisk if there are multiple.
** If width is negative. Set '-' flag.
*/

int8_t	ft_printf_width(t_arr *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	size_t	res;

	res = 0;
	if (**fmt == '0')
		return (ft_printf_flags(ret, fmt, x, clone));
	while (ISDIGIT(**fmt))
	{
		res = res * 10 + (**fmt - '0');
		++*fmt;
	}
	x->width = res;
	while (**fmt == '*')
	{
		x->width = va_arg(clone, int);
		++*fmt;
	}
	if (x->width < 0)
	{
		x->width = -x->width;
		x->left = 1;
	}
	return (0);
}

int8_t	ft_printf_dot(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	int res;

	(void)ret;
	(void)clone;
	res = 0;
	++*fmt;
	x->is_prec = 1;
	if (**fmt == '*')
	{
		res = va_arg(clone, int);
		++*fmt;
	}
	else
	{
		while (ISDIGIT(**fmt))
		{
			res = res * 10 + (**fmt - '0');
			++*fmt;
		}
	}
	x->prec = res;
	return (0);
}

/*
**					1 hh;
**					2 h;
**					3 l;
**					4 ll;
**					5 j;
**					6 z;
**					7 L;
*/

char	g_length_spec[7] = {"hhlljzL"};
#define ISLENSPEC(a) (a == 'h' || a == 'l' || a == 'j' || a == 'z' || a == 'L')

int8_t	ft_printf_length(t_arr *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	int		index;

	(void)ret;
	(void)clone;
	while (ISLENSPEC(**fmt))
	{
		index = ft_strchr(g_length_spec, **fmt) - g_length_spec + 1;
		if (index == 1)
		{
			if (*(*fmt + 1) == 'h')
				++*fmt;
			else
				index = 2;
		}
		if (index == 3)
		{
			index = ((*(*fmt + 1)) == 'l') ? index + 1 : index;
		}
		x->len_mod = (index > x->len_mod) ? index : x->len_mod;
		++*fmt;
	}
	return (0);
}
