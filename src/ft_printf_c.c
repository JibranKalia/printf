/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:02:19 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/28 19:30:41 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void		ft_pad(char **src, t_printf *x, int len) //
{
	int		i;
	char	*tmp;

	tmp = *src;
	i = 0;
	while (i < len)
	{
		tmp[i] = x->pad;
		i++;
	}
}

int8_t		ft_printf_c(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	unsigned char	org;
	char			*tmp;
	wchar_t			tmp1;
	int				tmp2;
	int				index;

	CHK((tmp = ft_strnew(x->width)) == NULL, -1);
	(x->is_long == 1) ? (tmp1 = va_arg(clone, wchar_t)) : (tmp2 = va_arg(clone, int));
	org = (x->is_long == 1) ? (unsigned char)tmp1 : (unsigned char)tmp2;
	if (x->width != 0)
	{
		index = (x->left == 1) ? 0 : x->width - 1;
		ft_pad(&tmp, x, x->width);
		tmp[index] = org;
	}
	else
		tmp[0] = (char)org;
	ft_arr_append_str(&x->extra, tmp);
	free(tmp);
	return (ft_printf_append(ret, fmt, x));
}
