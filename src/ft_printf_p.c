/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:12:21 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/05 20:54:17 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int8_t			ft_printf_percent(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	CHK1((ft_arr_init(&x->extra, 1)) == -1, ft_arr_del(ret), -1);
	ft_arr_insertn(&x->extra, 0, "%", 1);
	ft_handlewidth(x);
	return (ft_printf_append(ret, fmt, x));
}

int8_t			ft_printf_p(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	uintmax_t	org;
	char		*nbr;

	CHK1((ft_arr_init(&x->extra, 1)) == -1, ft_arr_del(ret), -1);
	org = (uintmax_t)va_arg(clone, void*);
	nbr = ft_itoa_base(org, 16, "0123456789abcdef");
	ft_arr_appendn(&x->extra, nbr, sizeof(char) * ft_strlen(nbr));
	handle_prec(x, org);
	ft_arr_insertn(&x->extra, 0, "0x", 2);
	free(nbr);
	ft_handlewidth(x);
	return (ft_printf_append(ret, fmt, x));
}
