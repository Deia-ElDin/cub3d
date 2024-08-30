#include "cub3d.h"

int	key_reles(mlx_key_data_t keydata, t_cub *mlx)	// release the key
{
	if (keydata.key == MLX_KEY_D)
		mlx->player->r_l = 0;
	else if (keydata.key == MLX_KEY_A)
		mlx->player->r_l = 0;
	else if (keydata.key == MLX_KEY_S)
		mlx->player->u_d = 0;
	else if (keydata.key == MLX_KEY_W)
		mlx->player->u_d = 0;
	else if (keydata.key == MLX_KEY_LEFT)
		mlx->player->rot_flag = 0;
	else if (keydata.key == MLX_KEY_RIGHT)
		mlx->player->rot_flag = 0;
	return (0);
}

int mlx_key(mlx_key_data_t keydata, void *ml)	// key press
{
	t_cub    *mlx;

	mlx = ml;
	if (keydata.key == MLX_KEY_ESCAPE) // exit the game
		exit_success(mlx);
	else if (keydata.key == MLX_KEY_A) // move left
		mlx->player->r_l -= 1;
	else if (keydata.key == MLX_KEY_D) // move right
		mlx->player->r_l += 1;
	else if (keydata.key == MLX_KEY_S) // move down
		mlx->player->u_d = -1;
	else if (keydata.key == MLX_KEY_W) // move up
		mlx->player->u_d = 1;
	else if (keydata.key == MLX_KEY_LEFT) // rotate left
		mlx->player->rot_flag = -1;
	else if (keydata.key == MLX_KEY_RIGHT) // rotate right
		mlx->player->rot_flag = 1;
	return (0);
}

void	rotate_player(t_cub *mlx, int i)	// rotate the player
{
	if (i == 1)
	{
		mlx->player->plyr_angle += ROTATE_SPEED; // rotate right
		if (mlx->player->plyr_angle > 2 * M_PI)
			mlx->player->plyr_angle -= 2 * M_PI;
	}
	else
	{
		mlx->player->plyr_angle -= ROTATE_SPEED; // rotate left
		if (mlx->player->plyr_angle < 0)
			mlx->player->plyr_angle += 2 * M_PI;
	}
}



int	check_collision(t_map *data, float new_x, float new_y)
{
	int	map_x1;
	int	map_y1;
	int	map_x2;
	int	map_y2;

	map_x1 = (int)(new_x - 5) / TILE_SIZE;
	map_y1 = (int)(new_y - 5) / TILE_SIZE;
	map_x2 = (int)(new_x + 5) / TILE_SIZE;
	map_y2 = (int)(new_y + 5) / TILE_SIZE;
	if (map_x1 < 0 || map_x1 >= data->map_width || map_y1 < 0
		|| map_y1 >= data->map_height || map_x2 < 0 || map_x2 >= data->map_width
		|| map_y2 < 0 || map_y2 >= data->map_height)
		return (1);
	return (data->map_arr[map_y1][map_x1] == '1'
		|| data->map_arr[map_y1][map_x2] == '1'
		|| data->map_arr[map_y2][map_x1] == '1'
		|| data->map_arr[map_y2][map_x2] == '1');
}


void	move_player(t_cub *mlx, double move_x, double move_y)	// move the player
{
	// int		map_grid_y;
	// int		map_grid_x;
	int		new_x;
	int		new_y;

	new_x = roundf(mlx->player->plyr_x + move_x); // get the new x position
	new_y = roundf(mlx->player->plyr_y + move_y); // get the new y position
	if (!check_collision(mlx->map, new_x, new_y))
	{
		mlx->player->plyr_x = new_x; // move the player
		mlx->player->plyr_y = new_y; 
	}
	// map_grid_x = (new_x / TILE_SIZE); // get the x position in the map
	// map_grid_y = (new_y / TILE_SIZE); // get the y position in the map
	// if (mlx->map->map_arr[map_grid_y][map_grid_x] != '1' && \
	// (mlx->map->map_arr[map_grid_y][mlx->player->plyr_x / TILE_SIZE] != '1' && \
	// mlx->map->map_arr[mlx->player->plyr_y / TILE_SIZE][map_grid_x] != '1')) // check the wall hit and the diagonal wall hit
	// {
	// 	mlx->player->plyr_x = new_x; // move the player
	// 	mlx->player->plyr_y = new_y; // move the player
	// }
}

void	hook(t_cub *mlx, double move_x, double move_y)	// hook the player
{
	if (mlx->player->rot_flag == 1) //rotate right
		rotate_player(mlx, 1);
	if (mlx->player->rot_flag == -1) //rotate left
		rotate_player(mlx, 0);
	if (mlx->player->r_l == 1) //move right
	{
		move_x = -sin(mlx->player->plyr_angle) * PLAYER_SPEED;
		move_y = cos(mlx->player->plyr_angle) * PLAYER_SPEED;
	}
	if (mlx->player->r_l == -1) //move left
	{
		move_x = sin(mlx->player->plyr_angle) * PLAYER_SPEED;
		move_y = -cos(mlx->player->plyr_angle) * PLAYER_SPEED;
	}
	if (mlx->player->u_d == 1) //move up
	{
		move_x = cos(mlx->player->plyr_angle) * PLAYER_SPEED;
		move_y = sin(mlx->player->plyr_angle) * PLAYER_SPEED;
	}
	if (mlx->player->u_d == -1) //move down
	{
		move_x = -cos(mlx->player->plyr_angle) * PLAYER_SPEED;
		move_y = -sin(mlx->player->plyr_angle) * PLAYER_SPEED;
	}
	move_player(mlx, move_x, move_y); // move the player
}