/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 22:57:42 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/27 17:47:11 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int8_t	ft_arr_init(t_arr *src, size_t cap)
{
	if (src == 0 || cap == 0)
		return (-1);
	ft_bzero(src, sizeof(t_arr));
	CHK((src->ptr = ft_memalloc(cap)) == NULL, -1);
	src->cap = cap;
	return (0);
}

int8_t	ft_arr_resize(t_arr *ret, size_t sze)
{
	size_t	malloc_sze;
	void	*tmp;

	malloc_sze = ret->cap + 1;		//In case ret cap is a 0
	while (malloc_sze < sze)		//Keeping increasing Malloc size
		malloc_sze *= 2;
	CHK((tmp = ft_memalloc(malloc_sze)) == 0, -1);
	ft_memcpy(tmp, ret->ptr, ret->len);
	free(ret->ptr);
	ret->ptr = tmp;
	ret->cap = malloc_sze;
	return (0);
}

int8_t	ft_arr_append_str(t_arr *dst, char *src)
{
	size_t	src_len;
	
	src_len = ft_strlen(src);
	if (dst->cap < src_len + dst->len)
		CHK((ft_arr_resize(dst, src_len + dst->len)) == -1, -1);
	ft_memcpy(dst->ptr + dst->len, src, src_len);
	dst->len += src_len;
	return (0);
}

int8_t	ft_arr_append_strn(t_arr *dst, char *src, size_t n)
{
	size_t	src_len;
	
	src_len = n;
	if (dst->cap < src_len + dst->len)
		CHK((ft_arr_resize(dst, src_len + dst->len)) == -1, -1);
	ft_memcpy(dst->ptr + dst->len, src, src_len);
	dst->len += n;
	return (0);
}

int8_t	ft_arr_append_arr(t_arr *dst, t_arr *src)
{
	if (dst->cap < src->len + dst->len)
		CHK((ft_arr_resize(dst, src->len + dst->len)) == -1, -1);
	ft_memcpy(dst->ptr + dst->len, src->ptr, src->len);
	dst->len += src->len;
	return (0);
}

void	ft_arr_del(t_arr *src)
{
	if (src == 0)
		return ;
	if (src->cap > 0)
		free(src->ptr);
	ft_bzero(src, sizeof(t_arr));
}

char	*ft_arrtostr(t_arr *src)
{
	CHK(src == 0, 0);
	CHK(src->cap == 0, 0);
	return (src->ptr);
}

int8_t	ft_printf_append(t_arr *ret, const char **fmt, t_printf *x)
{
	CHK2((ft_arr_append_arr(ret, &x->extra)) == -1, ft_arr_del(ret), ft_arr_del(&x->extra), -1);
	++*fmt;
	return (0);
}

int8_t	ft_printf_d(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	int			org;
	char		*nbr;

	org = va_arg(clone, int);
	nbr = ft_itoa(org);				//ITOA BASE
	ft_arr_append_str(&x->extra, nbr);
	free(nbr);
	return (ft_printf_append(ret, fmt, x));
}

static int	choosetype(t_arr *ret, const char **fmt, t_printf *x, va_list clone)
{
	if (ft_strstr(*fmt, "d") != NULL)
		return (ft_printf_d(ret, fmt, x, clone));
	return (0); //Doesn't Match any of the types ????
}

static int	dispatch(char **final, const char *fmt, va_list clone)
{
	size_t			i;
	t_arr			ret;
	t_printf		x;

	ft_arr_init(&ret, ft_strlen(fmt) + 10);
	ft_bzero(&x, sizeof(t_printf));
	while (*fmt)
	{
		i = 0;
		while (fmt[i] != '%' && fmt[i] != 0)
			i++;
		ft_arr_append_strn(&ret, (char*)fmt, i);
		fmt += i;
		if (*fmt == '%')
		{
			if (*(++fmt) == 0) //Percentage is the last thing in the string. Also increments ahead of percentage.
				break;
			choosetype(&ret, &fmt, &x, clone); //Passing the address of fmt so that it can be incremented by other functions.
		}
	}
	//Copying the result of array onto output string.
	*final = ft_arrtostr(&ret);
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
	va_copy(clone, ap); //Why clone again?
	len = dispatch(ret, fmt, clone); // VAS Prints out on to the malloc'd string.
	va_end(clone);
	return (len);
}

// there is another way to do it, parse the whole fmt string and va_arg to calculate the size of the malloc.
