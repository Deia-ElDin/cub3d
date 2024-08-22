/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:23:50 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/22 20:43:36 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_cub *cub, int direction)
{
	if (direction == 1)
	{
		cub->player.angle += ROTATION_SPEED;
		if (cub->player.angle > 2 * M_PI)
			cub->player.angle -= 2 * M_PI;
	}
	else
	{
		cub->player.angle -= ROTATION_SPEED;
		if (cub->player.angle < 0)
			cub->player.angle += 2 * M_PI;
	}
}

void	move_player(t_cub *cub, double move_x, double move_y)
{
	int		map_grid_y;
	int		map_grid_x;
	int		new_x;
	int		new_y;

	new_x = round(cub->player.plyr_x + move_x);
	new_y = round(cub->player.plyr_y + move_y);
	map_grid_x = (new_x / TILE_SIZE);
	map_grid_y = (new_y / TILE_SIZE);
	if (cub->map.map_arr[map_grid_y][map_grid_x] != '1' && \
	(cub->map.map_arr[map_grid_y][cub->player.plyr_x / TILE_SIZE] != '1' && \
	cub->map.map_arr[cub->player.plyr_y / TILE_SIZE][map_grid_x] != '1'))
	{
		cub->player.plyr_x = new_x;
		cub->player.plyr_y = new_y;
	}
}

void	cub_hook(t_cub *cub, double move_x, double move_y)
{
	if (cub->player.rot == 1)
		rotate_player(cub, 1);
	if (cub->player.rot == -1)
		rotate_player(cub, 0);
	if (cub->player.l_r == 1)
	{
		move_x = -sin(cub->player.angle) * PLYR_SPEED;
		move_y = cos(cub->player.angle) * PLYR_SPEED;
	}
	if (cub->player.l_r == -1)
	{
		move_x = sin(cub->player.angle) * PLYR_SPEED;
		move_y = -cos(cub->player.angle) * PLYR_SPEED;
	}
	if (cub->player.u_d == 1)
	{
		move_x = cos(cub->player.angle) * PLYR_SPEED;
		move_y = sin(cub->player.angle) * PLYR_SPEED;
	}
	if (cub->player.u_d == -1)
	{
		move_x = -cos(cub->player.angle) * PLYR_SPEED;
		move_y = -sin(cub->player.angle) * PLYR_SPEED;
	}
	move_player(cub, move_x, move_y);
}

void	ft_reles(int keycode, t_cub *cub)
{
	if (keycode == 2) // 'D' key
		cub->player.l_r = 0;
	else if (keycode == 0) // 'A' key
		cub->player.l_r = 0;
	else if (keycode == 1) // 'S' key
		cub->player.u_d = 0;
	else if (keycode == 13) // 'W' key
		cub->player.u_d = 0;
	else if (keycode == 123) // Left Arrow key
		cub->player.rot = 0;
	else if (keycode == 124) // Right Arrow key
		cub->player.rot = 0;
}


void	key_press(int keycode, t_cub *cub)
{
	if (keycode == 53) // Escape key
	{
		exit_success(cub);
	}
	else if (keycode == 0) // 'A' key
		cub->player.l_r = -1;
	else if (keycode == 2) // 'D' key
		cub->player.l_r = 1;
	else if (keycode == 1) // 'S' key
		cub->player.u_d = -1;
	else if (keycode == 13) // 'W' key
		cub->player.u_d = 1;
	else if (keycode == 123) // Left Arrow key
		cub->player.rot = -1;
	else if (keycode == 124) // Right Arrow key
		cub->player.rot = 1;
	ft_reles(keycode, cub);
}

