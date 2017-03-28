/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:42:59 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/28 13:09:47 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int		ft_printf_flags(const char **fmt, t_printf *x)
{
	while (*fmt && (**fmt == '-' || **fmt == '+' || **fmt == ' ' || **fmt == '#' || **fmt == '0'))
	{
		if (**fmt == '-')
		{
			printf("Negative Flag\n");
			x->left = 1;
		}
		else if (**fmt == '+')
		{
			printf("Positive Flag\n");
			x->showsign = 1;
		}
		else if (**fmt == ' ')
		{
			printf("Space Flag\n");
			x->space = 1;
			pad = ' ';
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
			pad = '0';
		}
		++*fmt;
		++x->extra.len;
	}
	return (x->extra.len);
}

int		ft_printf_width(const char **fmt, t_printf *x)
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

int		ft_printf_dot(const char **fmt, t_printf *x)
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
