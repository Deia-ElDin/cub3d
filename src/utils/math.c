/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:27:58 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/21 14:05:22 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// double	degrees_to_radians(double degrees)
// {
// 	return (degrees * (M_PI / 180.0));
// }

void	calculate_angle(t_cub *cub, char direction)
{
	if (direction == 'N')
		cub->player.angle = M_PI / 2;
	else if (direction == 'S')
		cub->player.angle = 3 * M_PI / 2;
	else if (direction == 'E')
		cub->player.angle = 0;
	else if (direction == 'W')
		cub->player.angle = M_PI;
}

void	calculate_center(double x, double y, int *center_x, int *center_y)
{
    *center_x = (int)(x * MINI_TILE_SIZE + MINI_TILE_SIZE / 2);
    *center_y = (int)(y * MINI_TILE_SIZE + MINI_TILE_SIZE / 2);
}

void	calculate_deltas(t_player *player, int keycode, double *dx, double *dy)
{
	double	move_speed;

	move_speed = PLYR_SPEED / 50.0;
	if (keycode == 0)
	{
		*dx = player->plyr_x + cos(player->angle + M_PI_2) * move_speed;
		*dy = player->plyr_y - sin(player->angle + M_PI_2) * move_speed;
	}
	else if (keycode == 2)
	{
		*dx = player->plyr_x - cos(player->angle + M_PI_2) * move_speed;
		*dy = player->plyr_y + sin(player->angle + M_PI_2) * move_speed;
	}
	else if (keycode == 13)
	{
		*dx = player->plyr_x + cos(player->angle) * move_speed;
		*dy = player->plyr_y - sin(player->angle) * move_speed;
	}
	else if (keycode == 1)
	{
		*dx = player->plyr_x - cos(player->angle) * move_speed;
		*dy = player->plyr_y + sin(player->angle) * move_speed;
	}
}



/*
	*	void	calculate_center(int x, int y, int *center_x, int *center_y)
	{
		-	Purpose:
			The function finds the center of a specific tile on the map.

		-	Parameters:
			x: The x-coordinate of the tile (the start of the tile from the left).
			y: The y-coordinate of the tile (the start of the tile from the top).
			center_x: The address which we will set the x center to.
			center_y: The address which we will set the y center to.
			
		-	How It Works:
			1- Calculate Position: It multiplies the tile's x and y positions by the 
				tile size to get the top-left corner of the tile.
			2- Find Center: It adds half the tile size to these positions 
				to find the center of the tile.
			3- Output: The calculated center coordinates are stored in center_x and center_y.
	}
*/

