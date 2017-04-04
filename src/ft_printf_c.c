/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:02:19 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/04 13:13:36 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int			ft_wchar_len(wint_t org)
{
	if (org <= 0X7f)
		return (1);
	if (org <= 0x7ff)
	{
		printf("Wchar Len = 2\n");
		return (2);
	}
	if (org <= 0xffff)
	{
		printf("Wchar Len = 3\n");
		return (3);
	}
	if (org <= 0x10ffff)
	{
		printf("Wchar Len = 4\n");
		return (4);
	}
	return (-1);
}

int8_t		ft_printf_w(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	int				len;
	unsigned char	tmp[5];
	wint_t			org;

	org = va_arg(clone, wint_t);
	CHK((len = ft_wchar_len(org)) == -1, -1);
	
	if (len == 1)
		tmp[0] = org;
	else if (len == 2)
	{
		tmp[0] = ((org >> 6) | 0xC0);
		tmp[1] = ((org & 0x3f) | 0x80);
	}
	else if (len == 3)
	{
		tmp[0] = ((org >> 12) | 0xE0);
		tmp[1] = (((org >> 6) & 0x3f) | 0x80);
		tmp[2] = ((org & 0x3f) | 0x80);
	}
	else if (len == 4)
	{
		tmp[0] = ((org >> 18) | 0xf0);
		tmp[1] = (((org >> 12) & 0x3f) | 0x80);
		tmp[2] = (((org >> 6) & 0x3f) | 0x80);
		tmp[3] = ((org & 0x3f) | 0x80);
	}
	ft_arr_appendn(&x->extra, tmp, sizeof(char) * len);
	ft_handlewidth(x);
	return (ft_printf_append(ret, fmt, x));
}

int8_t		ft_printf_c(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	unsigned char	tmp[1];

	CHK1((ft_arr_init(&x->extra, 5)) == -1, ft_arr_del(ret), -1);
	if (x->len_mod == 3)
		return (ft_printf_w(ret, fmt, x, clone));
	tmp[0] = (unsigned char)va_arg(clone, int);
	ft_arr_append(&x->extra, tmp);
	ft_handlewidth(x);
	return (ft_printf_append(ret, fmt, x));
}

int8_t		ft_printf_C(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	x->len_mod = 3;                  //Treated as c with the l (ell) modifier.
	return (ft_printf_c(ret, fmt, x, clone));
}
