/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:38:22 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/23 23:42:44 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	char		*ret;
	int			len;

	if (fmt == 0 || *fmt == 0)
		return (0);

	va_start (ap, fmt);
	len = ft_vasprintf(&ret, fmt, ap); // ADD CHK
	write(1, ret, len); //ADD CHK
	free(ret);
	va_end (ap);
	return (len);
}

