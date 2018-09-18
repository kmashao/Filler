/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crop_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:47:31 by kmashao           #+#    #+#             */
/*   Updated: 2018/09/02 13:26:50 by kmashao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	crop_piece(t_filler *full_piece)
{
	int		y;
	int		x;

	y = 0;
	while (y < full_piece->piece_y && !ft_strchr(full_piece->piece[y], '*'))
		y++;
	full_piece->crop_y_start = y;
	y = full_piece->piece_y - 1;
	while (!(ft_strchr(full_piece->piece[y], '*')))
		y--;
	full_piece->crop_y_end = y;
	full_piece->crop_x_start = full_piece->piece_x;
	while (y >= full_piece->crop_y_start)
	{
		x = 0;
		while (full_piece->piece[y][x])
		{
			if (full_piece->piece[y][x] == '*' && x <= full_piece->crop_x_start)
				full_piece->crop_x_start = x;
			if (full_piece->piece[y][x] == '*' && x >= full_piece->crop_x_end)
				full_piece->crop_x_end = x;
			x++;
		}
		y--;
	}
}
