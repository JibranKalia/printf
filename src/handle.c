/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:55:37 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/11 18:20:55 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int8_t	handle_space(t_printf *x, char c)
{
	(void)c;
	if (x->space == 1 && (x->width < x->prec))
		ft_arr_insertn(&x->extra, 0, " ", 1);
	return (0);
}

/*
** If prec is set. '0' is ignored.
*/

int8_t	handle_width(t_printf *x, char c)
{
	char	*tmp;
	int		diff;
	size_t	index;

	if (x->is_prec == 1 && c != 'c' && c != 's' && c != '%')
		x->pad = ' ';
	diff = x->width - x->extra.len;
	index = (x->left == 1) ? x->extra.len : 0;
	index = (x->pad == '0' && ISSIGN(x->extra.ptr[index])) ? index + 1 : index;
	if ((c == 'x' || c == 'p') && x->left == 0 && x->zero == 1)
		index = (ft_strstr(x->extra.ptr, "0x") != NULL) ? 2 : 0;
	if (x->space == 1 && x->zero == 1 && diff > 0)
	{
		ft_arr_insertn(&x->extra, 0, " ", 1);
		++index;
		--diff;
	}
	if (diff > 0)
	{
		CHK((tmp = ft_strnew(diff)) == 0, -1);
		ft_memset((void *)tmp, (int)x->pad, (size_t)diff);
		ft_arr_insertn(&x->extra, index, tmp, diff);
		free(tmp);
	}
	handle_space(x, c);
	return (0);
}

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

int8_t		ft_printf_f(t_arr *ret, const char **fmt,
		t_printf *x, va_list clone)
{
	(void)ret;
	(void)fmt;
	(void)x;
	(void)clone;
	return (0);
}
