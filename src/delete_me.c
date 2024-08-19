/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_me.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:23:51 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/19 15:08:09 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_file(t_cub *cub)
{
	t_file	*file;

	file = &cub->file;
	ft_printf(1, "\n---------------------------------");
	ft_printf(1, "\n********* Printing File *********\n");
	ft_printf(1, "---------------------------------\n");
	ft_printf(1, "\nFile Length = %d\n\n", file->file_len);
	ft_printf(1, "%a\n", file->file_arr);
}

void	print_textures(t_cub *cub)
{
	t_texture	*texture;

	texture = &cub->texture;
	ft_printf(1, "\n-------------------------------------");
	ft_printf(1, "\n********* Printing Textures *********\n");
	ft_printf(1, "-------------------------------------\n");
	if (texture->no_img)
		ft_printf(1, "NO Path = %s\n", texture->no_img);
	if (texture->so_img)
		ft_printf(1, "SO Path = %s\n", texture->so_img);
	if (texture->we_img)
		ft_printf(1, "WE Path = %s\n", texture->we_img);
	if (texture->ea_img)
		ft_printf(1, "EA Path = %s\n", texture->ea_img);
	if (texture->c_arr[0] != -1)
		ft_printf(1, "C Colors = %d, %d, %d\n",
			texture->c_arr[0], texture->c_arr[1], texture->c_arr[2]);
	if (texture->f_arr[0] != -1)
		ft_printf(1, "F Colors = %d, %d, %d\n",
			texture->f_arr[0], texture->f_arr[1], texture->f_arr[2]);
	if (texture->c_color != -1)
		ft_printf(1, "C Color = %d\n", texture->c_color);
	if (texture->f_color != -1)
		ft_printf(1, "F Color = %d\n", texture->f_color);
}

void	print_map(t_cub *cub)
{
	t_map	*map;

	map = &cub->map;
	ft_printf(1, "\n--------------------------------");
	ft_printf(1, "\n********* Printing Map *********\n");
	ft_printf(1, "--------------------------------\n");
	ft_printf(1, "\nMap Width = %d\n", map->map_width);
	ft_printf(1, "\nMap Height = %d\n\n", map->map_height);
	ft_printf(1, "%a\n", map->map_arr);
}
