/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:02:19 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/04 08:53:19 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int			ft_wchar_len(wint_t org)
{
	if (org <= 0X7f)
		return (1);
	else if (org <= 0x7ff)
		return (2);
	else if (org <= 0xfff)
		return (3);
	else if (org <= 0x10ffff)
		return (4);
}


int8_t		ft_printf_w(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	char	*tmp;
	int		len;
	wint_t	org;

	org = va_arg(clone, wint_t);
	len = ft_wchar_len(org);
	printf("Char len = %d\n", len);

	return (0);
}

int8_t		ft_printf_c(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	char			*tmp;

//	CHK(!(x->len_mod == 3 || x->len_mod == 0), -1); //No other lenght mods allowed with c
	if (x->len_mod == 3)
		return (ft_printf_w(ret, fmt, x, clone));
	CHK1((ft_arr_init(&x->extra, 1)) == -1, ft_arr_del(ret), -1);
	CHK((tmp = ft_strnew(1)) == NULL, -1);
	tmp[0] = (unsigned char)va_arg(clone, int);
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
