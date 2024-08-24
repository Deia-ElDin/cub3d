/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:33:53 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/18 16:07:41 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
