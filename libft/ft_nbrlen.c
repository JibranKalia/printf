/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:13:00 by jkalia            #+#    #+#             */
/*   Updated: 2017/04/01 08:55:23 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int8_t		ft_nbrlen(intmax_t src)
{
	int8_t		ret;

	if (src == 0)
		return (1);
	ret = (src < 0) ? 1 : 0;
	while (src != 0)
	{
		src = src / 10;
		++ret;
	}
	return (ret);
}
