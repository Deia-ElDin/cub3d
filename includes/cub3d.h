/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:23:43 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/22 20:44:36 by dehamad          ###   ########.fr       */
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

// ******************** Constants ******************** //

# define SCREEN_HEIGHT 720
# define SCREEN_WIDTH 1280
# define TILE_SIZE 30
# define FOV 60 
# define ROTATION_SPEED 0.2
# define PLYR_SPEED 4

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
	char	plyr_direction;
}	t_map;

typedef struct s_player
{
	double	plyr_x;
	double	plyr_y;
	double	angle;
	float	fov_rd;
	int		rot;
	int		l_r;
	int		u_d;
}	t_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_ray
{
	double	ray_ngl;
	double	distance;
	int		flag;
}	t_ray;

typedef struct s_cub
{
	void		*mlx;
	void		*win;
	t_file		file;
	t_texture	texture;
	t_map		map;
	t_player	player;
	t_img		img;
	t_ray		ray;
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

void	execution(t_cub *cub);

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
// 		*	mlx.c
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		create_rgb(int *color_arr);
// 		*	math.c
void	calculate_angle(t_cub *cub, char direction);
void	calculate_center(double x, double y, int *center_x, int *center_y);
void	calculate_deltas(t_player *player, int keycode, double *dx, double *dy);

// ********************** EXEC ********************** //
void	exec(t_cub *cub);
void	rotate_player(t_cub *cub, int direction);
void	move_player(t_cub *cub, double move_x, double move_y);
void	cub_hook(t_cub *cub, double move_x, double move_y);
void	ft_reles(int keycode, t_cub *cub);
void	key_press(int keycode, void *cb);
int inter_check(float angle, float *inter, float *step, int is_horizon);
int wall_hit(float x, float y, t_cub *cub);
float get_h_inter(t_cub *cub, float angl);
float get_v_inter(t_cub *cub, float angl);
void cast_rays(t_cub *cub);
void	draw_floor_ceiling(t_texture *texture, t_img *img, int ray, int t_pix, int b_pix);
void	*get_texture(t_texture *texture, t_ray *ray);
double	get_x_o(void *texture, t_ray *ray);
void	draw_wall(t_img *img, t_ray *ray, t_texture *texture, int t_pix, int b_pix, double wall_h);
void	render_wall(t_cub *cub, int ray);
int	get_rgba(int r, int g, int b, int a);
int	reverse_bytes(int c);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
float	normalize_angle(float angle);
int	unit_circle(float angle, char c);
// ************************************************** //
// ************************************************** //
// ************************************************** //

// *************************** DELETE ME *************************** //
void	print_textures(t_cub *cub);
void	print_file(t_cub *cub);
void	print_map(t_cub *cub);
void	print_player(t_cub *cub);

# define MINI_TILE_SIZE 30
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define GRAY 0x808080
# define YELLOW 0xFF00FF
// ***************************************************************** //

#endif
