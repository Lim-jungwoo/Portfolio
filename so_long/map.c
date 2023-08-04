/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:11:46 by jlim              #+#    #+#             */
/*   Updated: 2021/06/24 15:32:54 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
int		map_width(t_map *map)
{
	return (ft_strlen(map->line));
}
*/
int		map_width(t_map *map)
{
	t_map	*check;
	int		max;

	check = map;
	max = 0;
	while (1)
	{
		if (max < (int)ft_strlen(check->line))
			max = (int)ft_strlen(check->line);
		if (check->next)
			check = check->next;
		else
			break ;
	}
	return (max);
}

int		map_height(t_map *map)
{
	int	height;

	height = 0;
	while (map)
	{
		height++;
		map = map->next;
	}
	return (height);
}

char	map_index(t_map *map, int width, int height)
{
	while (height-- > 0)
		map = map->next;
	return ((map->line)[width]);
}

void	map_clear(t_map **map_ptr)
{
	t_map	*line;
	t_map	*next;

	line = *map_ptr;
	while (line)
	{
		next = line->next;
		free(line->line);
		free(line);
		line = next;
	}
	*map_ptr = NULL;
}
