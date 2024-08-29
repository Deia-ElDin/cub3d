/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student`.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:04:54 by aalshafy          #+#    #+#             */
/*   Updated: 2024/08/25 17:55:57 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void start_the_game(t_cub *cub);
int game_loop(void *param);

int execution(t_cub *cub)
{
    // t_map       *map;
    // t_texture   *texture;
    // t_player    *player;
    
    printf("execution\n");
    // cub->map = init_argument();
    start_the_game(cub);
    return (0);
}

void start_the_game(t_cub *cub)
{
    cub->player->plyr_x = cub->map->p_x * TILE_SIZE + TILE_SIZE / 2;
    cub->player->plyr_y = cub->map->p_y * TILE_SIZE + TILE_SIZE / 2;
    cub->ray = (t_ray *)ft_calloc(1, sizeof(t_ray));
    if (!cub->ray)
        return ;
    cub->img = (t_mlx_img *)ft_calloc(1, sizeof(t_mlx_img));
    cub->win_ptr = mlx_new_window(cub->mlx_ptr, S_WIDTH, S_HEIGHT, "cub3d");
    init_txtures(cub);
    mlx_hook(cub->win_ptr, MLX_PRESS, MLX_RELEASE, &mlx_key, cub); // key press
    mlx_hook(cub->win_ptr, MLX_RELEASE, MLX_RELEASE, &key_reles, cub); // key release
    mlx_loop_hook(cub->mlx_ptr, &game_loop, cub); // game loop continous called to render the game
    mlx_loop(cub->mlx_ptr);
    // ft_exit(&cub);
}

int game_loop(void *param)
{
    t_cub *cub;

    cub = (t_cub *)param;
    if (cub->img->img)
        mlx_destroy_image(cub->mlx_ptr, cub->img->img);
    cub->img->img = mlx_new_image(cub->mlx_ptr, S_WIDTH, S_HEIGHT);
    cub->img->addr = mlx_get_map_addr(cub->img->img, &cub->img->bpp, &cub->img->line_len, &cub->img->endian);
    hook(cub, 0, 0);
    cast_rays(cub);
    mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img->img, 0, 0);
    return (0);
}

// void	ft_exit(t_cub *mlx) 		// exit the game
// {
// 	int	i = 0;
// 	while (mlx->data->map2d[i])
// 		free(mlx->data->map2d[i++]); // free the map line by line
// 	free(mlx->data->map2d); // free the map
// 	free(mlx->data); // free the data structure
// 	free(mlx->player); // free the player structure
// 	free(mlx->ray); // free the ray structure
// 	mlx_destroy_image(mlx->mlx_ptr, mlx->img->img); // destroy the image
// 	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr); // destroy the window
// 	printf("Game closed\n"); // print the message
// 	exit(0); // exit the game
// }

void init_txtures(t_cub *cub)
{
    t_txtrs *txtrs;
    t_texture texture;


    texture = cub->texture;
    txtrs = (t_txtrs *)ft_calloc(1, sizeof(t_txtrs));
    cub->txtrs = txtrs;
    txtrs->no = (t_txtdata *)ft_calloc(1, sizeof(t_txtdata));
    txtrs->so = (t_txtdata *)ft_calloc(1, sizeof(t_txtdata));
    txtrs->we = (t_txtdata *)ft_calloc(1, sizeof(t_txtdata));
    txtrs->ea = (t_txtdata *)ft_calloc(1, sizeof(t_txtdata));
    txtrs->no->img = texture.no_img;
    txtrs->so->img = texture.so_img;
    txtrs->we->img = texture.we_img;
    txtrs->ea->img = texture.ea_img;
    txtrs->no->addr = mlx_get_map_addr(txtrs->no->img, &txtrs->no->bpp, &txtrs->no->line_len, &txtrs->no->endian);
    txtrs->so->addr = mlx_get_map_addr(txtrs->so->img, &txtrs->so->bpp, &txtrs->so->line_len, &txtrs->so->endian);
    txtrs->we->addr = mlx_get_map_addr(txtrs->we->img, &txtrs->we->bpp, &txtrs->we->line_len, &txtrs->we->endian);
    txtrs->ea->addr = mlx_get_map_addr(txtrs->ea->img, &txtrs->ea->bpp, &txtrs->ea->line_len, &txtrs->ea->endian);
}
