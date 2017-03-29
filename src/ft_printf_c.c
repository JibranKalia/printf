/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:02:19 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/29 13:48:59 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int8_t	ft_pad(char **src, t_printf *x, int len) //
{
	int		i;
	char	*tmp;

	CHK(len == 0, -1);
	tmp = *src;
	i = 0;
	while (i < len)
	{
		tmp[i] = x->pad;
		i++;
	}
	return (0);
}

int8_t		ft_printf_c(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	unsigned char	org;
	char			*tmp;
	wint_t			tmp1;
	int				tmp2;
	int				index;

	CHK((tmp = ft_strnew(x->width)) == NULL, -1);
	(x->is_long == 1) ? (tmp1 = va_arg(clone, wint_t)) : (tmp2 = va_arg(clone, int));
	org = (x->is_long == 1) ? (unsigned char)tmp1 : (unsigned char)tmp2;
	if (x->width != 0)
	{
		index = (x->left == 1) ? 0 : x->width - 1;
		CHK(ft_pad(&tmp, x, x->width) == -1, -1);
		tmp[index] = org;
	}
	else
	{
		tmp[0] = org;
		tmp[1] = 0; //Make sure that str is correctly stopped is being copied over.
	}
	ft_arr_append_str(&x->extra, tmp);
	free(tmp);
	return (ft_printf_append(ret, fmt, x));
}
