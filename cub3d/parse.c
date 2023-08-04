/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:33:43 by jlim              #+#    #+#             */
/*   Updated: 2022/03/08 13:33:44 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_next_line(const int fd, char **line)
{//read함수는 실패했을 때 -1, EOF를 읽으면 0을 리턴, 성공했으면 양수
//성공했을 때 1 리턴, 실패하면 -1 리턴
	ssize_t	ret;
	char	*str;
	char	*tmp;
	char	buf[2];

	ret = read(fd, buf, 1);
	if (ret < 0)
	{//READ를 실패했을 때 에러 메시지를 출력하고 -1을 리턴
		printf(READ_FAIL);
		return (-1);
	}
	if (ret == 0)
		return (0);
	buf[1] = '\0';
	str = ft_strdup("");
	if (str == NULL)
	{
		printf(MALLOC_FAIL);
		return (-1);
	}
	while (ret > 0 && buf[0] != '\n')
	{
		tmp = str;
		str = ft_strjoin(tmp, buf);
		if (str == NULL)
		{
			printf(MALLOC_FAIL);
			free(tmp);
			return (-1);
		}
		free(tmp);
		ret = read(fd, buf, 1);
	}
	*line = str;
	return (1);
}

int	add_line_to_map(char *line, t_map **map_ptr)
{//성공했을 때 0 리턴, 실패했을 때 -1 리턴
	t_map	*ptr;

	if (*map_ptr == NULL)
	{
		*map_ptr = malloc(sizeof(t_map));
		if (*map_ptr == NULL)
		{
			printf(MALLOC_FAIL);
			return (-1);
		}
		(*map_ptr)->line = line;
		(*map_ptr)->next = NULL;
		(*map_ptr)->prev = NULL;
	}
	else
	{
		ptr = *map_ptr;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = malloc(sizeof(t_map));
		if (ptr->next == NULL)
		{
			printf(MALLOC_FAIL);
			return (-1);
		}
		ptr->next->line = line;
		ptr->next->next = NULL;
		ptr->next->prev = ptr;
	}
	return (0);
}

int	parse_gnl(t_map **map_ptr, const int fd)
{
	int		ret_gnl;
	int		ret_add_line;
	char	*line;

	line = NULL;
	ret_gnl = get_next_line(fd, &line);
	ret_add_line = 0;
	while (ret_gnl > 0 && ret_add_line == 0)
	{
		ret_add_line = add_line_to_map(line, map_ptr);
		line = NULL;
		ret_gnl = get_next_line(fd, &line);
	}
	if (ret_gnl < 0)
	{
		printf(GNL_FAIL);
		return (-1);
	}
	if (ret_add_line < 0)
	{
		printf(GNL_FAIL);
		return (-1);
	}
	return (0);
}

int	parse_map(t_map **map_ptr, const char *map_file)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		printf(OPEN_FAIL);
		return (-1);
	}
	if (parse_gnl(map_ptr, fd) == -1)
		return (-1);
	if (close(fd))
	{
		printf(CLOSE_FAIL);
		return (-1);
	}
	if (map_check(map_ptr) == -1)
		return (-1);
	return (0);
}