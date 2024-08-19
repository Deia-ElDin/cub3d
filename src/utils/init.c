/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:33:53 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/19 15:16:30 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_file(t_file *file, char *input_file)
{
	file->file_arr = NULL;
	file->filepath_len = (int)ft_strlen(input_file);
	file->file_len = 0;
	file->stage = 1;
}

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
	map->map_width = 0;
	map->map_height = 0;
	map->map_st = 0;
	map->map_end = 0;
	map->wall_counter = 0;
	map->player_counter = 0;
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

void	init(t_cub *cub, char *input_file)
{
	cub->mlx = NULL;
	cub->win = NULL;
	init_file(&cub->file, input_file);
	init_texture(&cub->texture);
	init_map(&cub->map);
	init_player(&cub->player);
}

/*
	*	void	init(t_cub *cub, char *input_file)
	{
		-	cub->mlx = NULL;
			used to store the mlx pointer into that variable, we init it to NULL.
		-	cub->win = NULL;
			used to store the window pointer into that variable,
			we init it to NULL.
		-	init_file(&cub->file, input_file);
			used to init the file struct.
		-	init_texture(&cub->texture);
			used to init the texture struct.
		-	init_map(&cub->map);
			used to init the map struct.
		-	init_player(&cub->player);
			used to init the player struct.
	}
	
	*	static void	init_file(t_file *file, char *input_file)
	{
		-	file->file_arr = NULL;
			used to store the whole file into that array.
		-	file->filepath_len = (int)ft_strlen(input_file);
			used to store the length of the input file path (the given map).
		-	file->file_len = 0;
			used to store the length of the file, (the given elements & map).
		-	file->stage = 1;
			used to store the stage of the parsing process.
			- 1 for the elements.
			- 2 for the map.
			- we use it to validate if the map follows the right order.
	}

	*	static void	init_texture(t_texture *texture)
	{
		-	texture->no_img = NULL;
			used to store the north texture into that variable.
		-	texture->so_img = NULL;
			used to store the south texture into that variable.
		-	texture->we_img = NULL;
			used to store the west texture into that variable.
		-	texture->ea_img = NULL;
			used to store the east texture into that variable.
		-	texture->f_color = -1;
			used to store the floor color into that variable.
		-	texture->c_color = -1;
			used to store the ceiling color into that variable.
	}
	
	*	static void	init_map(t_map *map)
	{
		-	map->map_arr = NULL;
			used to store the map into that array.
		-	map->map_width = 0;
			used to store the width of the map.
		-	map->map_height = 0;
			used to store the height of the map.
		-	map->map_st = 0;
			used to store the starting index of the map.
		-	map->map_end = 0;
			used to store the ending index of the map.
		-	map->wall_counter = 0;
			used to store the number of walls in the map.
		-	map->player_counter = 0;
			used to store the number of players in the map.
		-	map->player_position = '\0';
			used to store the position of the player in the map.
	}

	*	static void	init_player(t_player *player)
	{
		-	player->plyr_x = -1;
			used to store the x position of the player.
		-	player->plyr_y = -1;
			used to store the y position of the player.
		-	player->angle = -1;
			used to store the angle of the player.
		-	player->fov_rd = -1;
			used to store the field of view of the player.
		-	player->rot = -1;
			used to store the rotation of the player.
		-	player->l_r = -1;
			used to store the left right movement of the player.
		-	player->u_d = -1;
			used to store the up down movement of the player.
	}
*/
