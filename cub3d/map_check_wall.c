/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:43:24 by jlim              #+#    #+#             */
/*   Updated: 2022/03/08 16:43:25 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_check_first_ch(t_map **map_ptr)
{//첫 번째 글자가 1인지 확인
	t_map	*check;
	int		index;
	int		end_flag;

	check = *map_ptr;
	end_flag = 0;
	while (1)
	{
		index = 0;
		while (check->line[index] == ' ')
			index++;
		if (check->line[index] != '1')
			return (-1);
		if (end_flag == 1)
			break ;
		if (check->next)
			check = check->next;
		else
			end_flag = 1;
	}
	return (0);
}

int	map_check_end_ch(t_map **map_ptr)
{//마지막 글자가 1인지 확인
	t_map	*check;
	int		index;
	int		end_flag;

	check = *map_ptr;
	end_flag = 0;
	while (1)
	{
		index = (int)ft_strlen(check->line) - 1;
		if (check->line[index] != '1')
			return (-1);
		if (end_flag == 1)
			break ;
		if (check->next)
			check = check->next;
		else
			end_flag = 1;
	}
	return (0);
}

int	map_check_first_line(t_map **map_ptr)
{
	t_map	*check_first;
	int		index;

	check_first = *map_ptr;
	index = 0;
	while (check_first->line[index])
	{//맨 첫줄이 벽이나 공백으로 둘러싸여 있는지 확인
		if (check_first->line[index] != '1' && check_first->line[index] != ' ')
		{
			printf(NO_WALL);
			return (-1);
		}
		index++;
	}
	return (0);
}

int	map_check_end_line(t_map **map_ptr)
{//마지막 줄이 벽이나 공백으로 둘러싸여 있는지 확인
	t_map	*check_end;
	int		index;

	check_end = *map_ptr;
	index = 0;
	while (check_end->next)
		check_end = check_end->next;
	while (check_end->line[index])
	{
		if (check_end->line[index] != '1' && check_end->line[index] != ' ')
		{
			printf(NO_WALL);
			return (-1);
		}
		index++;
	}
	return (0);
}