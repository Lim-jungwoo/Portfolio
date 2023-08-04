/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:49:31 by jlim              #+#    #+#             */
/*   Updated: 2022/03/08 11:49:32 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{//받아오는 것이 없으면 바로 종료
		printf(NOT_ARGUMENT);
		return (-1);
	}
	map = NULL;
	if (parse_map(&map, argv[1]) == -1) //맵을 파싱한다.
	{
		printf(INVALID_MAP);
		//map_print(&map);
		map_clear(&map);
		return (-1);
	}
	map_print(&map);
	map_clear(&map);

	return (0);
}
