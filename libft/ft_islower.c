/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:17:56 by jkalia            #+#    #+#             */
/*   Updated: 2017/02/27 11:18:12 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_islower(int c)
{
	return ((c >= 'a' && c <= 'z') ? 1 : 0);
}
