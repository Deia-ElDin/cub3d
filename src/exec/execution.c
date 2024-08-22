/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:23:50 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/22 20:38:23 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map_pixel(void *cub_ptr)
{
	t_cub	*cub;

	cub = cub_ptr;
	mlx_delete_image(cub->mlx, cub->img.img); // Assuming img is of type t_img
	cub->img.img = mlx_new_image(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	cub_hook(cub, 0, 0);
	cast_rays(cub);
	mlx_image_to_window(cub->mlx, cub->img.img, 0, 0);
}

int	checkload(t_txtr *list)
{
	t_txtr			*tmp;

	tmp = list;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, "NO", 2) || !ft_strncmp(tmp->key, "SO", 2) \
		|| !ft_strncmp(tmp->key, "WE", 2) || !ft_strncmp(tmp->key, "EA", 2))
		{
			if (tmp->value == NULL) // Ensure the value is valid
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	load_texture(t_texture *texture, t_txtr *l_ture)
{
	t_txtr	*tmp;

	tmp = l_ture;
	if (!checkload(l_ture))
		return (0);
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, "NO", 2))
			texture->no_img = mlx_load_png(tmp->value); // Assume textures are loaded here
		else if (!ft_strncmp(tmp->key, "SO", 2))
			texture->so_img = mlx_load_png(tmp->value);
		else if (!ft_strncmp(tmp->key, "WE", 2))
			texture->we_img = mlx_load_png(tmp->value);
		else if (!ft_strncmp(tmp->key, "EA", 2))
			texture->ea_img = mlx_load_png(tmp->value);
		tmp = tmp->next;
	}
	return (1);
}

void	get_angle(t_cub *cub)
{
	char	c;

	c = cub->map.map_arr[cub->map.plyr_counter][cub->map.plyr_counter];
	if (c == 'N')
		cub->player.angle = 3 * M_PI / 2;
	else if (c == 'S')
		cub->player.angle = M_PI / 2;
	else if (c == 'E')
		cub->player.angle = 0;
	else if (c == 'W')
		cub->player.angle = M_PI;
	cub->player.plyr_x = (cub->map.plyr_counter * TILE_SIZE) + TILE_SIZE / 2;
	cub->player.plyr_y = (cub->map.plyr_counter * TILE_SIZE) + TILE_SIZE / 2;
	cub->player.fov_rd = (FOV * M_PI / 180);
}

static void	init_mlx(t_cub *cub, t_img *img)
{
	cub->win = mlx_new_window(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!cub->win)
		exit_failure(cub, MLX_ERR);
	img->img = mlx_new_image(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!img->img)
		exit_failure(cub, MLX_ERR);
	img->addr = mlx_get_data_addr(
			img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	if (!img->addr)
		exit_failure(cub, MLX_ERR);
}

void	exec(t_cub *cub)
{
	t_file	*file;
	t_map	*map;
	t_texture	*texture;
	

	if (SCREEN_HEIGHT > 1440 || SCREEN_WIDTH > 2560 || FOV >= 180 || FOV <= 0)
		return (0);
	init_mlx(cub, img);
	get_angle(&cub);
	mlx_key_hook(cub.mlx, &key_press, &cub);
	mlx_loop_hook(cub.mlx, &draw_map_pixel, &cub);
	mlx_loop(cub.mlx);
}

