/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:57:42 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/24 00:21:38 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int		ft_printf_d(char **ret, const char **fmt, va_list clone)
{
	int			org;
	char		*nbr;

	printf("Error Here?");

	org = va_arg(clone, int);
	nbr = ft_itoa(org);
	ft_strcat(*ret, nbr);
	fmt++; // Incrementing the pointer by one. Completed d && i;
	return (ft_strlen(nbr));
}

static int	choosetype(char **ret, const char **fmt, va_list clone)
{
	//char	c;

	printf("String %s\n", *fmt);
	if (ft_strstr(*fmt, "%d") != NULL)
		return (ft_printf_d(ret, fmt, clone));
	//if (*fmt == '%')
	return (0); //Doesn't Match any of the types ????
}


static int	dispatch(char **ret, const char *fmt, va_list clone)
{
	int		i;
	int		len;	//Number of bytes copied???

	*ret = ft_strnew(ft_strlen(fmt) * 100); // Probably not a good place to malloc. Will need a resizable array anyway.
	len = 0;
	while (*fmt)
	{
		i = 0;
		while (fmt[i] != '%' && fmt[i] != '\0')
			i++;
		ft_memcpy(*ret, fmt, i - 1); //  -1 to Not copy over the percentage //POSSIBLE ISSUE
		fmt += i;
		len += i;
		if (*fmt == '%')
		{
			if (*(fmt + 1) == 0) //Percentage is the last thing in the string.
				break;
			len += choosetype(ret, &fmt, clone); //Passing the address of fmt so that it can be incremented by other functions.
		}
	}
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
	va_copy(clone, ap);
	len = dispatch(ret, fmt, clone); // VAS Prints out on to the malloc'd string.
	va_end(clone);
	return (len);
}
