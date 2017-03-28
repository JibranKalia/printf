/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:01:25 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/27 20:02:11 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
