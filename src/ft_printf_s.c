/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:53:24 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/04 17:55:48 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int8_t			ft_printf_s(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	char	*tmp;
	int		n;

	CHK1((ft_arr_init(&x->extra, 1)) == -1, ft_arr_del(ret), -1);
	tmp = va_arg(clone, char*);
	if (tmp == 0)
		tmp = "(null)";
	n = (x->is_prec == 1) ? ft_abs(x->prec) : ft_strlen(tmp);
	ft_arr_appendn(&x->extra, tmp, n * sizeof(char));
//	printf("Seg?\n");
	//printf("Before %d\n", &x->extra.len);
	ft_handlewidth(x);
	return (ft_printf_append(ret, fmt, x));
}

int8_t		ft_printf_S(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	x->len_mod = 3;                  //Treated as s with the l (ell) modifier.
	return (ft_printf_s(ret, fmt, x, clone));
}
