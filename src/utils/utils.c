/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:58:17 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/29 16:17:42 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	use_atoi(t_cub *cub, char *str_nbr, int *counter)
{
	t_atoi	res;
	int		nbr;

	if (!str_nbr || !*str_nbr)
		return (exit_failure(cub, COLOR_ERR));
	res = ft_atoi(str_nbr);
	if (res.error)
		return (exit_failure(cub, COLOR_ERR));
	nbr = (int)res.nbr;
	if (nbr < 0 || nbr > 255)
		return (exit_failure(cub, COLOR_ERR));
	*counter = nbr;
}

void	calculate_angle(t_cub *cub, char direction, int x, int y)
{
	if (direction == 'N')
		cub->player->plyr_angle = M_PI / 2;
	else if (direction == 'S')
		cub->player->plyr_angle = 3 * M_PI / 2;
	else if (direction == 'E')
		cub->player->plyr_angle = 0;
	else if (direction == 'W')
		cub->player->plyr_angle = M_PI;
	cub->player->plyr_x = x * TILE_SIZE + TILE_SIZE / 2;
    cub->player->plyr_y = y * TILE_SIZE + TILE_SIZE / 2;
}

int	create_rgb(int *color_arr)
{
	int	r;
	int	g;
	int	b;
	int a;

	r = color_arr[0];
	g = color_arr[1];
	b = color_arr[2];
	a = 0x00000000;
	return (r << 16 | g << 8 | b | a);
}


// void	calculate_center(double x, double y, int *center_x, int *center_y)
// {
// 	*center_x = (int)(x * MINI_TILE_SIZE + MINI_TILE_SIZE / 2);
// 	*center_y = (int)(y * MINI_TILE_SIZE + MINI_TILE_SIZE / 2);
// }

// void	calculate_deltas(t_player *player, int keycode, double *dx, double *dy)
// {
// 	double	move_speed;

// 	move_speed = PLYR_SPEED / 50.0;
// 	if (keycode == 0)
// 	{
// 		*dx = player->plyr_x + cos(player->angle + M_PI_2) * move_speed;
// 		*dy = player->plyr_y - sin(player->angle + M_PI_2) * move_speed;
// 	}
// 	else if (keycode == 2)
// 	{
// 		*dx = player->plyr_x - cos(player->angle + M_PI_2) * move_speed;
// 		*dy = player->plyr_y + sin(player->angle + M_PI_2) * move_speed;
// 	}
// 	else if (keycode == 13)
// 	{
// 		*dx = player->plyr_x + cos(player->angle) * move_speed;
// 		*dy = player->plyr_y - sin(player->angle) * move_speed;
// 	}
// 	else if (keycode == 1)
// 	{
// 		*dx = player->plyr_x - cos(player->angle) * move_speed;
// 		*dy = player->plyr_y + sin(player->angle) * move_speed;
// 	}
// }

/*
	*	void	calculate_center(int x, int y, int *center_x, int *center_y)
	{
		-	Purpose:
			The function finds the center of a specific tile on the map.

		-	Parameters:
			x: The x-cords of the tile (the start of the tile from the left).
			y: The y-cords of the tile (the start of the tile from the top).
			center_x: The address which we will set the x center to.
			center_y: The address which we will set the y center to.
			
		-	How It Works:
			1- Calculate Position: It multiplies the tile's x and y positions 
				by the tile size to get the top-left corner of the tile.
			2- Find Center: It adds half the tile size to these positions 
				to find the center of the tile.
			3- Output: The calculated center cords are stored in
				center_x and center_y.
	}
*/
