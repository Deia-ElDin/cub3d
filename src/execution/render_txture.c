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
		x_o = (int)fmodf((mlx->ray->hor_x * \
		(64 / TILE_SIZE)), 64); // need to intialize the texture_width on the t_txtdata structure on parsing
	else
		x_o = (int)fmodf((mlx->ray->ver_y * \
		(64 / TILE_SIZE)), 64);
	return (x_o);
}

void draw_floor_ceiling(t_cub *mlx, int ray, int t_pix, int b_pix) // draw the floor and the ceiling
{
    int  i;
    int color;

    i = b_pix;
    color = mlx->texture.f_color;
    while (i < S_HEIGHT)
        my_mlx_pixel_put(mlx, ray, i++, color); // floor
    i = 0;
    color = mlx->texture.c_color;
    while (i < t_pix)
        my_mlx_pixel_put(mlx, ray, i++, color); // ceiling
}
