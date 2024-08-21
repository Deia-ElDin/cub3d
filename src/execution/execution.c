/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:33:41 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/20 22:57:13 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	execution(t_cub *cub)
{
	t_map	*map;
	t_img	*img;

	map = &cub->map;
	img = &cub->img;
	// print_player(cub);
	// print_map(cub);
	init_mlx(cub, img);
	mlx_hook(cub->win, ON_DESTROY, 0, exit_success, cub);
	mlx_hook(cub->win, ON_KEYDOWN, 0, movement, cub);
	mlx_loop_hook(cub->mlx, draw_map, cub);
	mlx_loop(cub->mlx);
}


// static void	update_player(t_cub *cub)
// {
// 	t_map		*map;
// 	t_player	*player;
// 	char		**map_arr;
// 	int			y;
// 	int			x;

// 	map = &cub->map;
// 	player = &cub->player;
// 	map_arr = map->map_arr;
// 	y = 0;
// 	x = 0;
// 	while (map_arr[y])
// 	{
// 		x = 0;
// 		while (map_arr[y][x])
// 		{
// 			if (ft_strchr("NSWE", map_arr[y][x]))
// 			{
// 				// player->plyr_x = (j * MINI_TILE_SIZE) + (MINI_TILE_SIZE / 2);
// 				// player->plyr_y = (i * MINI_TILE_SIZE) + (MINI_TILE_SIZE / 2);
// 				player->plyr_y = y;
// 				player->plyr_x = x;
// 				player->plyr_dir = map_arr[y][x];
// 				// map_arr[y][x] = '0';
// 				return ;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }