/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:23:52 by aalshafy          #+#    #+#             */
/*   Updated: 2024/08/24 17:09:32 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d_test.h"

void	my_pixel_put(t_mlx_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void my_mlx_pixel_put(t_cube *mlx, int x, int y, int color) // put the pixel
{
	if (x < 0) // check the x position
		return ;
	else if (x >= S_WIDTH)
		return ;
	if (y < 0) // check the y position
		return ;
	else if (y >= S_HEIGHT)
		return ;
	my_pixel_put(mlx->img, x, y, color); // put the pixel
}

float nor_angle(float angle) // normalize the angle
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

// void draw_floor_ceiling(t_cube *mlx, int ray, int t_pix, int b_pix) // draw the floor and the ceiling
// {
//     int  i;

// 	i = b_pix;
// 	while (i < S_HEIGHT)
// 		my_mlx_pixel_put(mlx, ray, i++, 0xB99470FF); // floor
// 	i = 0;
// 	while (i < t_pix)
// 		my_mlx_pixel_put(mlx, ray, i++, 0x89CFF3FF); // ceiling
// }

int get_color(t_cube *mlx, int flag) // get the color of the wall
{
	mlx->ray->ray_angle = nor_angle(mlx->ray->ray_angle); // normalize the angle
	if (flag == 0)
	{
		if (mlx->ray->ray_angle > M_PI / 2 && mlx->ray->ray_angle < 3 * (M_PI / 2))
			return (0xB5B5B5FF); // west wall
		else
			return (0xB5B5B5FF); // east wall
	}
	else
	{
		if (mlx->ray->ray_angle > 0 && mlx->ray->ray_angle < M_PI)
			return (0xF5F5F5FF); // south wall
		else
			return (0xF5F5F5FF); // north wall
	}
}

void draw_wall(t_cube *mlx, int t_pix, int b_pix, double wall_h) // draw the wall
{
	int color;
	t_txtdata *txt;
	double x_o;
	double y_o;
	double fact;

	txt = get_txt(mlx, mlx->ray->wall_flag); // get the texture
	fact = (double)txt->height / wall_h; // get the texture height
	x_o = texture_x(mlx, txt, mlx->ray->wall_flag); // get the x coordinate of the texture
	y_o = (t_pix - (S_HEIGHT / 2) + (wall_h / 2)) * fact; // get the y coordinate of the texture
	if (y_o < 0)
		y_o = 0;
	while (t_pix < b_pix)
	{
		color = reverse_color(*(unsigned int *)(txt->addr + ((int)y_o * txt->line_len + (int)x_o * (txt->bpp / 8)))); // get the color
		my_mlx_pixel_put(mlx, mlx->ray->indx, t_pix++, color); // put the pixel
		y_o += fact; // increment the y coordinate
	}
}

void render_wall(t_cube *mlx, int ray) // render the wall
{
	double wall_h;
	double b_pix;
	double t_pix;

	mlx->ray->distance *= cos(nor_angle(mlx->ray->ray_angle - mlx->player->plyr_angle)); // fix the fisheye
	wall_h = (TILE_SIZE / mlx->ray->distance) * ((S_WIDTH / 2) / tan(mlx->player->fov_rd / 2)); // get the wall height
	b_pix = (S_HEIGHT / 2) + (wall_h / 2); // get the bottom pixel
	t_pix = (S_HEIGHT / 2) - (wall_h / 2); // get the top pixel
	if (b_pix > S_HEIGHT) // check the bottom pixel
		b_pix = S_HEIGHT;
	if (t_pix < 0) // check the top pixel
		t_pix = 0;
	mlx->ray->indx = ray; // get the index
	draw_wall(mlx, t_pix, b_pix, wall_h); // draw the wall
	draw_floor_ceiling(mlx, ray, t_pix, b_pix); // draw the floor and the ceiling
}