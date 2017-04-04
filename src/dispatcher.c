/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:57:42 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/04 13:17:50 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

#define LEN1 32
#define LEN2 2
#define TYPEFIELD 22

typedef int8_t FUNC(t_arr *, const char **, t_printf *, va_list);

static char g_tbl[LEN1][LEN2] =
{
	{"-"}, {"+"}, {" "}, {"#"}, {"0"}, {"*"},
	{"1"}, {"2"}, {"3"}, {"4"}, {"5"},
	{"6"}, {"7"}, {"8"}, {"9"}, {"."},
	{"hh"}, {"h"}, {"ll"}, {"L"}, {"l"},
	{"j"}, {"z"}, {"c"}, {"C"}, {"d"},
	{"D"}, {"i"}, {"x"}, {"X"}, {"o"},
	{"O"}, {"u"}};

FUNC  *g_func[LEN1] = {
	ft_printf_flags, ft_printf_flags, ft_printf_flags, ft_printf_flags, ft_printf_flags, ft_printf_width,
	ft_printf_width, ft_printf_width, ft_printf_width, ft_printf_width, ft_printf_width,
	ft_printf_width, ft_printf_width, ft_printf_width, ft_printf_width, ft_printf_dot,
	ft_printf_length, ft_printf_length, ft_printf_length, ft_printf_length, ft_printf_length,
	ft_printf_length, ft_printf_length, ft_printf_c, ft_printf_C, ft_printf_d,
	ft_printf_d, ft_printf_d, ft_printf_X, ft_printf_X, ft_printf_o,
	ft_printf_o, ft_printf_u};

static int8_t	check(const char **fmt, int i)
{
	if (ft_strnstr(*fmt, g_tbl[i], LEN2) != NULL)
		return (1);
	return (0);
}


static int	choosetype(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	int i;
	int r;

	i = -1;
	while (i < LEN1)
	{
		i++;
		if (**fmt == g_tbl[i][0])
		{
			if ((check(fmt, i)) == 1)
			{
				CHK(g_func[i](ret, fmt, x, clone) == -1, -1);
				if (i < TYPEFIELD)
					i = -1;                            //Reset counter to beginnning only if type field is not reached
			}
		}
	}
	return (0);
}

static int	choosetype1(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	if (ft_strnstr(*fmt, "-", 1) != NULL)
		ft_printf_flags(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, "+", 1) != NULL)
		ft_printf_flags(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, " ", 1) != NULL)
		ft_printf_flags(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, "#", 1) != NULL)
		ft_printf_flags(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, "0", 1) != NULL)
		ft_printf_flags(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, "1", 1) != NULL)
		ft_printf_width(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, "2", 1) != NULL)
		ft_printf_width(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, "3", 1) != NULL)
		ft_printf_width(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, "4", 1) != NULL)
		ft_printf_width(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, "5", 1) != NULL)
		ft_printf_width(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, "6", 1) != NULL)
		ft_printf_width(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, "7", 1) != NULL)
		ft_printf_width(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, "8", 1) != NULL)
		ft_printf_width(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, "9", 1) != NULL)
		ft_printf_width(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, ".", 1) != NULL)
		ft_printf_dot(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, "hh", 2) != NULL)
		ft_printf_length(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, "h", 1) != NULL)
		ft_printf_length(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, "ll", 2) != NULL)
		ft_printf_length(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, "L", 1) != NULL)
		ft_printf_length(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, "l", 1) != NULL)
		ft_printf_length(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, "j", 1) != NULL)
		ft_printf_length(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, "z", 1) != NULL)
		ft_printf_length(ret, fmt, x, clone);
	if (ft_strnstr(*fmt, "c", 1) != NULL)
		return(ft_printf_c(ret, fmt, x, clone));
	if (ft_strnstr(*fmt, "C", 1) != NULL)
	{
		x->len_mod = 3;
		return(ft_printf_c(ret, fmt, x, clone));
	}
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
		ft_arr_appendn(&ret, (char*)fmt, i);
		fmt += i;
		if (*fmt == '%')
		{
			if (*(++fmt) == 0) //Percentage is the last thing in the string. Also increments ahead of percentage.
				break;
			CHK1(choosetype(&ret, &fmt, &x, clone) == -1, ft_arr_del(&ret), -1); //Passing the address of fmt so that it can be incremented by other functions.
		}
		ft_arr_del(&x.extra);  //Shouldn't BZERO Better?
		CHK((ft_printf_init(&x)) == -1, -1); //Reset this array after every % is dealt with
	}
	//Copying the result of array onto output string.
	*final = ft_arrtostr(&ret);
	return (ret.len);
}
