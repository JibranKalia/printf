/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:38:22 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/06 14:11:34 by jkalia           ###   ########.fr       */
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
	CHK((len = ft_vasprintf(&ret, fmt, ap)) == -1, -1);
	write(1, ret, len);
	free(ret);
	va_end (ap);
	return (len);
}

int		ft_asprintf(char **ret, const char *fmt, ...)
{
	va_list		ap;
	int			len;

	if (fmt == 0 || *fmt == 0)
		return (0);

	va_start (ap, fmt);
	len = ft_vasprintf(ret, fmt, ap); // ADD CHK
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
//TODO: Need to set pointer to null if return is -1;

// there is another way to do it, parse the whole fmt string and va_arg to calculate the size of the malloc.
