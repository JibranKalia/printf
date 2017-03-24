/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:38:22 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/23 20:55:38 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	char		*ret;
	int			done;

	if (fmt == 0 || *fmt == 0)
		return (0);

	va_start (ap, fmt);
	done = ft_vasprintf(&ret, fmt, ap); // ADD CHK
	write(1, ret, done); //ADD CHK
	free(ret);
	va_end (ap);
	return (done);
}

int		ft_vasprintf(char **ret, const char *fmt, va_list ap)
{

	if (fmt == 0 || *fmt == 0 || ret == 0)
		return (0);
	*ret = 0;

	if (ft_strchr(*fmt, '%') == 0)
	{
		// DUP onto ret.
	}
	r = dispatch(
}
