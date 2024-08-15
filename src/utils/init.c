/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:33:53 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/15 23:05:44 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_cub *cub, char *input_file)
{
	cub->mlx = NULL;
	cub->win = NULL;
	cub->file.file_arr = NULL;
	cub->file.map_arr = NULL;
	cub->file.cpy_arr = NULL;
	cub->file.no_path = NULL;
	cub->file.so_path = NULL;
	cub->file.we_path = NULL;
	cub->file.ea_path = NULL;
	cub->file.filename_len = (int)ft_strlen(input_file);
	if(!cub->file.filename_len)
		exit_failure(cub, INVALID_FILE_NAME);
	cub->file.stage = 1;
	cub->file.file_len = 0;
	cub->file.is_valid_color = 0;
	cub->file.is_full_element = 0;
	cub->file.map_len = 0;
	cub->file.map_width = 0;
	cub->file.map_height = 0;
}

/*
	* cub->mlx = NULL;
		- we store the mlx pointer into that variable, we init it to NULL.
		
	* cub->win = NULL;
		- we store the window pointer into that variable, we init it to NULL.
		
	* cub->file.file_arr = NULL;
		- we store the whole file into that array.
	
	* cub->file.map_arr = NULL;
		- we store the map into that array.

	* cub->file.cpy_arr = NULL;
		- we store the copy of the map into that array.
		
	* cub->file.no_path = NULL;
		- we store the path of the north texture into that string.

	* cub->file.so_path = NULL;
		- we store the path of the south texture into that string.

	* cub->file.we_path = NULL;
		- we store the path of the west texture into that string.

	* cub->file.ea_path = NULL;
		- we store the path of the east texture into that string.

	* cub->file.f_color = NULL;
		- we store the floor color into that string.

	* cub->file.c_color = NULL;
		- we store the ceiling color into that string.

	* cub->file.filename_len = (int)ft_strlen(input_file);
		- we store the length of the input file name (the map).

	* cub->file.map_width = 0;
		- we store the width of the map.

	* cub->file.map_height = 0;
		- we store the height of the map.

	* cub->file.file_len = 0;
		- we store the length of the file (the given map).

	* cub->file.stage = 1;
		- we store the stage of the parsing process.
		- 1 for the elements.
		- 2 for the map.
		- we use it to validate if the map follows the right order.
*/

// cub->file.player = 0;
			// cub->file.res_x = 0;
	// cub->file.res_y = 0;