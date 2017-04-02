/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:42:59 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/01 19:50:37 by jkalia           ###   ########.fr       */
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
			if (x->showsign == 0)  //flag ' ' is ignored when flag '+' is present
				x->space = 1;
			printf("Space Flag\n");
		}
		else if (**fmt == '#')
		{
			printf("Hash Flag\n");
			x->alt = 1;
		}
		else if (**fmt == '0')
		{
			printf("Zero Flag\n");
			if (x -> left == 0) /** flag '0' is ignored if - flag is present.**/
				x->zero = 1;
		}
		++*fmt;
		++x->extra.len;
	}
	x->pad = (x->zero) ? '0' : ' '; //Doing at the end after all the flags are handled
	return (0);
}

int8_t	ft_printf_width(const char **fmt, t_printf *x)			//What should this be returning?
{
	size_t	res;

	res = 0;
	if (**fmt == '0')
		return (ft_printf_flags(fmt, x)); //Starting with zero is a flag);

	while (ISDIGIT(**fmt))
	{
		res = res * 10 + (**fmt - '0');
		++*fmt;
	}
	x->width = res;
	printf("Width = %d\n", x->width);
	return (0);
}

int8_t	ft_printf_dot(const char **fmt, t_printf *x)
{
	size_t	res;

	res = 0;
	if (**fmt != '.')
		return (-1);		//This error doesn't go anywhere
	++*fmt;
	x->is_prec = 1;
	while (ISDIGIT(**fmt))
	{
		res = res * 10 + (**fmt - '0');
		++*fmt;
	}
	x->prec = res;
	printf("Precision = %d\n", x->prec);
	return (0);
}

int8_t	ft_printf_length(const char **fmt, t_printf *x)
{
	if (ft_strnstr(*fmt, "hh", 2) != NULL)
	{
		printf("hh Flag \n");
		x->len_mod = 1;
		++*fmt;
	}
	else if (ft_strnstr(*fmt, "h", 1) != NULL)
	{
		printf("h Flag\n");
		x->len_mod = 2;
	}
	else if (ft_strnstr(*fmt, "ll", 2) != NULL)
	{
		printf("ll Flag\n");
		x->len_mod = 4;
		++*fmt;
	}
	else if (ft_strnstr(*fmt, "l", 1) != NULL)
	{
		printf("l Flag\n");
		x->len_mod = 3;
	}
	else if (ft_strnstr(*fmt, "j", 1) != NULL)
	{
		printf("j Flag\n");
		x->len_mod = 5;
	}
	else if (ft_strnstr(*fmt, "z", 1) != NULL)
	{
		printf("z Flag\n");
		x->len_mod = 6;
	}
	else if (ft_strnstr(*fmt, "L", 1) != NULL)
	{
		printf("L Flag\n");
		x->len_mod = 7;
	}
	++*fmt;
	return (0);
}
