/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 13:53:24 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/05 16:23:56 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int8_t		ft_printf_wstr(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	wchar_t *tmp;

	tmp = va_arg(clone, wchar_t*);
}
int8_t			ft_printf_s(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	char	*tmp;
	char	*final;
	int		n;
	int		len;


	CHK1((ft_arr_init(&x->extra, 5)) == -1, ft_arr_del(ret), -1);
	tmp = va_arg(clone, char*);
	final = (tmp != NULL) ? ft_strdup(tmp) : ft_strdup("(null)");
	n = (x->is_prec == 1) ? MIN(x->prec, ft_strlen(final)) : ft_strlen(final);
	ft_arr_appendn(&x->extra, final, sizeof(char) * n);
	free(final);
	ft_handlewidth(x);
	return (ft_printf_append(ret, fmt, x));
}

int8_t		ft_printf_S(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	x->len_mod = 3;                  //Treated as s with the l (ell) modifier.
	return (ft_printf_s(ret, fmt, x, clone));
}
