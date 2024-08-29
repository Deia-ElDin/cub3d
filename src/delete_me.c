/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_me.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:23:51 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/29 19:53:03 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_file(t_cub *cub)
{
	t_file	*file;

	file = &cub->file;
	printf("\n---------------------------------");
	printf("\n********* Printing File *********\n");
	printf("---------------------------------\n");
	printf("\nFile Length = %d\n\n", file->file_len);
	ft_printf(1, "%a\n", file->file_arr);
}

void	print_textures(t_cub *cub)
{
	t_txtrs	*txtrs;

	txtrs = &cub->txtrs;
	printf("\n-------------------------------------");
	printf("\n********* Printing Textures *********\n");
	printf("-------------------------------------\n");
	if (txtrs->no->img)
		printf("NO Path = %s\n", txtrs->no->img);
	if (txtrs->so->img)
		printf("SO Path = %s\n", txtrs->so->img);
	if (txtrs->we->img)
		printf("WE Path = %s\n", txtrs->we->img);
	if (txtrs->ea->img)
		printf("EA Path = %s\n", txtrs->ea->img);
	if (txtrs->c_arr[0] != -1)
		printf("C Colors = %d, %d, %d\n",
			txtrs->c_arr[0], txtrs->c_arr[1], txtrs->c_arr[2]);
	if (txtrs->f_arr[0] != -1)
		printf("F Colors = %d, %d, %d\n",
			txtrs->f_arr[0], txtrs->f_arr[1], txtrs->f_arr[2]);
	if (txtrs->c_color != -1)
		printf("C Color = %d\n", txtrs->c_color);
	if (txtrs->f_color != -1)
		printf("F Color = %d\n", txtrs->f_color);
}

void	print_map(t_cub *cub)
{
	t_map	*map;

	map = &cub->map;
	printf("\n--------------------------------");
	printf("\n********* Printing Map *********\n");
	printf("--------------------------------\n");
	printf("\nMap Width = %d\n", map->map_width);
	printf("\nMap Height = %d\n\n", map->map_height);
	ft_printf(1, "%a\n", map->map_arr);
}

void	print_player(t_cub *cub)
{
	t_player	*player;

	player = &cub->player;
	printf("\n-----------------------------------");
	printf("\n********* Printing Player *********\n");
	printf("-----------------------------------\n");
	printf("\nPlayer X = %f\n", player->plyr_x);
	printf("\nPlayer Y = %f\n", player->plyr_y);
	printf("\nPlayer Angle Degree = %.2f\n", (player->angle * (180 / M_PI)));
	printf("\nPlayer Angle Radius = %f\n", player->angle);
	printf("\nPlayer FOV = %f\n", player->fov_rd);
	printf("\nPlayer Rotation = %d\n", player->rot);
	printf("\nPlayer Left/Right = %d\n", player->l_r);
	printf("\nPlayer Up/Down = %d\n", player->u_d);
}
