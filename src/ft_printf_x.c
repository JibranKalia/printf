/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 21:51:12 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/05 18:04:50 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

char	g_specx[17] = "0123456789abcdef";
char	g_specX[17] = "0123456789ABCDEF";

uintmax_t		ft_printf_uox_len(t_printf *x, va_list clone)
{
	if (x->len_mod == 0 || x->len_mod == 7)
		return (va_arg(clone, unsigned int));
	if (x->len_mod == 1)
		return ((unsigned char)va_arg(clone, unsigned int));
	if (x->len_mod == 2)
		return ((unsigned short)va_arg(clone, unsigned int));
	if (x->len_mod == 3)
		return (va_arg(clone, unsigned long));
	if (x->len_mod == 4)
		return (va_arg(clone, unsigned long long));
	if (x->len_mod == 5)
		return (va_arg(clone, uintmax_t));
	if (x->len_mod == 6)
		return (va_arg(clone, size_t));
	return (0);
}

static int8_t		ft_printf_x_dot(t_printf *x)
{
	char	*tmp;
	int		diff;

	if (x->is_prec == 0 && x->prec == 0)                 //Precision is set to zero
		return (0);
	if (x->is_prec == 0)                                  //If no precision is set. Default is 1
		x->prec = 1;
	if (x->prec < (int)x->extra.len)      //Nbr len is more than precession.
		return (0);
	diff = x->prec - x->extra.len;
	if (diff > 0)
	{
		CHK((tmp = ft_strnew(diff)) == 0, 0);
		ft_memset(tmp, '0', diff);
		ft_arr_insertn(&x->extra, 0, tmp, diff);
	}
	return (0);
}

static int8_t		ft_printf_hex(t_arr *ret, const char **fmt, t_printf *x, va_list clone, char *spec)
{
	uintmax_t	org;
	char		*nbr;

	CHK1((ft_arr_init(&x->extra, 1)) == -1, ft_arr_del(ret), -1);
	org = ft_printf_uox_len(x, clone);
	if (x->prec == 0 && x->is_prec == 1 && org == 0)               //if both the converted value is 0 and the precision is SET to 0 the conversion results in no characters.
		return (ft_printf_append(ret, fmt, x));
	nbr = ft_itoa_base(org, 16, spec);
	ft_arr_appendn(&x->extra, nbr, sizeof(char) * ft_strlen(nbr));
	ft_printf_x_dot(x);
	if (x->alt == 1)                                                   // "#' is alternative for Hex
		ft_arr_insertn(&x->extra, 0, "0x", 2);
	free(nbr);
	ft_handlewidth(x);
	return (ft_printf_append(ret, fmt, x));
}

int8_t				ft_printf_X(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	if (**fmt == 'X')
		return (ft_printf_hex(ret, fmt, x, clone, g_specX));
	return (ft_printf_hex(ret, fmt, x, clone, g_specx));
}
