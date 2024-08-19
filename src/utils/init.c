/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:33:53 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/19 12:50:20 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_texture(t_texture *texture)
{
	texture->no_img = NULL;
	texture->so_img = NULL;
	texture->we_img = NULL;
	texture->ea_img = NULL;
	texture->f_color = -1;
	texture->c_color = -1;
}

static void	init_map(t_map *map)
{
	map->map_arr = NULL;
	map->map_width = -1;
	map->map_height = -1;
	map->wall_counter = -1;
	map->map_st = -1;
	map->map_end = -1;
	map->player_counter = -1;
	map->player_position = '\0';
}

static void	init_player(t_player *player)
{
	player->plyr_x = -1;
	player->plyr_y = -1;
	player->angle = -1;
	player->fov_rd = -1;
	player->rot = -1;
	player->l_r = -1;
	player->u_d = -1;
}

static void	init_file(t_file *file, char *input_file)
{
	file->file_arr = NULL;
	cub->file.filename_len = (int)ft_strlen(input_file);
	cub->file.file_len = 0;
	cub->file.stage = 1;
}

void	init(t_cub *cub, char *input_file)
{
	cub->mlx = NULL;
	cub->win = NULL;
	cub->file.file_arr = NULL;
	cub->file.map = NULL;
	cub->file.no_path = NULL;
	cub->file.so_path = NULL;
	cub->file.we_path = NULL;
	cub->file.ea_path = NULL;
	cub->file.filename_len = (int)ft_strlen(input_file);
	cub->file.file_len = 0;
	cub->file.stage = 1;
	cub->file.is_valid_colors = 0;
	cub->file.map_st = 0;
	cub->file.map_end = 0;
	cub->file.map_width = 0;
	cub->file.map_height = 0;
	cub->file.wall_counter = 0;
	cub->file.player_counter = 0;
	cub->file.player_position = '\0';
	// cub->img = NULL;

	init_texture(&cub->texture);
	init_map(&cub->map);
	init_player(&cub->player);
	// init_file(&cub->file, input_file);
}

/*
	*	init(t_cub *cub, char *input_file)
	{
		-	cub->mlx = NULL;
			used to store the mlx pointer into that variable, we init it to NULL.
		-	cub->win = NULL;
			used to store the window pointer into that variable,
			we init it to NULL.
			
		-	cub->file.file_arr = NULL;
			used to store the whole file into that array.
		-	cub->file.map = NULL;
			used to store the map into that array.
			
		-	cub->file.no_path = NULL;
			used to store the path of the north texture into that string.
		-	cub->file.so_path = NULL;
			used to store the path of the south texture into that string.
		-	cub->file.we_path = NULL;
			used to store the path of the west texture into that string.
		-	cub->file.ea_path = NULL;
			used to store the path of the east texture into that string.
			
		-	cub->file.filename_len = (int)ft_strlen(input_file);
			used to store the length of the input file name (the map).

		-	cub->file.file_len = 0;
			used to store the length of the file
			(the given map, not the filename).
			
		-	cub->file.stage = 1;
			used to store the stage of the parsing process.
			- 1 for the elements.
			- 2 for the map.
			- we use it to validate if the map follows the right order.
			
		-	cub->file.is_valid_colors = 0;
			used to store the number of valid colors we parsed.
			
		-	cub->file.map_st = 0;
			used to store the start of the map.
		-	cub->file.map_end = 0;
			used to store the end of the map.
		-	cub->file.map_width = 0;
			used to store the width of the map.
		-	cub->file.map_height = 0;
			used to store the height of the map.
		-	cub->file.wall_counter = 0;
			used to store the number of walls in the map.
		-	cub->file.player_counter = 0;
			used to store the number of players in the map.
		-	cub->file.player_position = '\0';
			used to store the position of the player in the map.
	}
*/
