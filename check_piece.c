/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:45:21 by kmashao           #+#    #+#             */
/*   Updated: 2018/09/02 17:09:02 by kmashao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "stdio.h"

static int	contakt(t_filler *check, int *contact, int y_m, int x_m)
{
	if (check->piece[check->y_piece][check->x_piece] == '*')
	{
		if (check->map[y_m][x_m] == check->player_id
			|| check->map[y_m][x_m] == check->player_id + 32)
			(*contact)++;
		if (check->map[y_m][x_m] == check->enemy_id || check->map[y_m][x_m] == check->enemy_id +32)
			return (0);
	}
	return (1);
}

static int	check(t_filler *check, int y_m, int x_m)
{
	int		contact;
	int		x_m_save;

	contact = 0;
	x_m_save = x_m;
	check->y_piece = check->crop_y_start;
	while (y_m < check->map_y && check->y_piece < check->piece_y)
	{
		x_m = x_m_save;
		check->x_piece = check->crop_x_start;
		while (x_m < check->map_x && check->x_piece < check->piece_x)
		{
			if (!(contakt(check, &contact, y_m, x_m)))
				return (0);
			check->x_piece++;
			x_m++;
		}
		check->y_piece++;
		y_m++;
	}
	return (contact == 1 ? 1 : 0);
}

int			check_piece(t_filler *ch, int y_m, int x_m)
{
	if ((y_m + ch->piece_y) > ch->map_y)
		return (0);
	else if ((x_m + ch->piece_x) > ch->map_x)
		return (0);
	return (check(ch, y_m, x_m));
}
