/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:33:41 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/19 14:17:06 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_block(t_img *img, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 63)
	{
		j = 0;
		while (j < 63)
		{
			my_mlx_pixel_put(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_ceiling(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = 0;
		while (j < SCREEN_HEIGHT)
		{
			my_mlx_pixel_put(img, i, j, 0xC0C0C0);
			j++;
		}
		i++;
	}
}

void	draw_floor(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = SCREEN_HEIGHT / 2;
		while (j < SCREEN_HEIGHT)
		{
			my_mlx_pixel_put(img, i, j, 0x000080);
			j++;
		}
		i++;
	}
}

void	map_draw(t_cub *cub, char **map)
{
	int		x;
	int		y;
	t_img	img;

	y = 0;
	img = cub->img;
	draw_ceiling(&img);
	draw_floor(&img);
	while (map[y])
	{
		printf("y = %d\n", y);
		x = 0;
		while (map[y][x])
		{
			printf("x = %d\n", x);
			if (map[y][x] == '1')
				draw_block(&img, x * 64, y * 64, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, img.img, 0, 0);
}

void	execution(t_cub *cub)
{
	t_img	*img;

	img = &cub->img;
	cub->win = mlx_new_window(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!cub->win)
		exit_failure(cub, MLX_ERR);
	img->img = mlx_new_image(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
		&img->line_length, &img->endian);
	map_draw(cub, cub->map.map_arr);
	mlx_loop(cub->mlx);
}
