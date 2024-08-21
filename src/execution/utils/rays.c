/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:40:02 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/21 14:50:18 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	unit_circle(float angle, char c)	// check the unit circle
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}

int	inter_check(float angle, float *inter, float *step, int is_horizon)	// check the intersection
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2)) 
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int	wall_hit(t_cub *cub, float x, float y)	// check the wall hit
{
	int		x_m;
	int		y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor (x / TILE_SIZE); // get the x position in the map
	y_m = floor (y / TILE_SIZE); // get the y position in the map
	if ((y_m >= cub->dt->h_map || x_m >= cub->dt->w_map))
		return (0);
	if (cub->dt->map2d[y_m] && x_m <= (int)strlen(cub->dt->map2d[y_m]))
		if (cub->dt->map2d[y_m][x_m] == '1')
			return (0);
	return (1);
}

float	get_h_inter(t_cub *cub, float angle)	// get the horizontal intersection
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angle);
	h_y = floor(cub->player->plyr_y / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angle, &h_y, &y_step, 1);
	h_x = cub->player->plyr_x + (h_y - cub->player->plyr_y) / tan(angle);
	if ((unit_circle(angle, 'y') && x_step > 0) || (!unit_circle(angle, 'y') && x_step < 0)) // check x_step value
		x_step *= -1;
	while (wall_hit(h_x, h_y - pixel, cub)) // check the wall hit whit the pixel value
	{
		h_x += x_step;
		h_y += y_step;
	}
	return (sqrt(pow(h_x - cub->player->plyr_x, 2) + pow(h_y - cub->player->plyr_y, 2))); // get the distance
}

float	get_v_inter(t_cub *cub, float angle)	// get the vertical intersection
{
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE; 
	y_step = TILE_SIZE * tan(angle);
	v_x = floor(cub->player->plyr_x / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angle, &v_x, &x_step, 0); // check the intersection and get the pixel value
	v_y = cub->player->plyr_y + (v_x - cub->player->plyr_x) * tan(angle);
	if ((unit_circle(angle, 'x') && y_step < 0) || (!unit_circle(angle, 'x') && y_step > 0)) // check y_step value
		y_step *= -1;
	while (wall_hit(v_x - pixel, v_y, cub)) // check the wall hit whit the pixel value
	{
		v_x += x_step;
		v_y += y_step;
	}
	return (sqrt(pow(v_x - cub->player->plyr_x, 2) + pow(v_y - cub->player->plyr_y, 2))); // get the distance
}

void cast_rays(t_cub *cub) // cast the rays
{
	double	h_inter;
	double	v_inter;
	int		ray;

	ray = 0;
	cub->ray->ray_ngl = cub->player->angle - (cub->player->fov_rd / 2);
	while (ray < SCREEN_WIDTH) // loop for the rays
	{
		cub->ray->flag = 0; // flag for the wall
		h_inter = get_h_inter(cub, nor_angle(cub->ray->ray_ngl)); // get the horizontal intersection
		v_inter = get_v_inter(cub, nor_angle(cub->ray->ray_ngl)); // get the vertical intersection
		if (v_inter <= h_inter) // check the distance
			cub->ray->distance = v_inter; // get the distance
		else
		{
			cub->ray->distance = h_inter; // get the distance
			cub->ray->flag = 1; // flag for the wall
		}
		render_wall(cub, ray); // render the wall
		ray++; // next ray
		cub->ray->ray_ngl += (cub->player->fov_rd / SCREEN_WIDTH); // next angle
	}
}
