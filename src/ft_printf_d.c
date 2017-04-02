/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:00:15 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/01 20:11:40 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>


static intmax_t		ft_printf_d_len(t_printf *x, va_list clone)
{
	if (x->len_mod == 0)
		return (va_arg(clone, int));
	if (x->len_mod == 1)
		return ((signed char)va_arg(clone, int));
	if (x->len_mod == 2)
		return ((short)va_arg(clone, int));
	if (x->len_mod == 3)
		return (va_arg(clone, long));
	if (x->len_mod == 4)
		return (va_arg(clone, long long));
	if (x->len_mod == 5)
		return (va_arg(clone, intmax_t));
	if (x->len_mod == 6)
		return (va_arg(clone, ssize_t));
	return (0);
}

static int8_t		ft_printf_d_dot(t_printf *x)
{
	char	*tmp;
	int		diff;

	if (x->is_prec == 0)
		return (0);
	if (x->prec == 0)                 //Not sure what to do in this case
		return (-1);
	if (x->prec < x->extra.len)      //Nbr len is more than precession.
		return (0);
	diff = x->prec - x->extra.len;
	if (diff > 0)
	{
		CHK((tmp = ft_strnew(diff)) == 0, 0);
		ft_memset(tmp, '0', diff);
		ft_arr_insertn(&x->extra, 0, tmp, diff);
	}
	return (0);
}

int8_t				ft_printf_d(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	intmax_t	org;
	char		*nbr;

	//if (x->len_mod == 7)                                           // L doesn't work with d.
	//	return (-1);
	if (x->is_prec == 1)                                          // for integer numbers it is ignored if the precision is explicitly specified.
		x->zero = 0;
	CHK1((ft_arr_init(&x->extra, 5)) == -1, ft_arr_del(ret), -1);
	org = ft_printf_d_len(x, clone);
	if (x->prec == 0 && x->is_prec == 1 && org == 0)               //if both the converted value and the precision are 0 the conversion results in no characters.
		return (ft_printf_append(ret, fmt, x));
	nbr = ft_itoa(org);
	ft_arr_appendn(&x->extra, nbr, ft_strlen(nbr));
	ft_printf_d_dot(x);
	if (org > 0 && x->showsign == 1)
		ft_arr_insert(&x->extra, 0, "+");
	free(nbr);
	ft_width(x);
	return (ft_printf_append(ret, fmt, x));
}
