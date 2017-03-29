/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:00:15 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/28 18:56:34 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int8_t		ft_printf_d(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	int			org;
	char		*nbr;

	org = va_arg(clone, int);
	nbr = ft_itoa(org);				//ITOA BASE
	ft_arr_append_str(&x->extra, nbr);
	free(nbr);
	return (ft_printf_append(ret, fmt, x));
}
