/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:23:43 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/29 15:45:07 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>

enum
{
	ON_KEYDOWN = 2,
	ON_DESTROY = 17
};

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

/*-------------------COLORS-------------------*/
# define BLACK 0x000000
# define WHITE 0xFFFFFF


// ******************** Constants ******************** //

# define S_HEIGHT 1900
# define S_WIDTH 1000
# define TILE_SIZE 30
# define FOV 60 
# define ROTATE_SPEED 0.2
# define PLAYER_SPEED 4

// ********************* Errors ********************* //

# define INVALID_FD "Error\nFailed to open the file you provided.\n"
# define INVALID_FILE_NAME "Error\nInvalid file, kindly check the file name.\n"
# define INVALID_FILE_EMPTY "Error\nInvalid file, \
kindly provide us a file to work with.\n"
# define INVALID_FILE_NOT_COMPLETE "Error\nInvalid file, \
the file missing some elements or the map.\n"
# define MALLOC_ERR "Error\nFailed to malloc.\n"
# define READ_ERR "Error\nSomething went wrong with the read function, \
kindly try again later.\n"
# define TAB_ERR "Error\nInvalid file, tab character found.\n"
# define ELEMENTS_ERR "Error\nInvalid elements.\n"
# define ELEMENTS_EXIST_ERR "Error\nInvalid elements. element already exist.\n"
# define ELEMENTS_SPACE_ERR "Error\nInvalid elements, \
invalid spaces within the image file name.\n"
# define ELEMENTS_IMG_NAME_ERR "Error\nInvalid elements, \
invalid image file name.\n"
# define ELEMENTS_IMG_CORRUPTED_ERR "Error\nInvalid elements, \
invalid image corrupted file.\n"
# define MAP_EMPTY_ERR "Error\nInvalid map, the map is empty.\n"
# define MAP_HEIGHT_ERR "Error\nInvalid map, the map is less than 3 lines.\n"
# define MAP_LINE_ERR "Error\nInvalid map, not a map line.\n"
# define MAP_EMPTY_LINE "Error\nInvalid map, \
the map can't be separated by one or more empty line(s).\n"
# define MAP_CHARS_ERR "Error\nInvalid map, invalid characters.\n"
# define MAP_SPACE_ERR "Error\nInvalid map, invalid spaces.\n"
# define MAP_WALL_ERR "Error\nInvalid map, not surrounded by walls.\n"
# define MLX_ERR "Error\nSomething went wrong with mlx lib, kindly try later.\n"
# define COLOR_ERR "Error\nInvalid color.\n"


typedef struct s_mlx_key_data	//the mlx key data structure
{
	int		key;	// the key
	int		action;	// the action
}	mlx_key_data_t;

typedef struct s_file
{
	char	**file_arr;
	int		filepath_len;
	int		stage;
	int		file_len;
}	t_file;

typedef struct s_texture
{
	void	*no_img;
	void	*so_img;
	void	*we_img;
	void	*ea_img;
	int		f_arr[3];
	int		c_arr[3];
	int		f_color;
	int		c_color;
}	t_texture;

typedef struct s_map
{
	char	**map_arr;
	int		map_width;
	int		map_height;
	int		map_st;
	int		map_end;
	int		wall_counter;
	int		plyr_counter;
	int		p_x; // player x position in the map for testing needs delete it later
	int		p_y; // player y position in the map for testing needs delete it later
	char	plyr_direction;
}	t_map;

typedef struct s_player
{
	int		plyr_x;
	int		plyr_y;
	double	plyr_angle;
	float	fov_rd;
	int		rot_flag;
	int		r_l;
	int		u_d;
	int		m_x;
	int		m_y;
}	t_player;

// typedef struct s_img
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }	t_img;

typedef struct s_mlx_img
{
    void    *background_img;
    void    *wall_img;
    void    *img;
    char    *addr;
    char    *pixel;
    int     bpp;
    int     line_len;
    int     endian;
    int     tx_width;
    int     tx_height;
}           t_mlx_img;

// typedef struct s_ray
// {
// 	double	ray_ngl;
// 	double	distance;
// 	int		flag;
// }	t_ray;

typedef struct s_txtdata
{
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
    int     width;
    int     height;
}           t_txtdata;

typedef struct s_txtrs
{
    t_txtdata   *no;
    t_txtdata   *so;
    t_txtdata   *we;
    t_txtdata   *ea;
	int			f_arr[3];
	int			c_arr[3];
	int			f_color;
	int			c_color;
}           t_txtrs;
 
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

typedef struct s_cub
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_file		file;
	t_texture	texture;
	t_map		*map;
	t_player	*player;
	t_mlx_img   *img;
	t_ray		*ray;
	t_txtrs     *txtrs;
}	t_cub;

// ********************* PARSING ********************* //

void	parsing(t_cub *cub, char *input_file);

// ****************** PARSING UTILS ****************** //

// 		*	validate.c
void	file_validate(t_cub *cub, t_file *file, t_map *map);
// 		*	utils.c
int		is_color(t_cub *cub, char *line, int *color_idx, int *color_arr);
bool	is_textures_ready(t_texture *texture);
void	is_player(t_cub *cub, char *map_line, int y);
void	set_map_width(t_map *map, char *map_line);
char	*set_map_line(t_cub *cub, t_map *map, char *map_line);

// ******************** EXECUTION ******************** //


// ***************** EXECUTION UTILS ***************** //
// 		*	draw.c
int		draw_map(t_cub *cub);
// 		*	movement.c
int		movement(int keycode, t_cub *cub);
// 		*	rotation.c
void	rotation(t_player *player, int direction);
// 		*	rays.c
void	cast_rays(t_cub *cub);

// ******************** APP UTILS ******************** //

// 		*	exit.c
void	exit_failure(t_cub *cub, char *err_msg);
int		exit_success(t_cub *cub);
// 		*	init.c
void	init(t_cub *cub, char *input_file);
// 		*	utils.c
void	use_atoi(t_cub *cub, char *str_nbr, int *counter);
void	calculate_angle(t_cub *cub, char direction);
void	calculate_center(double x, double y, int *center_x, int *center_y);
void	calculate_deltas(t_player *player, int keycode, double *dx, double *dy);
// 		*	mlx.c
// void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		create_rgb(int *color_arr);

// ******************** EXCUTION ******************** //

/*-------------------INIT-------------------*/
// t_map  *init_argument();
// char    **init_map();
// void    init_player_map(t_cub cube);

int execution(t_cub *cub);

/*-------------------GAME-------------------*/
void    start_the_game(t_cub *data);
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
void draw_wall(t_cub *mlx, int t_pix, int b_pix, double wall_h);
void render_wall(t_cub *mlx, int ray);

/*-------------------TEXTURE-------------------*/
t_txtdata *get_txt(t_cub *mlx, int flag);
void init_txtures(t_cub *cube);
t_txtdata *get_txt(t_cub *mlx, int flag);
double texture_x(t_cub *mlx, t_txtdata *texture, int flag);
void draw_floor_ceiling(t_cub *mlx, int ray, int t_pix, int b_pix);


/*-------------------MOVEMENT-------------------*/
void    hook(t_cub *mlx, double move_x, double move_y);
void    move_player(t_cub *mlx, double move_x, double move_y);
void    rotate_player(t_cub *mlx, int flag);
int     mlx_key(mlx_key_data_t keydata, void *ml);
int     key_reles(mlx_key_data_t keydata, t_cub *mlx);

/*-------------------UTILS-------------------*/
// void    ft_exit(t_cub *mlx);

// *************************** DELETE ME *************************** //
void	print_textures(t_cub *cub);
void	print_file(t_cub *cub);
void	print_map(t_cub *cub);
void	print_player(t_cub *cub);
t_map 	*init_argument();
void 	init_player_data(t_cub cub);


// ***************************************************************** //

#endif
