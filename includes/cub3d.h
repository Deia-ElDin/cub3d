/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:23:43 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/15 22:37:33 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"

// Constants
// # define PX 50
// # define ELEMENTS_CHARS "01PNSEW\n "
# define MAP_CHARS "01NSEW\n "
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

typedef struct s_file
{
	char	**file_arr;
	char	**map_arr;
	char	**cpy_arr;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	// char	*s_path;
	int		c_color[3];
	int		f_color[3];
	int		is_valid_color;
	int		is_full_element;
	int		map_width;
	int		map_height;
	int		filename_len;
	int		file_len;
	int		stage;
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


// ********************* parsing ********************* //

void	parsing(t_cub *cub, char *input_file);

// ****************** PARSING UTILS ****************** //

// **	FILE FOLDER
// 		*	file.c
void	file(t_cub *cub, char *input_file);
// 		*	utils.c
bool	is_element_line(char *line);
bool	is_map_line(char *line);
bool	is_elements_ready(t_file *file);
void	validate_color(t_cub *cub, int *color_arr, char *line);

// ******************** APP UTILS ******************** //

// 		*	exit.c
void	exit_failure(t_cub *cub, char *err_msg);
void	exit_success(t_cub *cub);
// 		*	init.c
void	init(t_cub *cub, char *input_file);
// 		*	img.c
char	*validate_img(t_cub *cub, char *line);

// DELETE ME
void	print_file_paths(t_cub *cub);

#endif
