#include "cub3d.h"

t_txtdata *get_txt(t_cub *mlx, int flag) // get the texture
{
    mlx->ray->ray_angle = nor_angle(mlx->ray->ray_angle);
    if (flag == 0)
	{
		if (mlx->ray->ray_angle > M_PI / 2 && mlx->ray->ray_angle < 3 * (M_PI / 2))
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

double texture_x(t_cub *mlx, t_txtdata *texture, int flag) // get the x coordinate of the texture
{
    double	x_o;
	(void) texture;

	if (flag == 1)
		x_o = ((float)((int) mlx->ray->hor_x % TILE_SIZE) / TILE_SIZE )* texture->width;
	else
		x_o = ((float)((int) mlx->ray->ver_y % TILE_SIZE) / TILE_SIZE )* texture->width;
	return (x_o);


	// 	ray->x_texture = ((double)((int)ray->ry % data->pixel_y) / (double)(data->pixel_y)) * data->texture->width;
	// if (ray->dis_h < ray->dis_v)
	// 	ray->x_texture = ((double)((int)ray->rx % data->pixel_x)
	// 			/ (double)(data->pixel_x)) * data->texture->width;
	// ray->y_step = (float)data->texture->height / ray->line_height;
}

void draw_floor_ceiling(t_cub *mlx, int ray, int t_pix, int b_pix) // draw the floor and the ceiling
{
    int  i;
    int color;

    i = b_pix;
    color = mlx->txtrs->f_color;
    while (i < S_HEIGHT)
        my_mlx_pixel_put(mlx, ray, i++, color); // floor
    i = 0;
    color = mlx->txtrs->c_color;
    while (i < t_pix)
        my_mlx_pixel_put(mlx, ray, i++, color); // ceiling
}
