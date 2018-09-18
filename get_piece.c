/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:46:10 by kmashao           #+#    #+#             */
/*   Updated: 2018/09/02 13:28:35 by kmashao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_piece(t_filler *piece)
{
	char	*line;
	int		j;

	j = 0;
	get_next_line(0, &line);
	while (!(ft_strstr(line, "Piece")))
		get_next_line(0, &line);
	piece->piece_y = ft_atoi(&line[6]);
	piece->piece_x = ft_atoi(&line[8]);
	if (!piece->piece)
		if (!(piece->piece = ft_strnew_two(piece->piece_y)))
			return (-1);
	ft_strdel(&line);
	while (j < piece->piece_y)
	{
		get_next_line(0, &line);
		piece->piece[j] = ft_strdup(line);
		j++;
	}
	piece->piece[j] = NULL;
	crop_piece(piece);
	return (0);
}
