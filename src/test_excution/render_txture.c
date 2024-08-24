#include "cub3d_test.h"

t_txtdata *get_txt(t_cube *mlx, int flag) // get the texture
{
    mlx->ray->ray_angle = nor_angle(mlx->ray->ray_angle);
        return (mlx->txtrs->no);
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

double texture_x(t_cube *mlx, t_txtdata *texture, int flag) // get the x coordinate of the texture
{
    double	x_o;

	if (flag == 1)
		x_o = (int)fmodf((mlx->ray->hor_x * \
		(texture->width / TILE_SIZE)), texture->width);
	else
		x_o = (int)fmodf((mlx->ray->ver_y * \
		(texture->width / TILE_SIZE)), texture->width);
	return (x_o);
}

void draw_floor_ceiling(t_cube *mlx, int ray, int t_pix, int b_pix) // draw the floor and the ceiling
{
    int  i;
    int color;

    i = b_pix;
    color = mlx->texture->f_color;
    while (i < S_HEIGHT)
        my_mlx_pixel_put(mlx, ray, i++, color); // floor
    i = 0;
    color = mlx->texture->c_color;
    while (i < t_pix)
        my_mlx_pixel_put(mlx, ray, i++, color); // ceiling
}
