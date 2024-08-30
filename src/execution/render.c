/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:32:14 by aalshafy          #+#    #+#             */
/*   Updated: 2024/08/30 18:36:44 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(t_mlx_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put(t_cub *mlx, int x, int y, int color)
{
	if (x < 0)
		return ;
	else if (x >= S_WIDTH)
		return ;
	if (y < 0)
		return ;
	else if (y >= S_HEIGHT)
		return ;
	my_pixel_put(mlx->img, x, y, color);
}

float	nor_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void	draw_wall(t_cub *mlx, int t_pix, int b_pix, double wall_h)
{
	int			color;
	t_txtdata	*txt;
	double		x_o;
	double		y_o;
	double		fact;

	txt = get_txt(mlx, mlx->ray->wall_flag);
	fact = (double)txt->height / wall_h;
	x_o = texture_x(mlx, txt, mlx->ray->wall_flag);
	y_o = (t_pix - (S_HEIGHT / 2) + (wall_h / 2)) * fact;
	if (y_o < 0)
		y_o = 0;
	while (t_pix < b_pix)
	{
		color = *(unsigned int *)(txt->addr + ((int)y_o * txt->line_len
					+ (int)x_o * (txt->bpp / 8)));
		my_mlx_pixel_put(mlx, mlx->ray->indx, t_pix++, color);
		y_o += fact;
	}
}

void	render_wall(t_cub *mlx, int ray)
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	mlx->ray->distance *= cos(nor_angle(mlx->ray->ray_angle
				- mlx->player->plyr_angle));
	wall_h = (TILE_SIZE / mlx->ray->distance) * ((S_WIDTH / 2)
			/ tan(mlx->player->fov_rd / 2));
	b_pix = (S_HEIGHT / 2) + (wall_h / 2);
	t_pix = (S_HEIGHT / 2) - (wall_h / 2);
	if (b_pix > S_HEIGHT)
		b_pix = S_HEIGHT;
	if (t_pix < 0)
		t_pix = 0;
	mlx->ray->indx = ray;
	draw_wall(mlx, t_pix, b_pix, wall_h);
	draw_floor_ceiling(mlx, ray, t_pix, b_pix);
}
