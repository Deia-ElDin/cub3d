/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:25:37 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/22 20:27:35 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor_ceiling(t_texture *texture, t_img *img, int ray, int t_pix, int b_pix)
{
	int		i;
	int		c;

	i = b_pix;
	c = texture->f_color; // Using predefined floor color
	while (i < SCREEN_HEIGHT)
		my_mlx_pixel_put(img, ray, i++, c);
	c = texture->c_color; // Using predefined ceiling color
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(img, ray, i++, c);
}

void	*get_texture(t_texture *texture, t_ray *ray)
{
	ray->ray_ngl = normalize_angle(ray->ray_ngl);
	if (ray->flag == 0)
	{
		if (ray->ray_ngl > M_PI / 2 && ray->ray_ngl < 3 * (M_PI / 2))
			return (texture->ea_img);
		else
			return (texture->we_img);
	}
	else
	{
		if (ray->ray_ngl > 0 && ray->ray_ngl < M_PI)
			return (texture->so_img);
		else
			return (texture->no_img);
	}
}

double	get_x_o(void *texture, t_ray *ray)
{
	double	x_o;
	int		width = TILE_SIZE; // Assuming TILE_SIZE for the texture width

	if (ray->flag == 1)
		x_o = fmod(ray->ray_ngl * (width / TILE_SIZE), width);
	else
		x_o = fmod(ray->ray_ngl * (width / TILE_SIZE), width);
	return (x_o);
}

void	draw_wall(t_img *img, t_ray *ray, t_texture *texture, int t_pix, int b_pix, double wall_h)
{
	double			x_o;
	double			y_o;
	void			*tex;
	uint32_t		*arr;
	double			factor;

	tex = get_texture(texture, ray);
	// Assuming you have a way to get the pixel data from your texture
	arr = (uint32_t *)tex;
	factor = TILE_SIZE / wall_h;
	x_o = get_x_o(tex, ray);
	y_o = (t_pix - (SCREEN_HEIGHT / 2) + (wall_h / 2)) * factor;
	if (y_o < 0)
		y_o = 0;
	while (t_pix < b_pix)
	{
		my_mlx_pixel_put(img, ray->ray_ngl, t_pix, arr[(int)y_o * TILE_SIZE + (int)x_o]);
		y_o += factor;
		t_pix++;
	}
}

void	render_wall(t_cub *cub, int ray)
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	cub->ray.distance *= cos(normalize_angle(cub->ray.ray_ngl - cub->player.angle));
	wall_h = (TILE_SIZE / cub->ray.distance) * ((SCREEN_WIDTH / 2) / tan(cub->player.fov_rd / 2));
	b_pix = (SCREEN_HEIGHT / 2) + (wall_h / 2);
	t_pix = (SCREEN_HEIGHT / 2) - (wall_h / 2);
	if (b_pix > SCREEN_HEIGHT)
		b_pix = SCREEN_HEIGHT;
	if (t_pix < 0)
		t_pix = 0;
	cub->ray.ray_ngl = ray;
	draw_wall(&cub->img, &cub->ray, &cub->texture, t_pix, b_pix, wall_h);
	draw_floor_ceiling(&cub->texture, &cub->img, ray, t_pix, b_pix);
}
