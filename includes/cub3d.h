/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:23:43 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/19 12:53:02 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"

// ******************** Constants ******************** //

# define SCREEN_HEIGHT 720
# define SCREEN_WIDTH 1280

// ********************* Errors ********************* //

# define INVALID_FD "Error\nFailed to open the file you provided.\n"
# define INVALID_FILE_NAME "Error\nInvalid file, kindly check the file name.\n"
# define INVALID_FILE_EMPTY "Error\nInvalid file, \
kindly provide us a file to work with.\n"
# define INVALID_FILE_NOT_COMPLETE "Error\nInvalid file, \
the file missing some elements or the map.\n"
# define INVALID_MAP "Error\nInvalid map, kindly check the map.\n"
# define MALLOC_ERR "Error\nFailed to malloc.\n"
# define READ_ERR "Error\nSomething went wrong with the read function, \
kindly try again later.\n"
# define ELEMENTS_ERR "Error\nInvalid elements.\n"
# define ELEMENTS_EXIST_ERR "Error\nInvalid elements. element already exist.\n"
# define ELEMENTS_SPACE_ERR "Error\nInvalid elements, \
invalid spaces within the image file name.\n"
# define ELEMENTS_IMG_NAME_ERR "Error\nInvalid elements, \
invalid image file name.\n"
# define ELEMENTS_IMG_CORRUPTED_ERR "Error\nInvalid elements, \
invalid image corrupted file.\n"
# define MAP_EMPTY_ERR "Error\nInvalid map, the map is empty.\n"
# define MAP_HEIGHT_ERR "Error\nInvalid map, the map is less than 3 lines.\n"
# define MAP_LINE_ERR "Error\nInvalid map, not a map line.\n"
# define MAP_EMPTY_LINE "Error\nInvalid map, \
the map can't be separated by one or more empty line(s).\n"
# define MAP_CHARS_ERR "Error\nInvalid map, invalid characters.\n"
# define MAP_SPACE_ERR "Error\nInvalid map, invalid spaces.\n"
# define MAP_WALL_ERR "Error\nInvalid map, not surrounded by walls.\n"
# define MLX_ERR "Error\nSomething went wrong with mlx lib, kindly try later.\n"
# define COLOR_ERR "Error\nInvalid color.\n"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_texture
{
	void	*no_img;
	void	*so_img;
	void	*we_img;
	void	*ea_img;
	int		f_array[2];
	int		c_array[2];
	int		f_color;
	int		c_color;
}	t_texture;

typedef struct s_map
{
	char	**map_arr;
	int		map_width;
	int		map_height;
	int		map_st;
	int		map_end;
	int		wall_counter;
	int		player_counter;
	char	player_position;
}	t_map;

typedef struct s_player
{
	int		plyr_x;
	int		plyr_y;
	double	angle;
	float	fov_rd;
	int		rot;
	int		l_r;
	int		u_d;
}	t_player;

typedef struct s_file
{
	char	**file_arr;
	char	**map;
	void	*no_path;
	void	*so_path;
	void	*we_path;
	void	*ea_path;
	int		c_color[3];
	int		f_color[3];
	int		filename_len;
	int		stage;
	int		file_len;
	int		is_valid_colors;
	int		map_st;
	int		map_end;
	int		map_width;
	int		map_height;
	int		wall_counter;
	int		player_counter;
	char	player_position;
}	t_file;

typedef struct s_cub
{
	void		*mlx;
	void		*win;
	t_file		file;
	t_texture	texture;
	t_map		map;
	t_player	player;
	t_img		img;
}	t_cub;

// ********************* PARSING ********************* //

void	parsing(t_cub *cub, char *input_file);

// ****************** PARSING UTILS ****************** //

// 		*	validate.c
void	validate_file(t_cub *cub, t_file *file);
// 		*	utils.c
int		is_color(t_cub *cub, char *line, int *color_idx, int *color_arr);
bool	is_elements_ready(t_file *file);
void	is_player(t_cub *cub, char *map_line);
void	set_map_width(t_file *file, char *map_line);
char	*set_map_line(t_cub *cub, t_file *file, char *map_line);

// ******************** EXECUTION ******************** //

void	execution(t_cub *cub);

// ******************** APP UTILS ******************** //

// 		*	exit.c
void	exit_failure(t_cub *cub, char *err_msg);
void	exit_success(t_cub *cub);
// 		*	init.c
void	init(t_cub *cub, char *input_file);
// 		*	utils.c
void	use_atoi(t_cub *cub, char *str_nbr, int *counter);

// *************************** DELETE ME *************************** //

void	print_elements(t_cub *cub);
void	print_map(t_cub *cub);

#endif
