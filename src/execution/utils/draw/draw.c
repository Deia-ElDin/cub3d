/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:45:07 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/22 20:21:10 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling_floor(t_texture *texture, t_img *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SCREEN_WIDTH)
	{
		j = -1;
		while (++j < SCREEN_HEIGHT / 2)
			my_mlx_pixel_put(img, i, j, texture->c_color);
		while (++j < SCREEN_HEIGHT)
			my_mlx_pixel_put(img, i, j, texture->f_color);
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

void	draw_line(t_img *img, t_map *map, int x, int y, double angle, int len, int color)
{
    int 	i;
    double 	dx;
    double 	dy;
	int 	px;
	int 	py;
	
	i = -1;
	dx = cos(angle);
	dy = -sin(angle);
    while (++i < len)
	{
        px = x + i * dx;
        py = y + i * dy;
		int	map_x = ft_abs(px / MINI_TILE_SIZE);
		int	map_y = ft_abs(py / MINI_TILE_SIZE);
		if (map_x >= 0 && map_y >= 0
			&& map_x <= map->map_width
			&& map_y < map->map_height
			&& map->map_arr[map_y][map_x]
			&& map->map_arr[map_y][map_x] != '1'
			&& map->map_arr[map_y][map_x] != ' ')
			my_mlx_pixel_put(img, px, py, color); 
		else
			break;
    }
}

void	draw_rays(t_img *img, t_map *map, double x, double y, double angle)
{
	double	st_angle = (angle * (180 / M_PI)) - 30;
	double	end_angle = (angle * (180 / M_PI)) + 30;

	while (st_angle < end_angle)
	{
		draw_line(img, map, round(x), round(y), (st_angle * (M_PI / 180)), map->map_width * MINI_TILE_SIZE, YELLOW);
		st_angle += 2;
	
	}
}

void	draw_player(t_player *player, t_map *map, t_img *img)
{
    int i = 0;
    int j;
    int size = MINI_TILE_SIZE / 6;
    int center_x, center_y;

    calculate_center(player->plyr_x, player->plyr_y, &center_x, &center_y);
    while (i < size)
	{
        j = 0;
        while (j < size)
		{
            my_mlx_pixel_put(img, center_x + i - size / 2, center_y + j - size / 2, RED);
            j++;
        }
        i++;
    }
    draw_line(img, map, center_x, center_y, player->angle, 10, BLACK);
	draw_rays(img, map, center_x, center_y, player->angle);
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
}

int	draw_map(t_cub *cub)
{
	t_texture	*texture;
	t_player	*player;
	t_map		*map;
	t_img		*img;

	texture = &cub->texture;
	player = &cub->player;
	map = &cub->map;
	img = &cub->img;
	draw_ceiling_floor(texture, img);
	draw_map_mini(player, map, img);
	draw_player(player, map, img);
	mlx_put_image_to_window(cub->mlx, cub->win, img->img, 0, 0);
	return (0);
}

// float calculate_distance(t_player *player, float ray_angle, float distance)
// {
//     // Correct the fisheye effect by using the difference between the player's angle and the ray's angle
//     return distance * cos(ray_angle - player->angle);
// }

// void render_wall_slice(t_img *img, int ray_x, float distance, t_texture *texture)
// {
//     int wall_height;
//     int draw_start;
//     int draw_end;

//     wall_height = (int)(SCREEN_HEIGHT / distance); // Calculate wall height
//     draw_start = -wall_height / 2 + SCREEN_HEIGHT / 2; // Center the wall slice vertically
//     draw_end = wall_height / 2 + SCREEN_HEIGHT / 2;

//     if (draw_start < 0)
//         draw_start = 0;
//     if (draw_end >= SCREEN_HEIGHT)
//         draw_end = SCREEN_HEIGHT - 1;

//     // Draw the wall slice
//     for (int y = draw_start; y < draw_end; y++)
//     {
//         my_mlx_pixel_put(img, ray_x, y, texture->f_color); // Replace with actual texture color
//     }
// }

// float normalize_angle(float angle)
// {
//     angle = fmod(angle, 2 * M_PI);
//     if (angle < 0)
//         angle += 2 * M_PI;
//     return angle;
// }


// float cast_single_ray(t_cub *cub, float ray_angle)
// {
//     float h_dist;  // Distance to the nearest horizontal intersection
//     float v_dist;  // Distance to the nearest vertical intersection

//     // Normalize the ray angle
//     ray_angle = normalize_angle(ray_angle);

//     // Calculate the horizontal and vertical intersections
//     h_dist = get_h_inter(cub, ray_angle);  // Get horizontal intersection distance
//     v_dist = get_v_inter(cub, ray_angle);  // Get vertical intersection distance

//     // Return the shortest distance (either horizontal or vertical intersection)
//     return (v_dist < h_dist) ? v_dist : h_dist;
// }

// void cast_rays_3d(t_cub *cub)
// {
//     int ray_x;
//     float ray_angle;
//     float distance;
//     float corrected_distance;

//     ray_angle = cub->player.angle - (cub->player.fov_rd / 2); // Start with the leftmost ray
//     for (ray_x = 0; ray_x < SCREEN_WIDTH; ray_x++)
//     {
//         // Cast the ray and calculate the distance to the wall
//         distance = cast_single_ray(cub, ray_angle); // This function will calculate the intersection with the wall

//         // Correct the distance to avoid fisheye effect
//         corrected_distance = calculate_distance(&cub->player, ray_angle, distance);

//         // Render the wall slice
//         render_wall_slice(&cub->img, ray_x, corrected_distance, &cub->texture);

//         // Move to the next angle
//         ray_angle += cub->player.fov_rd / SCREEN_WIDTH;
//     }
// }

// int draw_map(t_cub *cub)
// {
//     t_texture *texture;
//     t_img *img;

//     texture = &cub->texture;
//     img = &cub->img;

//     draw_ceiling_floor(texture, img); // This function can be reused to draw the ceiling and floor colors

//     // Cast rays and render the scene in 3D
//     cast_rays_3d(cub);

//     mlx_put_image_to_window(cub->mlx, cub->win, img->img, 0, 0);
//     return (0);
// }


// void	draw_border(t_img *img, int width, int height)
// {
// 	int	i;

// 	i = 0;
// 	width *= MINI_TILE_SIZE;
// 	height *= MINI_TILE_SIZE;
// 	while (i < width)
// 	{
// 		my_mlx_pixel_put(img, i, 0, 0xFF0000);
// 		my_mlx_pixel_put(img, i, height - 1, 0xFF0000);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < height)
// 	{
// 		my_mlx_pixel_put(img, 0, i, 0xFF0000);
// 		my_mlx_pixel_put(img, width - 1, i, 0xFF0000);
// 		i++;
// 	}
// }

// void draw_ray(t_img *img, t_player *player, float angle)
// {
//     float end_x;
//     float end_y;
// 	int	len = 200;

//     // Calculate the end position of the ray based on the angle and length
//     end_x = player->plyr_x + cos(angle) * len;
//     end_y = player->plyr_y + sin(angle) * len;
	
// 	// printf("we are drawing ray\n");
//     // Draw the line from the player's position to the end of the ray
//     draw_line(img, round(player->plyr_x), round(player->plyr_y), angle, len, GRAY);
// }


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

