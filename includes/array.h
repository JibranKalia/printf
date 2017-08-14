/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 23:33:08 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/13 13:56:15 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

typedef struct		s_arr
{
	char			*ptr;		// Data currently held
	size_t			len;		// Space currenlty being used
	size_t			cap;		// Total Space Allocated
}					t_arr;

typedef struct		s_printf
{
	t_arr			extra;
	unsigned int	is_prec:1;	// If Precision has been set
	int				prec;		// Precision Value
	int				width;		// Width Value
	unsigned int	left:1;		// If '-' flag is set
	unsigned int	showsign:1;	// If '+' flag is set
	unsigned int	space:1;	// If ' ' flag is set
	unsigned int	zero:1;		// If '0' flag is set
	unsigned int	alt:1;		// If '#' flag is set
	uint8_t			len_mod;	// Number of Lenght Modifier used
	char			pad;		// Padding Character used. Either ' ' or '0'
}					t_printf;

void				ft_arr_del(t_arr *src);
char				*ft_arrtostr(t_arr *src);
int8_t				ft_arr_init(t_arr *src, size_t cap);
int8_t				ft_arr_appendn(t_arr *dst, const void *src, size_t n);
int8_t				ft_arr_append_arr(t_arr *dst, t_arr *src);
int8_t				ft_arr_resize(t_arr *src, size_t sze);
int8_t				ft_arr_sizechk(t_arr *src, size_t sze);
int8_t				ft_arr_insertn(t_arr *dst, size_t index,
		const void *src, size_t src_len);
uintmax_t			ft_printf_uox_len(t_printf *x, va_list clone);

#endif
