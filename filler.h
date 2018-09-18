/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 10:06:49 by kmashao           #+#    #+#             */
/*   Updated: 2018/09/02 15:21:44 by kmashao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_filler
{
	int				map_y;
	int				map_x;
	char			**map;

	int				piece_y;
	int				piece_x;
	int				crop_x_start;
	int				crop_y_start;
	int				crop_x_end;
	int				crop_y_end;
	char			**piece;

	char			player_id;
	int				player_x;
	int				player_y;

	char			enemy_id;
	int				enemy_x;
	int				enemy_y;

	int				x_m;
	int				y_m;
	int				x_piece;
	int				y_piece;

	int				valid_x;
	int				valid_y;
	int				stop;
	int				flag;

}					t_filler;

int					get_piece(t_filler *piece);
void				crop_piece(t_filler *full_piece);
int					get_map(t_filler *map);
void				initialise(t_filler *initial);
void				get_position(t_filler *pos);
int					check_piece(t_filler *check, int y_m, int x_m);
void				place(t_filler *ptp);
int					ai(t_filler *game);
#endif
