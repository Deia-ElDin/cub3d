/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:31:00 by aalshafy          #+#    #+#             */
/*   Updated: 2024/08/25 17:58:58 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"

/*-------------------KEYS-------------------*/
# define MLX_KEY_ESCAPE 53
# define MLX_KEY_W 13
# define MLX_KEY_A 0
# define MLX_KEY_S 1
# define MLX_KEY_D 2
# define MLX_KEY_LEFT 123
# define MLX_KEY_RIGHT 124
# define MLX_PRESS 2
# define MLX_RELEASE 3
# define MLX_REPEAT 1


typedef struct s_mlx_key_data	//the mlx key data structure
{
	int		key;	// the key
	int		action;	// the action
}	mlx_key_data_t;

/*-------------------MACROS-------------------*/
# define TILE_SIZE 30
# define FOV 60
# define S_WIDTH 1900
# define S_HEIGHT 1000
# define ROTATE_SPEED 0.01
# define PLAYER_SPEED 1

/*-------------------STRUCTS-------------------*/

typedef struct s_mlx_img
{
    void    *img;
    char    *addr;
    char    *pixel;
    int     bpp;
    int     line_len;
    int     endian;
}           t_mlx_img;

typedef struct s_player
{
    int     plyr_x;
    int     plyr_y;
    double  plyr_angle;
    float   fov_rd;
    int     rot_flag;
    int     r_l; // right - left flag
    int     u_d; // up - down flag
    int     m_x;
    int     m_y;
}           t_player;

typedef struct s_ray
{
    int     indx;
    double  ray_angle;
    double  hor_x;
    double  hor_y;
    double  ver_x;
    double  ver_y;
    double  distance;
    int     wall_flag;
}           t_ray;

typedef struct s_data
{
    char    **map2d;
    int     p_x; // player x position in the map
    int     p_y; // player y position in the map
    int     w_map; // map width
    int     h_map; // map height
    int     rows;
    int     cols;
}          t_map;

typedef struct s_cube
{
    t_mlx_img   *img;
    void        *win_ptr;
    void        *mlx_ptr;
    t_map      *data;
    t_player    *player;
    t_ray       *ray;
}           t_cub;

/*-------------------PROTOTYPES-------------------*/

/*-------------------INIT-------------------*/
t_map  *init_argument();
char    **init_map();
void    init_player_data(t_cub cube);


/*-------------------GAME-------------------*/
void    start_the_game(t_map *data);
int    game_loop(void *param);
int unit_circle(float angle, char c);
int inter_check(float angle, float *inter, float *step, int is_horizon);
int wall_hit(float x, float y, t_cub *mlx);
float get_h_inter(t_cub *mlx, float angl);
float get_v_inter(t_cub *mlx, float angl);
void cast_rays(t_cub *mlx);
void my_mlx_pixel_put(t_cub *mlx, int x, int y, int color);
float nor_angle(float angle);
void draw_floor_ceiling(t_cub *mlx, int ray, int t_pix, int b_pix);
int get_color(t_cub *mlx, int flag);
void draw_wall(t_cub *mlx, int ray, int t_pix, int b_pix);
void render_wall(t_cub *mlx, int ray);

/*-------------------MOVEMENT-------------------*/
void    hook(t_cub *mlx, double move_x, double move_y);
void    move_player(t_cub *mlx, double move_x, double move_y);
void    rotate_player(t_cub *mlx, int flag);
int     mlx_key(mlx_key_data_t keydata, void *ml);
int     key_reles(mlx_key_data_t keydata, t_cub *mlx);

/*-------------------UTILS-------------------*/
// void    ft_exit(t_cub *mlx);




#endif