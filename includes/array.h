/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 23:33:08 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/05 23:38:05 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

typedef struct		s_arr
{
	char			*ptr;
	size_t			len;
	size_t			cap;
}					t_arr;

typedef struct		s_printf
{
	t_arr			extra;
	unsigned int	is_prec:1;
	int				prec;
	int				width;
	unsigned int	left:1;
	unsigned int	showsign:1;
	unsigned int	space:1;
	unsigned int	zero:1;
	unsigned int	alt:1;
	uint8_t			len_mod;
	char			pad;
}					t_printf;

int8_t				ft_arr_init(t_arr *src, size_t cap);
int8_t				ft_arr_appendn(t_arr *dst, const void *src, size_t n);
int8_t				ft_arr_append_arr(t_arr *dst, t_arr *src);
int8_t				ft_arr_resize(t_arr *src, size_t sze);
int8_t				ft_arr_insertn(t_arr *dst, size_t index,
		const void *src, size_t src_len);
void				ft_arr_del(t_arr *src);
char				*ft_arrtostr(t_arr *src);

#endif