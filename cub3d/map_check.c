/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:35:21 by jlim              #+#    #+#             */
/*   Updated: 2022/03/08 13:35:22 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int base_map_check(t_map **map_ptr)
{ // 간단하게 맵이 제대로 작성되었는지 확인
	// 맵의 라인이 2개 이하인지 확인
	t_map *check;
	int line_number;

	check = *map_ptr;
	line_number = 0;
	while (check->next)
	{
		line_number++;
		check = check->next;
	}
	if (line_number < 2)
		return (-1);
	return (0);
}

int map_check_space(t_map **map_ptr)
{ // 한 줄씩 넘어가면서 공백이 있을 경우 주변이 공백이나 1인지 확인
	// 에러 발생시 -1리턴, 성공시 0리턴
	t_map *check;
	int index;
	int end_flag;

	check = *map_ptr;
	end_flag = 0;
	while (1)
	{
		index = 0;
		while (check->line[index])
		{
			if (check->line[index] == ' ')
			{
				if (index > 0) // 공백의 왼쪽 확인
					if (check->line[index - 1] != ' ' && check->line[index - 1] != '1')
						return (-1);
				if (index < (int)ft_strlen(check->line) - 1) // 공백의 오른쪽 확인
					if (check->line[index + 1] != ' ' && check->line[index + 1] != '1')
						return (-1);
				if (check->prev) // 공백의 위쪽 확인
					if ((check->prev->line[index] != ' ' && check->prev->line[index] != '1') && ft_strcmp(check->prev->line, "") != 0)
						return (-1);
				if (check->next) // 공백의 아래쪽 확인
					if (check->next->line[index] != ' ' && check->next->line[index] != '1')
						return (-1);
			}
			index++;
		}
		if (end_flag == 1)
			break;
		if (check->next)
			check = check->next;
		else
			end_flag = 1;
	}
	return (0);
}

int map_check_wall_next(t_map **map_ptr)
{
	t_map *check;
	int end;
	int end_next;

	check = *map_ptr;
	while (check->next)
	{ // 한 줄씩 넘어가면서 다음 줄이 지금 줄보다 문자 개수가 많다면 지금 줄 마지막 문자의 인덱스 위치
		// 뒤에는 무조건 1이 오는지 확인
		end = (int)ft_strlen(check->line);
		end_next = (int)ft_strlen(check->next->line) - 1;
		if (end_next >= end)
		{
			while (check->next->line[end])
			{
				if (check->next->line[end] != '1')
					return (-1);
				end++;
			}
		}
		check = check->next;
	}
	return (0);
}

int map_check_wall_prev(t_map **map_ptr)
{
	t_map *check;
	t_map *first;
	int end;
	int end_prev;

	check = *map_ptr;
	first = *map_ptr;
	while (check->next)
		check = check->next;
	while (check != first)
	{
		// 한 줄씩 뒤로 넘어가면서 이전 줄이 지금 줄보다 문자 개수가 많다면 지금 줄 마지막 문자의 인덱스 위치
		// 뒤에는 무조건 1이 오는지 확인
		end = (int)ft_strlen(check->line);
		end_prev = (int)ft_strlen(check->prev->line) - 1;
		if (end_prev >= end)
		{
			while (check->prev->line[end])
			{
				if (check->prev->line[end] != '1')
					return (-1);
				end++;
			}
		}
		check = check->prev;
	}
	return (0);
}

int map_check_empty(t_map **map_ptr)
{ // 빈 줄을 확인하고 빈 줄은 건너뛰고 계속 넘어가는 함수
	// 빈 줄 다음에 아무 내용이 없으면 -1리턴
	while (ft_strcmp((*map_ptr)->line, "") == 0)
	{
		if ((*map_ptr)->next)
			(*map_ptr) = (*map_ptr)->next;
		else
			return (-1);
	}
	return (0);
}

int map_check(t_map **map_ptr)
{ // 에러가 발생하면 -1을 리턴
	t_map *check;

	check = *map_ptr;
	if (map_check_empty(&check) == -1)
		return (-1);
	if (map_check_identifier(&check) == -1)
		return (-1);

	if (base_map_check(&check) == -1)
		return (-1);

	if (map_check_character(&check) == -1)
		return (-1);

	if (map_check_first_line(&check) == -1)
		return (-1);

	if (map_check_end_line(&check) == -1)
		return (-1);

	if (map_check_first_ch(&check) == -1)
		return (-1);

	if (map_check_end_ch(&check) == -1)
		return (-1);

	if (map_check_wall_next(&check) == -1)
		return (-1);

	if (map_check_wall_prev(&check) == -1)
		return (-1);

	if (map_check_space(&check) == -1)
		return (-1);

	return (0);
}
