/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 12:55:58 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/04 11:57:47 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static int8_t		ft_printf_o_dot(t_printf *x)
{
	char	*tmp;
	int		diff;

	if (x->is_prec == 0 && x->prec == 0)                 //Precision is set to zero
		return (0);
	if (x->is_prec == 0)                                 //If no precision is set. Default is 1
		x->prec = 1;
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


int8_t		ft_printf_o(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	uintmax_t	org;
	char		*nbr;

	CHK1((ft_arr_init(&x->extra, 1)) == -1, ft_arr_del(ret), -1);
	org = ft_printf_uox_len(x, clone);
	if (x->prec == 0 && x->is_prec == 1 && org == 0 && x->alt == 0)               //if both the converted value and the precision are 0 the conversion results in no characters.
		return (ft_printf_append(ret, fmt, x));
	nbr = ft_itoa_base(org, 8, "01234567");
	ft_arr_appendn(&x->extra, nbr, sizeof(char) * ft_strlen(nbr));
	ft_printf_o_dot(x);
	if (org > 0 && x->alt == 1)
		ft_arr_insert(&x->extra, 0, "0");
	free(nbr);
	ft_handlewidth(x);
	return (ft_printf_append(ret, fmt, x));
}
