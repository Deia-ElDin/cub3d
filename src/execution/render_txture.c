/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_txture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:30:16 by aalshafy          #+#    #+#             */
/*   Updated: 2024/08/30 18:35:48 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_txtdata	*get_txt(t_cub *mlx, int flag)
{
	mlx->ray->ray_angle = nor_angle(mlx->ray->ray_angle);
	if (flag == 0)
	{
		if (mlx->ray->ray_angle > M_PI / 2 && mlx->ray->ray_angle < 3 * (M_PI
				/ 2))
			return (mlx->txtrs->ea);
		else
			return (mlx->txtrs->we);
	}
	else
	{
		if (mlx->ray->ray_angle > 0 && mlx->ray->ray_angle < M_PI)
			return (mlx->txtrs->so);
		else
			return (mlx->txtrs->no);
	}
}

double	texture_x(t_cub *mlx, t_txtdata *texture, int flag)
{
	double	x_o;

	(void)texture;
	if (flag == 1)
		x_o = ((float)((int)mlx->ray->hor_x % TILE_SIZE) / TILE_SIZE)
			* texture->width;
	else
		x_o = ((float)((int)mlx->ray->ver_y % TILE_SIZE) / TILE_SIZE)
			* texture->width;
	return (x_o);
}

void	draw_floor_ceiling(t_cub *mlx, int ray, int t_pix, int b_pix)
{
	int	i;
	int	color;

	i = b_pix;
	color = mlx->txtrs->f_color;
	while (i < S_HEIGHT)
		my_mlx_pixel_put(mlx, ray, i++, color);
	i = 0;
	color = mlx->txtrs->c_color;
	while (i < t_pix)
		my_mlx_pixel_put(mlx, ray, i++, color);
}

int	unit_circle(float angle, char c)
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
