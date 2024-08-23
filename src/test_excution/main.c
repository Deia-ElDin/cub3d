/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:04:54 by aalshafy          #+#    #+#             */
/*   Updated: 2024/08/15 18:06:36 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d_test.h"

int main()
{
    t_data *data;
    
    data = init_argument();
    start_the_game(data);
    return (0);
}

void start_the_game(t_data *data)
{
    t_cube cube;

    cube.data = data;
    cube.player = (t_player *)ft_calloc(1, sizeof(t_player));
    if (!cube.player)
        return ;
    init_player_data(cube);
    cube.ray = (t_ray *)ft_calloc(1, sizeof(t_ray));
    if (!cube.ray)
        return ;
    cube.img = (t_mlx_img *)ft_calloc(1, sizeof(t_mlx_img));
    cube.mlx_ptr = mlx_init();
    cube.win_ptr = mlx_new_window(cube.mlx_ptr, S_WIDTH, S_HEIGHT, "cub3d");
    mlx_hook(cube.win_ptr, MLX_PRESS, MLX_RELEASE, &mlx_key, &cube); // key press
    mlx_hook(cube.win_ptr, MLX_RELEASE, MLX_RELEASE, &key_reles, &cube); // key release
    mlx_loop_hook(cube.mlx_ptr, &game_loop, &cube); // game loop continous called to render the game
    mlx_loop(cube.mlx_ptr);
    // ft_exit(&cube);
}

int game_loop(void *param)
{
    t_cube *cube;

    cube = (t_cube *)param;
    if (cube->img->img)
        mlx_destroy_image(cube->mlx_ptr, cube->img->img);
    cube->img->img = mlx_new_image(cube->mlx_ptr, S_WIDTH, S_HEIGHT);
    cube->img->addr = mlx_get_data_addr(cube->img->img, &cube->img->bpp, &cube->img->line_len, &cube->img->endian);
    hook(cube, 0, 0);
    cast_rays(cube);
    mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img->img, 0, 0);
    return (0);
}

void	ft_exit(t_cube *mlx) 		// exit the game
{
	int	i = 0;
	while (mlx->data->map2d[i])
		free(mlx->data->map2d[i++]); // free the map line by line
	free(mlx->data->map2d); // free the map
	free(mlx->data); // free the data structure
	free(mlx->player); // free the player structure
	free(mlx->ray); // free the ray structure
	mlx_destroy_image(mlx->mlx_ptr, mlx->img->img); // destroy the image
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr); // destroy the window
	printf("Game closed\n"); // print the message
	exit(0); // exit the game
}