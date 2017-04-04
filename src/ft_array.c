/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:01:25 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/04 12:40:29 by jkalia           ###   ########.fr       */
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
	src->len = 0;
	return (0);
}

int8_t	ft_arr_sizechk(t_arr *src, size_t sze)
{
	CHK(src == 0, -1);
	CHK(src->cap == 0, -1);

	if (sze + src->len > src->cap)
	{
		CHK(ft_arr_resize(src, sze) == -1, -1);
	}
	return (0);
}

int8_t	ft_arr_resize(t_arr *src, size_t sze)
{
	size_t	malloc_sze;
	void	*tmp;
	
	CHK(src == 0, -1);
	CHK(src->cap == 0, -1);
	malloc_sze = src->cap;		//In case ret cap is a 0
	if (sze + src->len > malloc_sze)
	{
		while (sze + src->len > malloc_sze)		//Keeping increasing Malloc size
			malloc_sze *= 2;
		CHK((tmp = ft_memalloc(malloc_sze)) == 0, -1);
		if (src->len != 0)
			ft_memcpy(tmp, src->ptr, src->len);
		free(src->ptr);
		src->ptr = tmp;
		src->cap = malloc_sze;
	}
	return (0);
}

int8_t	ft_arr_insert(t_arr *dst, size_t index, const void *src)
{
	CHK(dst == 0, -1);
	CHK(dst->cap == 0, -1);
	CHK((ft_arr_sizechk(dst, 1) == -1), -1);
	if (index < dst->len)
		ft_memmove(&dst->ptr[index + 1], &dst->ptr[index], dst->len - index);
	ft_memcpy(&dst->ptr[index], src, 1);
	++dst->len;
	return (0);
}

int8_t	ft_arr_insertn(t_arr *dst, size_t index, const void *src, size_t src_len)
{
	CHK(dst == 0, -1);
	CHK(dst->cap == 0, -1);
	CHK((ft_arr_sizechk(dst, src_len) == -1), -1);
	if (index < dst->len)
		ft_memmove(&dst->ptr[index + src_len], &dst->ptr[index], dst->len - index);
	ft_memcpy(&dst->ptr[index], src, src_len);
	dst->len += src_len;
	return (0);
}

int8_t	ft_arr_append(t_arr *dst, const void *src)
{
	CHK(dst == 0, -1);
	CHK(dst->cap == 0, -1);
	CHK(ft_arr_sizechk(dst, 1) == -1, -1);
	ft_memcpy(&dst->ptr[dst->len], src, 1);
	++dst->len;
	return (0);
}

int8_t	ft_arr_appendn(t_arr *dst, const void *src, size_t n)
{
	CHK(dst == 0, -1);
	CHK(dst->cap == 0, -1);
	CHK(ft_arr_sizechk(dst, n) == -1, -1);
	ft_memcpy(&dst->ptr[dst->len], src, n);
	dst->len += n;
	return (0);
}

int8_t	ft_arr_append_arr(t_arr *dst, t_arr *src)
{
	CHK(dst == 0, -1);
	CHK(dst->cap == 0, -1);
	CHK(ft_arr_sizechk(dst, src->len) == -1, -1);
	ft_memcpy(&dst->ptr[dst->len], src->ptr, src->len);
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

int8_t		ft_printf_append(t_arr *ret, const char **fmt, t_printf *x)
{
	CHK2((ft_arr_append_arr(ret, &x->extra)) == -1, ft_arr_del(ret), ft_arr_del(&x->extra), -1);
	++*fmt;
	return (0);
}

int8_t		ft_printf_init(t_printf *x)
{
	ft_bzero(x, sizeof(t_printf));
	x->prec = -1; //Initial value of prec is -1
	x->pad = ' '; //Initial value of pad is ' '
	return (0);
}
