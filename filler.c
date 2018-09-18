/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 10:32:16 by kmashao           #+#    #+#             */
/*   Updated: 2018/09/03 09:16:08 by kmashao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	initialise(t_filler *initial)
{
	initial->x_m = 0;
	initial->y_m = 0;
	initial->x_piece = 0;
	initial->y_piece = 0;
	initial->map = NULL;
	initial->map_x = 0;
	initial->map_y = 0;
	initial->piece = NULL;
	initial->piece_x = 0;
	initial->piece_y = 0;
	initial->crop_x_start = 0;
	initial->crop_x_end = 0;
	initial->crop_y_start = 0;
	initial->crop_y_end = 0;
	initial->valid_x = 0;
	initial->valid_y = 0;
	initial->flag = 0;
	initial->stop = 0;
	initial->player_id = '\0';
	initial->player_x = 0;
	initial->player_y = 0;
	initial->enemy_id = '\0';
	initial->enemy_x = 0;
	initial->enemy_y = 0;
}

int		main(void)
{
	t_filler	*game;
	char		*line;

	line = NULL;
	game = (t_filler *)malloc(sizeof(t_filler));
	initialise(game);
	get_next_line(0, &line);
	game->player_id = (ft_atoi(line + 10) == 1) ? 'O' : 'X';
	while (1)
	{
		get_map(game);
		if (game->player_x == 0 && game->player_y == 0 &&
				game->enemy_x == 0 && game->enemy_y == 0)
			get_position(game);
		get_piece(game);
		if (!ai(game))
			game->stop = 1;
		place(game);
		if (game->stop == 1)
			break ;
	}
	free(game);
	return (0);
}
