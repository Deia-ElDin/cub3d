/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:23:43 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/17 23:11:17 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"

// Constants
// # define PX 50
// # define ELEMENTS_CHARS "01PNSEW\n "
# define MAP_CHARS " 01NSEW"
# define MIN_HEIGHT 3
# define MAX_HEIGHT 200
// # define FILE_EXTENSION ".cub"
// # define IMG_EXTENSION ".xpm"

// # define COUNTERS_CHARS "PCE"

typedef struct s_imgs
{
	void	*no_img;
	void	*so_img;
	void	*we_img;
	void	*ea_img;
	int		f_color;
	int		c_color;
}	t_imgs;

typedef struct s_map
{
	char	*line;
	int		len;
}	t_map;

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
	void	*mlx;
	void	*win;
	t_file	file;
	t_imgs	imgs;
}	t_cub;

// void	file_read(t_cub *cub, char *input_file, int len);
// // Images
// # define WALL_IMG "textures/wall.xpm"
// # define GRASS_IMG "textures/grass.xpm"
// # define PLAYER_RIGHT_IMG "textures/player_right.xpm"
// # define PLAYER_LEFT_IMG "textures/player_left.xpm"
// # define COLLECTABLES_IMG "textures/collectables.xpm"
// # define EXIT_IMG "textures/exit.xpm"

// // Errors
# define INVALID_FILE_NAME "Error\nInvalid file, kindly check the file name.\n"
# define INVALID_FD "Error\nFailed to open the file you provided.\n"
# define INVALID_FILE_EMPTY "Error\nKindly provide us a file to work with.\n"
# define INVALID_MAP "Error\nInvalid map, kindly check the map.\n"
# define MALLOC_ERR "Error\nFailed to malloc.\n"
# define READ_ERR "Error\nSomething went wrong with the read function, \
kindly try again later.\n"
# define ELEMENTS_ERR "Error\nInvalid elements."
# define MAP_ERR "Error\nInvalid map."
# define EMPTY_MAP_ERR "Error\nInvalid map, the map is empty."
# define MAP_HEIGHT_ERR "Error\nInvalid map, the map is either greater than \
200 lines or less than 3 lines."
# define MAP_LINE_ERR "Error\nInvalid map, not a map line."
# define SPACE_ERR "Error\nInvalid map, invalid spaces."
# define PLAYER_ERR "Error\nInvalid characters of player."
# define WALL_ERR "Error\nInvalid map, not surrounded by walls."
# define MLX_ERR "Error\nSomething went wrong with mlx lib, kindly try later.\n"
# define IMG_ERR "Error\nCorrupted image source file.\n"
# define COLOR_ERR "Error\nInvalid color.\n"

// # define INPUTS_ERR "Error\nInvalid inputs, \
// kindly provide us only 1 file to work with.\n"
// # define NO_FD_ERR "Error\nKindly provide us a file to work with.\n"
// # define LARGE_MAP_ERR "Error\nThe map is too large, \
// it doesn't make sense dude.\n"

// # define LEN_ERR "Error\nEach line of the map \
// can't be less than 4 characters.\n"
// # define LINES_ERR "Error\nThe map lines can't be of a different length.\n"
// # define WALL_ERR "Error\nThe map frame \
// must be all one's representing the wall.\n"
// # define NO_PLAYER_ERR "Error\nCan't start the game without a player!.\n"
// # define MORE_PLAYERS_ERR "Error\nCan't start the game \
// with more than 1 player!.\n"
// # define NO_EXIT_ERR "Error\nCan't start the game without an exit door!.\n"
// # define MORE_EXITS_ERR "Error\nCan't start the game \
// with more than 1 exit door!.\n"
// # define COLLECTABLES_ERR "Error\nCan't start the game \
// without some collectables!.\n"
// # define INVALID_CHAR_ERR "Error\nInvalid character.\n"
// # define SQR_MAP_ERR "Error\nThe map can't be square.\n"
// # define PATH_ERR "Error\nCan't reach either the exit or the collectables.\n"

// ********************* PARSING ********************* //

void	parsing(t_cub *cub, char *input_file);

// ****************** PARSING UTILS ****************** //

// 		*	validate.c
void	validate_file(t_cub *cub, t_file *file);
// 		*	utils.c
bool	is_elements_ready(t_file *file);
void	is_player(t_cub *cub, char *map_line);
void	set_map_width(t_file *file, char *map_line);
char	*set_map_line(t_cub *cub, t_file *file, char *map_line);
void	use_atoi(t_cub *cub, char *str_nbr, int *counter);

// ******************** APP UTILS ******************** //

// 		*	exit.c
void	exit_failure(t_cub *cub, char *err_msg);
void	exit_success(t_cub *cub);
// 		*	init.c
void	init(t_cub *cub, char *input_file);

// *************************** DELETE ME *************************** //
void	print_elements(t_cub *cub);
void	print_map(t_cub *cub);

#endif
