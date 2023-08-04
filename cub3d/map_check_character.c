/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_character.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:50:23 by jlim              #+#    #+#             */
/*   Updated: 2022/03/08 16:50:23 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	NSEW_check(t_map **map_ptr, char c)
{
	t_map	*check;
	int		index;

	check = *map_ptr;
	while (check->next)
	{
		index = 0;
		while (check->line[index])
		{
			if (check->line[index] == c)
				return (1);
			index++;
		}
		check = check->next;
	}
	return (0);
}

int	map_check_character(t_map **map_ptr)
{//맵에 N, S, E, W 중 하나만 존재하는 지 확인하고 아니면 -1을 리턴
	if (NSEW_check(map_ptr, 'N'))
		if (NSEW_check(map_ptr, 'S') || NSEW_check(map_ptr, 'E') || NSEW_check(map_ptr, 'W'))
			return (-1);
	if (NSEW_check(map_ptr, 'S'))
		if (NSEW_check(map_ptr, 'N') || NSEW_check(map_ptr, 'E') || NSEW_check(map_ptr, 'W'))
			return (-1);
	if (NSEW_check(map_ptr, 'E'))
		if (NSEW_check(map_ptr, 'S') || NSEW_check(map_ptr, 'N') || NSEW_check(map_ptr, 'W'))
			return (-1);
	if (NSEW_check(map_ptr, 'W'))
		if (NSEW_check(map_ptr, 'S') || NSEW_check(map_ptr, 'E') || NSEW_check(map_ptr, 'N'))
			return (-1);
	if (NSEW_check(map_ptr, 'N') || NSEW_check(map_ptr, 'S') || NSEW_check(map_ptr, 'E') || NSEW_check(map_ptr, 'W'))
		return (0);
	return (-1);
}