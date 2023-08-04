/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:29:45 by jlim              #+#    #+#             */
/*   Updated: 2022/03/08 13:29:46 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_print(t_map **map_ptr)
{
	t_map	*line;

	line = *map_ptr;
	while (line)
	{
		printf("%s\n", line->line);
		if (line->next)
			line = line->next;
		else
			break ;
	}
}