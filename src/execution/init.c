/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:12:28 by aalshafy          #+#    #+#             */
/*   Updated: 2024/08/25 17:04:01 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// t_map *init_argument()
// {
//     t_map *data;

//     data = (t_map *)ft_calloc(1, sizeof(t_map));
//     if (!data)
//         return (NULL);
//     data->map2d = init_map();
//     data->p_x = 13;
//     data->p_y = 3;
//     data->w_map = 25;
//     data->h_map = 9;
//     return (data);
// }

// char **init_map()
// {
//     char **map;

//     map = (char **)malloc(sizeof(char *) * 10);
//     if (!map)
//         return (NULL);
//     map[0] = ft_strdup("1111111111111111111111111");
//     map[1] = ft_strdup("1000000000000000000000001");
//     map[2] = ft_strdup("1001000000000P00000000001");
//     map[3] = ft_strdup("1001000000000000000000001");
//     map[4] = ft_strdup("1001000000000000001000001");
//     map[5] = ft_strdup("1001000000000000001000001");
//     map[6] = ft_strdup("1001000000000000001000001");
//     map[7] = ft_strdup("1000000000000000000000001");
//     map[8] = ft_strdup("1111111111111111111111111");
//     map[9] = NULL;
//     return (map);
// }

// void init_player_data(t_cub cub)
// {
//     char c;

//     c = cub.map->map_arr[cub.map->p_y][cub.map->p_x];
//     if (c == 'N')
//         cube.player->plyr_angle = 3 * M_PI / 2;
//     else if (c == 'S')
//         cube.player->plyr_angle = M_PI / 2;
//     else if (c == 'W')
//         cube.player->plyr_angle = M_PI;
//     else if (c == 'E')
//         cube.player->plyr_angle = 0;
//     else
//         cube.player->plyr_angle = M_PI; // default angle for testing need to removed after adding parsing
//     cube.player->plyr_x = cub.map->p_x * TILE_SIZE + TILE_SIZE / 2;
//     cube.player->plyr_y = cub.map->p_y * TILE_SIZE + TILE_SIZE / 2;
//     cube.player->fov_rd = (FOV * M_PI) / 180;
//     // cube.player->rot_flag = 0;
//     // cube.player->r_l = 0;
//     // cube.player->u_d = 0;
// }
    
    
    
        