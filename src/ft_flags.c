/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:42:59 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/02 21:10:22 by jkalia           ###   ########.fr       */
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
	printf("Width = %d\n", x->width);
	return (0);
}

int8_t	ft_printf_dot(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	size_t	res;

	res = 0;
	++*fmt;
	x->is_prec = 1;
	while (ISDIGIT(**fmt))
	{
		res = res * 10 + (**fmt - '0');
		++*fmt;
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
			{
				index = 1;
				++*fmt;
			}
			else
				index = 2;
		}
		if (index == 3)
		{
			if (*(*fmt + 1) == 'l')
			{
				++index;
				++*fmt;
			}
		}
		x->len_mod = (index > x->len_mod) ? index : x->len_mod;
		++*fmt;
		printf("Len Mod = %d\n", x->len_mod);
	}
	return (0);
}
