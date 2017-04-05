/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:42:59 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/04 13:53:56 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int8_t	ft_printf_flags(t_arr *ret, const char **fmt, t_printf *x, va_list clone)			//What should this be returning?
{
	while (*fmt && (**fmt == '-' || **fmt == '+' || **fmt == ' ' || **fmt == '#' || **fmt == '0'))
	{
		if (**fmt == '-')
		{
			printf("Negative Flag\n");
			x->left = 1;
			x->zero = 0;	//flag '0' is ignored when flag '-' is present
		}
		else if (**fmt == '+')
		{
			printf("Positive Flag\n");
			x->showsign = 1;
			x->space = 0; //flag ' ' is ignored when flag '+' is present
		}
		else if (**fmt == ' ')
		{
			if (x->showsign == 0)  //flag ' ' is ignored when flag '+' is present
				x->space = 1;
			printf("Space Flag\n");
		}
		else if (**fmt == '#')
		{
			printf("Hash Flag\n");
			x->alt = 1;
		}
		else if (**fmt == '0')
		{
			printf("Zero Flag\n");
			if (x -> left == 0) /** flag '0' is ignored if - flag is present.**/
				x->zero = 1;
		}
		++*fmt;
		++x->extra.len;
	}
	x->pad = (x->zero) ? '0' : ' '; //Doing at the end after all the flags are handled
	return (0);
}

int8_t		ft_handlewidth(t_printf *x)
{
	char	*tmp;
	int		diff;
	size_t	index;

	if (x->is_prec == 1)                     //Make sure pad is space if precision is set. (This doesn't include default precision);
		x->pad = ' ';
	diff = x->width - x->extra.len;
	index = (x->left == 1) ? x->extra.len : 0;
	if (diff > 0)
	{
		CHK((tmp = ft_strnew(diff)) == 0, -1);
		ft_memset((void *)tmp, (int)x->pad, (size_t)diff);
		ft_arr_insertn(&x->extra, index, tmp, diff);
	}
	return (0);
}

int8_t				ft_printf_width(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	size_t	res;

	res = 0;
	if (**fmt == '0')
		return (ft_printf_flags(ret, fmt, x, clone)); //Starting with zero is a flag);
	while (ISDIGIT(**fmt))
	{
		res = res * 10 + (**fmt - '0');
		++*fmt;
	}
	x->width = res;
	//Width takes the value of the last asterisk if they are in the a row.
	while (**fmt == '*')
	{
		x->width = va_arg(clone, int);
		printf("Width = %d\n", x->width);
		++*fmt;
	}
	//If width is somehow negative. The - is treated as a flag.
	if (x->width < 0)
	{
			x->width = -x->width;
			x->left = 1;
	}
	printf("Width = %d\n", x->width);
	return (0);
}

int8_t	ft_printf_dot(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	int res;

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
	printf("Precision = %d\n", x->prec);
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

#define ISLENSPEC(a) ((a == 'h') || (a == 'l') || (a == 'j') || (a == 'z') || (a == 'L'))

int8_t	ft_printf_length(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	int		index;

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
			index = ((*(*fmt + 1)) == 'l') ? index + 1 : index;   //If it is 'll' index is incremented to 4
		}
		x->len_mod = (index > x->len_mod) ? index : x->len_mod;
		++*fmt;
		printf("Len Mod = %d\n", x->len_mod);
	}
	return (0);
}
