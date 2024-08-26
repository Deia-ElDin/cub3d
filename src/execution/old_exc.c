#include "cub3d.h"

static char **init_map();
// static void init_player_map(t_cub cub);


t_map *init_argument()
{
    t_map *map;

    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->map_arr = init_map();
    map->map_width = 25;
    map->map_height = 9;
    map->p_x = 12;
    map->p_y = 2;
    return (map);
}

char **init_map()
{
    char **map;

    map = (char **)malloc(sizeof(char *) * 10);
    if (!map)
        return (NULL);
    map[0] = ft_strdup("1111111111111111111111111");
    map[1] = ft_strdup("1000000000000000000000001");
    map[2] = ft_strdup("1001000000000P00000000001");
    map[3] = ft_strdup("1001000000000000000000001");
    map[4] = ft_strdup("1001000000000000001000001");
    map[5] = ft_strdup("1001000000000000001000001");
    map[6] = ft_strdup("1001000000000000001000001");
    map[7] = ft_strdup("1000000000000000000000001");
    map[8] = ft_strdup("1111111111111111111111111");
    map[9] = NULL;
    return (map);
}

void init_player_data(t_cub cub)
{
    char c;

    c = cub.map->map_arr[cub.map->p_y][cub.map->p_x];
    if (c == 'N')
        cub.player->plyr_angle = 3 * M_PI / 2;
    else if (c == 'S')
        cub.player->plyr_angle = M_PI / 2;
    else if (c == 'W')
        cub.player->plyr_angle = M_PI;
    else if (c == 'E')
        cub.player->plyr_angle = 0;
    else
        cub.player->plyr_angle = M_PI; // default angle for testing need to removed after adding parsing
    cub.player->plyr_x = cub.map->p_x * TILE_SIZE + TILE_SIZE / 2;
    cub.player->plyr_y = cub.map->p_y * TILE_SIZE + TILE_SIZE / 2;
    cub.player->fov_rd = (FOV * M_PI) / 180;
    // cub.player->rot_flag = 0;
    // cub.player->r_l = 0;
    // cub.player->u_d = 0;
}