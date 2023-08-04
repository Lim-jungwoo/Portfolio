/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:45:33 by jlim              #+#    #+#             */
/*   Updated: 2022/03/08 11:45:36 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "./minilibx_opengl_20191021/mlx.h"

# include <stdio.h>
# include <fcntl.h>

# define NOT_ARGUMENT "./cub3d map\n"
# define OPEN_FAIL "file open fail\n"
# define CLOSE_FAIL "file close fail\n"
# define INVALID_MAP "map is invalid\n"
# define GNL_FAIL "get next line fail\n"
# define READ_FAIL "file read fail\n"
# define MALLOC_FAIL "malloc fail\n"
# define NO_WALL "map is not surrounded by wall\n"

typedef struct s_map	t_map;
struct	s_map
{
	char	*line;
	t_map	*next;
	t_map	*prev;
};

typedef struct s_flag	t_flag;
struct	s_flag
{
	int		NO_flag;
	int		SO_flag;
	int		WE_flag;
	int		EA_flag;
	int		F_flag;
	int		C_flag;
};

/*
typedef struct s_mlx	t_mlx;
struct	s_mlx
{
	t_map	*map;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_ptr;
	void	*sprit1_ptr;
	void	*sprit2_ptr;
	void	*sprit3_ptr;
	void	*sprit4_ptr;
	char	*img;
	char	*sprit1;
	char	*sprit2;
	char	*sprit3;
	char	*sprit4;
	int		size_square;
	int		width;
	int		height;
	int		size_line;
	int		bpp;
	int		endian;
	//int		move_count;
};*/

//parse.c
int	get_next_line(const int fd, char **line);
int	add_line_to_map(char *line, t_map **map_ptr);
int	parse_gnl(t_map **map_ptr, const int fd);
int	parse_map(t_map **map_ptr, const char *map_file);

//map.c
int		map_width(t_map **map_ptr);
int		map_height(t_map **map_ptr);

//map_check.c
int	map_check(t_map **map_ptr);
int	map_check_empty(t_map **map_ptr);

//map_check_wall.c
int	map_check_first_ch(t_map **map_ptr);
int	map_check_end_ch(t_map **map_ptr);
int	map_check_first_line(t_map **map_ptr);
int	map_check_end_line(t_map **map_ptr);

//map_check_character.c
int	map_check_character(t_map **map_ptr);

//map_check_nsew.c
void	init_nsew_flag(t_flag *nsew_flag);
int	map_check_identifier(t_map **map_ptr);

//print.c
void	map_print(t_map **map_ptr);

//clear.c
void	map_clear(t_map **map_ptr);

# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ESC_KEY 53
# define FONT_COLOR 0x000E3B81

#endif