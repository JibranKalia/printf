/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:42:59 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/27 21:09:48 by jkalia           ###   ########.fr       */
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
			x->flags |= NGV;
		}
		else if (**fmt == '+')
		{
			printf("Positive Flag\n");
			x->flags |= PSV;
		}
		else if (**fmt == ' ')
		{
			printf("Space Flag\n");
			x->flags |= SPC;
		}
		else if (**fmt == '#')
		{
			printf("Hash Flag\n");
			x->flags |= HSH;
		}
		else if (**fmt == '0')
		{
			printf("Zero Flag\n");
			x->flags |= ZRO;
		}
		++*fmt;
		++x->extra.len;
	}
	return (x->extra.len);
}

