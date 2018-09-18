/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 08:43:32 by kmashao           #+#    #+#             */
/*   Updated: 2018/09/02 13:27:38 by kmashao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_map(t_filler *map)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	while (!(ft_strstr(line, "Plateau")))
		get_next_line(0, &line);
	map->map_y = ft_atoi(&line[8]);
	map->map_x = ft_atoi(&line[11]);
	if (!map->map)
		if (!(map->map = ft_strnew_two(map->map_y)))
			return (-1);
	get_next_line(0, &line);
	ft_strdel(&line);
	while (i < map->map_y)
	{
		get_next_line(0, &line);
		if (ft_isdigit(line[0]))
			map->map[i] = ft_strdup(line + 4);
		i++;
	}
	map->map[i] = NULL;
	return (0);
}
