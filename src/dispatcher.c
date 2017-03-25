/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:57:42 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/24 19:25:54 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

//Arr Append
//Arr Resize

int		ft_printf_d(t_arr *ret, const char **fmt, va_list clone)
{
	int			org;
	char		*nbr;

	org = va_arg(clone, int);
	nbr = ft_itoa(org);
	printf("nbr = %s\n", nbr);
	ft_strnjoinf(ret->ptr, ft_strlen(ret->ptr), nbr, ft_strlen(nbr)); // pehaps use strjoin?? Array Append.
	printf("ret = %s\n", ret->ptr);
	printf("Before FMT = %s\n", *fmt);
	*fmt = *fmt + 1; // Incrementing the pointer by one. Completed d; There must be a better way to do this
	printf("After FMT = %s\n", *fmt);
	free(nbr);
	ret->len += ft_strlen(nbr);
	return (0); // Use Itoa Base
}

static int	choosetype(t_arr *ret, const char **fmt, va_list clone)
{
	if (ft_strstr(*fmt, "d") != NULL)
		return (ft_printf_d(ret, fmt, clone));
	return (0); //Doesn't Match any of the types ????
}


static int	dispatch(char **final, const char *fmt, va_list clone)
{
	int			i;
	const char	*limit;
	t_arr		ret;

	limit = ft_strlen(fmt) + fmt;
	ret.cap = ft_strlen(fmt) + 100;		//Initial size is slightly bigger than initial size of fmt string? Is this a good choice?
	ret.len = 0;						//Initializing len to 0
	ret.ptr = ft_strnew(ret.cap);
	while (fmt < limit)
	{
		i = 0;
		while (fmt[i] != '%' && fmt[i] != 0)
			i++;
		ft_memcpy(ret.ptr, fmt, i); //  -1 to Not copy over the percentage //POSSIBLE ISSUE
		fmt += i;
		ret.len += i;
		if (ret.len >= ret.cap)			//Need to figure this out. Resize Array. Implementing Realloc.
			return (0);
		if (*fmt == '%')
		{
			if (*(++fmt) == 0) //Percentage is the last thing in the string. Also increments ahead of percentage.
				break;
			choosetype(&ret, &fmt, clone); //Passing the address of fmt so that it can be incremented by other functions.
		}
	}
	*final = ft_strnew(ret.len);
	ft_memcpy(final, ret.ptr, ret.len);
	return (ret.len);
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
	printf("VASPRINTF = %s\n", *ret);
	va_end(clone);
	return (len);
}

// there is another way to do it, parse the whole fmt string and va_arg to calculate the size of the malloc.
