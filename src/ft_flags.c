/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:42:59 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/28 13:41:30 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int		ft_printf_flags(const char **fmt, t_printf *x)			//What should this be returning?
{
	while (*fmt && (**fmt == '-' || **fmt == '+' || **fmt == ' ' || **fmt == '#' || **fmt == '0'))
	{
		if (**fmt == '-')
		{
			printf("Negative Flag\n");
			x->left = 1;
			x->zero = 0;	//flag '0' is ignored when flag '-' is present
		}
		else if (**fmt == '+')
		{
			printf("Positive Flag\n");
			x->showsign = 1;
			x->space = 0; //flag ' ' is ignored when flag '+' is present
		}
		else if (**fmt == ' ')
		{
			printf("Space Flag\n");
			x->space = 1;
		}
		else if (**fmt == '#')
		{
			printf("Hash Flag\n");
			x->alt = 1;
		}
		else if (**fmt == '0')
		{
			printf("Zero Flag\n");
			x->zero = 1;
		}
		++*fmt;
		++x->extra.len;
	}
	x->pad = (x->zero) ? '0' : ' '; //Doing at the end after all the flags are handled
	return (x->extra.len);
}

int8_t	ft_printf_width(const char **fmt, t_printf *x)			//What should this be returning?
{
	size_t	i;
	char	tmp[20];

	i = 0;
	ft_bzero(tmp, 20);
	while (ISDIGIT(**fmt))
	{
		tmp[i] = **fmt;
		++i;
		++*fmt;
	}
	x->width = ft_atoi(tmp);
	return (0);
}

int8_t	ft_printf_dot(const char **fmt, t_printf *x)
{
	size_t	i;
	char	tmp[20];

	i = 0;
	if (**fmt != '.')
		return (-1);		//This error doesn't go anywhere
	else
		++*fmt;
	ft_bzero(tmp, 20);
	while (ISDIGIT(**fmt))
	{
		tmp[i] = **fmt;
		++i;
		++*fmt;
	}
	x->prec = ft_atoi(tmp);
	return (0);
}

int8_t	ft_printf_length(const char **fmt, t_printf *x)
{
	if (ft_strnstr(*fmt, "hh", 2) != NULL)
	{
		printf("hh Flag \n");
		x->is_char = 1;
	}
	if (ft_strnstr(*fmt, "h", 1) != NULL)
	{
		printf("h Flag\n");
		x->is_short = 1;
	}
	if (ft_strnstr(*fmt, "ll", 2) != NULL)
	{
		printf("ll Flag\n");
		x->is_long_double = 1;
	}
	if (ft_strnstr(*fmt, "L", 1) != NULL)
	{
		printf("L Flag\n");
		x->is_long_double = 1;
	}
	if (ft_strnstr(*fmt, "l", 1) != NULL)
	{
		printf("l Flag\n");
		x->is_long = 1;
	}
	if (ft_strnstr(*fmt, "j", 1) != NULL)
	{
		printf("j Flag\n");
		x->is_intmax = 1;
	}
	if (ft_strnstr(*fmt, "z", 1) != NULL)
	{
		printf("z Flag\n");
		x->is_sizet = 1;
	}
	return (0);
}
