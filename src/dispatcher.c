/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:57:42 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/28 13:11:34 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int8_t		ft_printf_append(t_arr *ret, const char **fmt, t_printf *x)
{
	CHK2((ft_arr_append_arr(ret, &x->extra)) == -1, ft_arr_del(ret), ft_arr_del(&x->extra), -1);
	++*fmt;
	return (0);
}

int8_t		ft_printf_init(t_printf *x)
{
	ft_bzero(x, sizeof(t_printf));
	x->prec = -1; //Initial value of prec is -1
	x->pad = ' '; //Initial value of pad is ' '
	return (0);
}

int8_t		ft_printf_d(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	int			org;
	char		*nbr;

	org = va_arg(clone, int);
	nbr = ft_itoa(org);				//ITOA BASE
	ft_arr_append_str(&x->extra, nbr);
	free(nbr);
	return (ft_printf_append(ret, fmt, x));
}

static int choosetype(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	if (ft_strnstr(*fmt, "-", 1) != NULL)
		ft_printf_flags(fmt, x);
	if (ft_strnstr(*fmt, "+", 1) != NULL)
		ft_printf_flags(fmt, x);
	if (ft_strnstr(*fmt, " ", 1) != NULL)
		ft_printf_flags(fmt, x);
	if (ft_strnstr(*fmt, "#", 1) != NULL)
		ft_printf_flags(fmt, x);
	if (ft_strnstr(*fmt, "0", 1) != NULL)
		ft_printf_flags(fmt, x);
	if (ft_strnstr(*fmt, "1", 1) != NULL)
		ft_printf_width(fmt, x);
	if (ft_strnstr(*fmt, "2", 1) != NULL)
		ft_printf_width(fmt, x);
	if (ft_strnstr(*fmt, "3", 1) != NULL)
		ft_printf_width(fmt, x);
	if (ft_strnstr(*fmt, "4", 1) != NULL)
		ft_printf_width(fmt, x);
	if (ft_strnstr(*fmt, "5", 1) != NULL)
		ft_printf_width(fmt, x);
	if (ft_strnstr(*fmt, "6", 1) != NULL)
		ft_printf_width(fmt, x);
	if (ft_strnstr(*fmt, "7", 1) != NULL)
		ft_printf_width(fmt, x);
	if (ft_strnstr(*fmt, "8", 1) != NULL)
		ft_printf_width(fmt, x);
	if (ft_strnstr(*fmt, "9", 1) != NULL)
		ft_printf_width(fmt, x);
	if (ft_strnstr(*fmt, ".", 1) != NULL)
		ft_printf_dot(fmt, x);
	if (ft_strnstr(*fmt, "d", 1) != NULL)
		return (ft_printf_d(ret, fmt, x, clone));
	if (ft_strnstr(*fmt, "i", 1) != NULL)
		return (ft_printf_d(ret, fmt, x, clone));

	return (0); //Doesn't Match any of the types ????
}

int			dispatch(char **final, const char *fmt, va_list clone)
{
	size_t			i;
	t_arr			ret;
	t_printf		x;

	CHK((ft_arr_init(&ret, ft_strlen(fmt) + 10)) == -1, -1);
	CHK((ft_printf_init(&x)) == -1, -1);
	while (*fmt)
	{
		i = 0;
		while (fmt[i] != '%' && fmt[i] != 0)
			i++;
		ft_arr_append_strn(&ret, (char*)fmt, i);
		fmt += i;
		if (*fmt == '%')
		{
			if (*(++fmt) == 0) //Percentage is the last thing in the string. Also increments ahead of percentage.
				break;
			choosetype(&ret, &fmt, &x, clone); //Passing the address of fmt so that it can be incremented by other functions.
		}
	}
	//Copying the result of array onto output string.
	*final = ft_arrtostr(&ret);
	return (ret.len);
}

