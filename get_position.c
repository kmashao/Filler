/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:49:04 by kmashao           #+#    #+#             */
/*   Updated: 2018/09/02 13:30:51 by kmashao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		get_position(t_filler *pos)
{
	int	y;
	int	x;

	y = 0;
	pos->enemy_id = (pos->player_id == 'O') ? 'X' : 'O';
	while (y < pos->map_y)
	{
		x = 0;
		while (x < pos->map_x)
		{
			if (pos->map[y][x] == pos->enemy_id)
			{
				pos->enemy_x = x;
				pos->enemy_y = y;
			}
			else if (pos->map[y][x] == pos->player_id)
			{
				pos->player_x = x;
				pos->player_y = y;
			}
			x++;
		}
		y++;
	}
	pos->flag = (pos->enemy_y > pos->player_y) ? 1 : 0;
}
