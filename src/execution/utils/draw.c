/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:45:07 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/21 14:06:13 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = 0;
		while (j < SCREEN_HEIGHT)
		{
			my_mlx_pixel_put(img, i, j, 0xC0C0C0);
			j++;
		}
		i++;
	}
}

void	draw_floor(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = SCREEN_HEIGHT / 2;
		while (j < SCREEN_HEIGHT)
		{
			my_mlx_pixel_put(img, i, j, 0x000080);
			j++;
		}
		i++;
	}
}

void	draw_tile(t_img *img, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	x *= MINI_TILE_SIZE;
	y *= MINI_TILE_SIZE;
	while (i < (MINI_TILE_SIZE - 1))
	{
		j = 0;
		while (j < (MINI_TILE_SIZE - 1))
		{
			my_mlx_pixel_put(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_border(t_img *img, int width, int height)
{
	int	i;

	i = 0;
	width *= MINI_TILE_SIZE;
	height *= MINI_TILE_SIZE;
	while (i < width)
	{
		my_mlx_pixel_put(img, i, 0, 0xFF0000);
		my_mlx_pixel_put(img, i, height - 1, 0xFF0000);
		i++;
	}
	i = 0;
	while (i < height)
	{
		my_mlx_pixel_put(img, 0, i, 0xFF0000);
		my_mlx_pixel_put(img, width - 1, i, 0xFF0000);
		i++;
	}
}

void	draw_line(t_img *img, int x, int y, double angle, int len)
{
    int i;
    double dx;
    double dy;
	int px;
	int py;
	
	i = -1;
	dx = cos(angle);
	dy = -sin(angle);
    while (++i < len)
	{
        px = x + i * dx;
        py = y + i * dy;
        my_mlx_pixel_put(img, px, py, BLACK); 
    }
}

void draw_player(t_img *img, double x, double y, double angle)
{
    int i = 0;
    int j;
    int size = MINI_TILE_SIZE / 6;
    int center_x, center_y;

    calculate_center(x, y, &center_x, &center_y);
    while (i < size) {
        j = 0;
        while (j < size)
		{
            my_mlx_pixel_put(img, center_x + i - size / 2, center_y + j - size / 2, RED);
            j++;
        }
        i++;
    }
    draw_line(img, center_x, center_y, angle, 10);
}

void	draw_map_mini(t_player *player, t_map *map, t_img *img)
{
	char	**map_arr;
	int		x;
	int		y;
	int		player_x;
	int		player_y;

	y = 0;
	map_arr = map->map_arr;
	player_x = round(player->plyr_x);
	player_y = round(player->plyr_y);
	
	while (map_arr[y])
	{
		x = 0;
		while (map_arr[y][x])
		{
			if (map_arr[y][x] == '1')
				draw_tile(img, x, y, GRAY);
			else if (map_arr[y][x] == ' ')
				draw_tile(img, x, y, BLACK);
			else
				draw_tile(img, x, y, WHITE);
			x++;
		}
		y++;
	}
	draw_player(img, player->plyr_x, player->plyr_y, player->angle);
	draw_border(img, map->map_width, map->map_height);
}

int	draw_map(t_cub *cub)
{
	t_img		*img;
	t_player	*player;

	img = &cub->img;
	player = &cub->player;
	// print_map(cub);
	draw_ceiling(img);
	draw_floor(img);
	draw_map_mini(player, &cub->map, img);
	mlx_put_image_to_window(cub->mlx, cub->win, img->img, 0, 0);
	return (0);
}



// void	draw_player(t_img *img, int x, int y, double angle)
// {
// 	int	i;
// 	int	j;
// 	int	size;
// 	int center_x;
// 	int center_y;
	
// 	i = 0;
// 	size = MINI_TILE_SIZE / 3; // 30 / 3 = 10
// 	calculate_center(x, y, &center_x, &center_y);
// 	draw_tile(img, x, y, 0xFFFFFF);
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			my_mlx_pixel_put(img, center_x + i - size / 2, center_y + j - size / 2, RED);
// 			j++;
// 		}
// 		i++;
// 	}
// 	draw_line(img, center_x, center_y, angle, 10);
// }


// void	draw_map(t_cub *cub, t_map *map, t_img *img)
// {
// 	char	**map_arr;
// 	int		x;
// 	int		y;

// 	y = 0;
// 	map_arr = map->map_arr;
// 	draw_ceiling(img);
// 	draw_floor(img);
// 	while (map_arr[y])
// 	{
// 		x = 0;
// 		while (map_arr[y][x])
// 		{
// 			if (map_arr[y][x] == '1')
// 				draw_tile(img, x * TILE_SIZE, y * TILE_SIZE, 0x00FFFFFF);
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_put_image_to_window(cub->mlx, cub->win, img->img, 0, 0);
// }


/*
x * MINI_TILE_SIZE: This gives you the top-left corner of the tile where the player is located.

(MINI_TILE_SIZE - size) / 2: This centers the player within the tile by calculating the offset required to position the smaller player square (size) within the larger tile (MINI_TILE_SIZE).
x + size / 2
*/

