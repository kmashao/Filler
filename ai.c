/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:16:43 by kmashao           #+#    #+#             */
/*   Updated: 2018/09/02 13:33:43 by kmashao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	top_left(t_filler *game)
{
	int	x_map;
	int	y_map;

	y_map = 0;
	while (y_map < game->map_y)
	{
		x_map = 0;
		while (x_map < game->map_x)
		{
			if (check_piece(game, y_map, x_map) == 1)
			{
				game->valid_x = x_map;
				game->valid_y = y_map;
				return (1);
			}
			x_map++;
		}
		y_map++;
	}
	return (0);
}

static int	top_right(t_filler *game)
{
	int x_map;
	int y_map;

	y_map = 0;
	while (y_map < game->map_y)
	{
		x_map = game->map_x;
		while (x_map > 0)
		{
			if (check_piece(game, y_map, x_map) == 1)
			{
				game->valid_x = x_map;
				game->valid_y = y_map;
				return (1);
			}
			x_map--;
		}
		y_map++;
	}
	return (0);
}

static int	bottom_right(t_filler *game)
{
	int x_map;
	int y_map;

	y_map = game->map_y;
	while (y_map > 0)
	{
		x_map = game->map_x;
		while (x_map > 0)
		{
			if (check_piece(game, y_map, x_map) == 1)
			{
				game->valid_x = x_map;
				game->valid_y = y_map;
				return (1);
			}
			x_map--;
		}
		y_map--;
	}
	return (0);
}

static int	bottom_left(t_filler *game)
{
	int x_map;
	int y_map;

	y_map = game->map_y;
	while (y_map > 0)
	{
		x_map = 0;
		while (x_map < game->map_x)
		{
			if (check_piece(game, y_map, x_map) == 1)
			{
				game->valid_x = x_map;
				game->valid_y = y_map;
				return (1);
			}
			x_map++;
		}
		y_map--;
	}
	return (0);
}

int			ai(t_filler *game)
{
	if (game->flag == 0)
		return (top_left(game));
	else if (game->flag == 1)
		return (bottom_right(game));
	else if (game->flag == 2)
		return (top_right(game));
	else if (game->flag == 3)
		return (bottom_left(game));
	return (0);
}
