/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:00:15 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/10 13:34:57 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

intmax_t	ft_printf_d_len(t_printf *x, va_list clone)
{
	if (x->len_mod == 0 || x->len_mod == 7)
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

/*
** If precision is not set function returns.
** If nbr is negative the minus sign doesn't count towards precision.
** If both value and precision are 0 no characters printed.
** If the number is negative the extra zero padding has to be after sign.
*/

int8_t		handle_prec(t_printf *x, intmax_t org)
{
	char	*tmp;
	int		diff;
	int		index;

	if (x->is_prec == 0 && x->prec == 0)
		return (0);
	if (x->prec < (int)x->extra.len)
		return (0);
	diff = (org >= 0) ? x->prec - x->extra.len : x->prec - x->extra.len + 1;
	index = (org >= 0) ? 0 : 1;
	if (diff > 0)
	{
		CHK((tmp = ft_strnew(diff)) == 0, 0);
		ft_memset(tmp, '0', diff);
		ft_arr_insertn(&x->extra, index, tmp, diff);
	}
	return (0);
}

int8_t		ft_printf_percent(t_arr *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	CHK1((ft_arr_init(&x->extra, 1)) == -1, ft_arr_del(ret), -1);
	ft_arr_insertn(&x->extra, 0, "%", 1);
	handle_width(x, '%');
	return (ft_printf_append(ret, fmt, x));
}

int8_t		ft_printf_p(t_arr *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	uintmax_t	org;
	char		*nbr;

	CHK1((ft_arr_init(&x->extra, 5)) == -1, ft_arr_del(ret), -1);
	ft_arr_insertn(&x->extra, 0, "0x", 2);
	org = (uintmax_t)va_arg(clone, void*);
	if (org == 0)
	{
		handle_width(x, 'p');
		return (ft_printf_append(ret, fmt, x));
	}
	nbr = ft_itoa_base(org, 16, "0123456789abcdef");
	ft_arr_appendn(&x->extra, nbr, sizeof(char) * ft_strlen(nbr));
	handle_prec(x, org);
	free(nbr);
	handle_width(x, 'p');
	return (ft_printf_append(ret, fmt, x));
}

/*
** This function handles 'D' 'd' 'i'. 'D' equates to 'ld'.
** For integer numbers '0' flag is ignored if precision is defined.
** If both value and precision are 0 no characters printed.
*/

int8_t		ft_printf_d(t_arr *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	intmax_t	org;
	char		*nbr;

	if (**fmt == 'D' && x->len_mod <= 3)
		x->len_mod = 3;
	if (x->is_prec == 1)
		x->zero = 0;
	CHK1((ft_arr_init(&x->extra, 5)) == -1, ft_arr_del(ret), -1);
	org = ft_printf_d_len(x, clone);
	if (x->prec == 0 && x->is_prec == 1 && org == 0)
	{
		handle_width(x, 'd');
		return (ft_printf_append(ret, fmt, x));
	}
	nbr = ft_itoa(org);
	ft_arr_appendn(&x->extra, nbr, sizeof(char) * ft_strlen(nbr));
	handle_prec(x, org);
	if (org >= 0 && x->showsign == 1)
		ft_arr_insertn(&x->extra, 0, "+", 1);
	if (org >= 0 && x->space == 1 && x->width == 0)
		ft_arr_insertn(&x->extra, 0, " ", 1);
	free(nbr);
	handle_width(x, 'd');
	return (ft_printf_append(ret, fmt, x));
}
