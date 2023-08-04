/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:29:50 by jlim              #+#    #+#             */
/*   Updated: 2022/03/08 13:29:50 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
