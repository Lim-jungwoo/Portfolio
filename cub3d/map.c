/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:32:45 by jlim              #+#    #+#             */
/*   Updated: 2022/03/11 10:32:45 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_width(t_map **map_ptr)
{//맵에서 가장 긴 가로 길이를 구해서 그것을 반환
	t_map	*check;
	int		max;

	check = *map_ptr;
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

int	map_height(t_map **map_ptr)
{//맵의 세로 길이를 구하여 반환
	t_map	*check;
	int		height;

	check = *map_ptr;
	height = 0;
	while (1)
	{
		height++;
		if (check->next)
			check = check->next;
		else
			break ;
	}
	return (height);
}

/*
char	map_index(t_map **map_ptr, int width, int height)
{//맵에서 특정한 위치에 있는 값을 찾아준다.
	t_map	*check;

	check = *map_ptr;
	while (height-- > 0)
		check = check->next;
	return ((check->line[width]));
}*/


