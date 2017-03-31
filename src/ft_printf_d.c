/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:00:15 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/30 17:16:13 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int8_t		ft_printf_d(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	int			org;
	char		*nbr;

	CHK1((ft_arr_init(&x->extra, 5)) == -1, ft_arr_del(ret), -1);
	org = va_arg(clone, int);
	nbr = ft_itoa(org);				//ITOA BASE
	ft_arr_appendn(&x->extra, nbr, ft_strlen(nbr));
	free(nbr);
	return (ft_printf_append(ret, fmt, x));
}
