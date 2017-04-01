/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:02:19 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/01 12:23:50 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int8_t		ft_width(t_printf *x)
{
	char	*tmp;
	int		diff;
	size_t	index;

	if (x->is_prec == 1) //Make sure pad is space if precision exists not zero.
		x->pad = ' ';
	diff = x->width - x->extra.len;
	index = (x->left == 1) ? x->extra.len : 0;
	if (diff > 0)
	{
		CHK((tmp = ft_strnew(diff)) == 0, -1);
		ft_memset((void *)tmp, (int)x->pad, (size_t)diff);
		ft_arr_insertn(&x->extra, index, tmp, diff);
	}
	return (0);
}

int8_t		ft_precision(t_printf *x);

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
	ft_width(x);
	return (ft_printf_append(ret, fmt, x));
}
