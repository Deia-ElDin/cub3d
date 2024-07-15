/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:23:43 by dehamad           #+#    #+#             */
/*   Updated: 2024/07/15 14:37:20 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"

// Constants
// # define PX 50
# define FILE_EXTENSION ".cub"
# define ALLOWED_CHARS "01PNSEW\n "
// # define COUNTERS_CHARS "PCE"

typedef struct s_file
{
    char    **file;
    char    **map;
    char    **cpy; 
}	t_file;

typedef struct s_cub
{
    void	*mlx;
	void	*win;
    t_file  file;
} t_cub;


void    parsing(t_cub *cub, char *input_file);

// // Images
// # define WALL_IMG "textures/wall.xpm"
// # define GRASS_IMG "textures/grass.xpm"
// # define PLAYER_RIGHT_IMG "textures/player_right.xpm"
// # define PLAYER_LEFT_IMG "textures/player_left.xpm"
// # define COLLECTABLES_IMG "textures/collectables.xpm"
// # define EXIT_IMG "textures/exit.xpm"

// // Errors
// # define INPUTS_ERR "Error\nInvalid inputs, \
// kindly provide us only 1 file to work with.\n"
// # define NO_FD_ERR "Error\nKindly provide us a file to work with.\n"
// # define INVALID_FD_NAME "Error\nInvalid file, kindly check the file name.\n"
// # define EMPTY_MAP_ERR "Error\nKindly provide us a map to work with.\n"
// # define LARGE_MAP_ERR "Error\nThe map is too large, \
// it doesn't make sence dude.\n"
// # define FD_ERR "Error\nFailed to read the file you provided.\n"
// # define MALLOC_ERR "Error\nFailed to malloc the map array.\n"
// # define READ_ERR "Error\nSomething went wrong with the read function, \
// kindly try again later.\n"
// # define MLX_ERR "Error\nSomething went wrong with mlx lib, kindly try later.\n"
// # define LEN_ERR "Error\nEach line of the map \
// can't be less than 4 characters.\n"
// # define LINES_ERR "Error\nThe map lines can't be of a different length.\n"
// # define WALL_ERR "Error\nThe map frame \
// must be all one's reprsenting the wall.\n"
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
// # define IMG_ERR "Error\nCorrupted image source file.\n"
// # define PATH_ERR "Error\nCan't reach either the exit or the collectables.\n"


#endif
