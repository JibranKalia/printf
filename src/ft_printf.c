/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:38:22 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/30 13:27:46 by jkalia           ###   ########.fr       */
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

int		ft_vasprintf(char **ret, const char *fmt, va_list ap)
{
	int			len;
	va_list		clone;

	if (fmt == 0 || *fmt == 0 || ret == 0)
		return (0);
	*ret = 0;
	if (ft_strchr(fmt, '%') == NULL) // % Not found. Print as it is.
	{
		*ret = ft_strdup(fmt);
		return (ft_strlen(fmt));
	}
	va_copy(clone, ap); //Why clone again?
	len = dispatch(ret, fmt, clone); // VAS Prints out on to the malloc'd string.
	va_end(clone);
	return (len);
}

// there is another way to do it, parse the whole fmt string and va_arg to calculate the size of the malloc.
