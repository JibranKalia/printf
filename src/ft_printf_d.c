/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:00:15 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/01 12:33:55 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static intmax_t		ft_printf_d_len();

int8_t				ft_printf_d(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	intmax_t	org;
	char		*nbr;

	if (is_prec == 1)   // for integer numbers it is ignored if the precision is explicitly specified.
		x->zero = 0;
	CHK1((ft_arr_init(&x->extra, 5)) == -1, ft_arr_del(ret), -1);
	org = va_arg(clone, int);
	nbr = ft_itoa(org);				//ITOA BASE
	ft_arr_appendn(&x->extra, nbr, ft_strlen(nbr));
	free(nbr);
	ft_width(x);
	return (ft_printf_append(ret, fmt, x));
}
