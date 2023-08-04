/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_nsew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:07:37 by jlim              #+#    #+#             */
/*   Updated: 2022/03/10 11:07:40 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	init_nsew_flag(t_flag *nsew_flag)
{
	nsew_flag->NO_flag = 0;
	nsew_flag->SO_flag = 0;
	nsew_flag->WE_flag = 0;
	nsew_flag->EA_flag = 0;
	nsew_flag->F_flag = 0;
	nsew_flag->C_flag = 0;
}

int	map_check_nsew(t_map **map_ptr, t_flag *nsew_flag)
{
	while (ft_strcmp((*map_ptr)->line, "") != 0)
	{
		if (ft_strncmp((*map_ptr)->line, "NO", 2) == 0)
		{
			if (nsew_flag->NO_flag == 1)
				return (-1);
			nsew_flag->NO_flag = 1;
			//map_check_texture로 texture을 구하고
			//mlx구조체에다 NO뒤의 texture을 넣어주면 될 듯
			(*map_ptr) = (*map_ptr)->next;
		}
		else if (ft_strncmp((*map_ptr)->line, "SO", 2) == 0)
		{
			if (nsew_flag->SO_flag == 1)
				return (-1);
			nsew_flag->SO_flag = 1;
			//map_check_texture로 texture을 구하고
			//mlx구조체에다 NO뒤의 texture을 넣어주면 될 듯
			(*map_ptr) = (*map_ptr)->next;
		}
		else if (ft_strncmp((*map_ptr)->line, "WE", 2) == 0)
		{
			if (nsew_flag->WE_flag == 1)
				return (-1);
			nsew_flag->WE_flag = 1;
			//map_check_texture로 texture을 구하고
			//mlx구조체에다 NO뒤의 texture을 넣어주면 될 듯
			(*map_ptr) = (*map_ptr)->next;
		}
		else if (ft_strncmp((*map_ptr)->line, "EA", 2) == 0)
		{
			if (nsew_flag->EA_flag == 1)
				return (-1);
			nsew_flag->EA_flag = 1;
			//map_check_texture로 texture을 구하고
			//mlx구조체에다 NO뒤의 texture을 넣어주면 될 듯
			(*map_ptr) = (*map_ptr)->next;
		}
		else if (ft_strncmp((*map_ptr)->line, "F", 1) == 0)
		{
			if (nsew_flag->F_flag == 1)
				return (-1);
			nsew_flag->F_flag = 1;
			//map_check_texture로 texture을 구하고
			//mlx구조체에다 NO뒤의 texture을 넣어주면 될 듯
			(*map_ptr) = (*map_ptr)->next;
		}
		else if (ft_strncmp((*map_ptr)->line, "C", 1) == 0)
		{
			if (nsew_flag->C_flag == 1)
				return (-1);
			nsew_flag->C_flag = 1;
			//map_check_texture로 texture을 구하고
			//mlx구조체에다 NO뒤의 texture을 넣어주면 될 듯
			(*map_ptr) = (*map_ptr)->next;
		}
		else //이상한 identifier가 들어왔으므로 에러 발생
			return (-1);
	}
	return (0);
}

char	*map_check_texture(t_map **map_ptr)
{//texture을 확인하고 동적할당하여 리턴해주는 함수
	char	*texture;
	int		i;

	while (ft_strcmp((*map_ptr)->line, "") == 0)
		(*map_ptr) = (*map_ptr)->next;
	i = 0;
	while (ft_isspace((*map_ptr)->line[i]) == 0)
		i++;
	while (ft_isspace((*map_ptr)->line[i]))
		i++;
	texture = ft_strdup((&(*map_ptr)->line[i]));
	return (texture);
}



int	map_check_identifier(t_map **map_ptr)
{
	t_flag	nsew_flag;

	init_nsew_flag(&nsew_flag);
	while (!nsew_flag.NO_flag || !nsew_flag.SO_flag || !nsew_flag.WE_flag
		|| !nsew_flag.EA_flag || !nsew_flag.F_flag || !nsew_flag.C_flag)
	{
		if (map_check_nsew(map_ptr, &nsew_flag) == -1)
			return (-1);
		if (map_check_empty(map_ptr) == -1)
			return (-1);
	}
	return (0);
}
