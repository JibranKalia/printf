/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:02:19 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/02 21:50:44 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int8_t		ft_printf_c(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	unsigned char	org;
	char			*tmp;
	wint_t			tmp1;
	int				tmp2;

	CHK(!(x->len_mod == 3 || x->len_mod == 0), -1); //No other lenght mods allowed with c
	CHK((tmp = ft_strnew(1)) == NULL, -1);
	CHK1((ft_arr_init(&x->extra, 5)) == -1, ft_arr_del(ret), -1);
	(x->len_mod == 3) ? (tmp1 = va_arg(clone, wint_t)) : (tmp2 = va_arg(clone, int));
	org = (x->len_mod == 3) ? (unsigned char)tmp1 : (unsigned char)tmp2;
	tmp[0] = org;
	ft_arr_append(&x->extra, tmp);
	free(tmp);
	ft_handlewidth(x);
	return (ft_printf_append(ret, fmt, x));
}

int8_t		ft_printf_C(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	x->len_mod = 3;                  //Treated as c with the l (ell) modifier.
	return (ft_printf_c(ret, fmt, x, clone));
}
