/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 21:51:12 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/05 21:13:07 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static uintmax_t	ft_printf_uox_len(t_printf *x, va_list clone)
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

int8_t		ft_printf_o(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	uintmax_t	org;
	char		*nbr;

	CHK1((ft_arr_init(&x->extra, 1)) == -1, ft_arr_del(ret), -1);
	org = ft_printf_uox_len(x, clone);
	if (x->prec == 0 && x->is_prec == 1 && org == 0 && x->alt == 0)               //if both the converted value and the precision are 0 the conversion results in no characters.
		return (ft_printf_append(ret, fmt, x));
	nbr = ft_itoa_base(org, 8, "01234567");
	ft_arr_appendn(&x->extra, nbr, sizeof(char) * ft_strlen(nbr));
	handle_prec(x, org);
	if (org > 0 && x->alt == 1)
		ft_arr_insert(&x->extra, 0, "0");
	free(nbr);
	ft_handlewidth(x);
	return (ft_printf_append(ret, fmt, x));
}

int8_t		ft_printf_u(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	uintmax_t	org;
	char		*nbr;

	CHK1((ft_arr_init(&x->extra, 1)) == -1, ft_arr_del(ret), -1);
	org = ft_printf_uox_len(x, clone);
	if (x->prec == 0 && x->is_prec == 1 && org == 0 && x->alt == 0)               //if both the converted value and the precision are 0 the conversion results in no characters.
		return (ft_printf_append(ret, fmt, x));
	nbr = ft_itoa_base(org, 10, "0123456789");
	ft_arr_appendn(&x->extra, nbr, sizeof(char) * ft_strlen(nbr));
	handle_prec(x, org);
//	if (org > 0 && x->alt == 1)
//		ft_arr_insert(&x->extra, 0, "0");
	free(nbr);
	ft_handlewidth(x);
	return (ft_printf_append(ret, fmt, x));
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
	handle_prec(x, org);
	if (x->alt == 1)                                                   // "#' is alternative for Hex
		ft_arr_insertn(&x->extra, 0, "0x", 2);
	free(nbr);
	ft_handlewidth(x);
	return (ft_printf_append(ret, fmt, x));
}

int8_t				ft_printf_X(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	if (**fmt == 'X')
		return (ft_printf_hex(ret, fmt, x, clone, "0123456789ABCDEF"));
	return (ft_printf_hex(ret, fmt, x, clone, "0123456789abcdef"));
}
