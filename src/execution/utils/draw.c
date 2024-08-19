/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:45:07 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/18 21:51:53 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	img_draw(t_vars *vars, char letter, int x, int y)
// {
// 	t_imgs	*imgs;
// 	void	*img;

// 	imgs = &vars->map.imgs;
// 	if (letter == 'P' || letter == 'r' || letter == 'l')
// 		imgs->player_prev_pos = letter;
// 	if (letter == '0')
// 		img = imgs->grass;
// 	else if (letter == '1')
// 		img = imgs->wall;
// 	else if (letter == 'C')
// 		img = imgs->collectable;
// 	else if (letter == 'E')
// 		img = imgs->exit;
// 	else if (letter == 'P' || letter == 'r')
// 		img = imgs->player_right;
// 	else if (letter == 'l')
// 		img = imgs->player_left;
// 	else
// 		img = NULL;
// 	if (!img)
// 		exit_error(&vars->map, IMG_ERR);
// 	mlx_put_image_to_window(vars->mlx, vars->win, img, x * PX, y * PX);
// }

void	map_draw_full(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if (map[y][x] != '1' && map[y][x] != '0')
				draw_img(vars, '0', x, y);
			draw_img(vars, map[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	map_draw_mini(char **map)
{
	int		x;
	int		y;
	char	*img;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			// draw_img(vars, map[y][x], x, y);
			mlx_put_image_to_window(vars->mlx, vars->win, img, x * PX, y * PX)
			x++;
		}
		y++;
	}
}

void    map_draw(t_cub *cub)
{
	// map_draw_full(vars);
	map_draw_mini(map);
}
