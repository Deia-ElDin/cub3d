/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:10:53 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/18 12:05:27 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static int	file_len(t_map *map, int fd, const char *file)
// {
// 	t_gnl	ret;
// 	int		len;

// 	len = (int)ft_strlen(file);
// 	if ((len - 4) <= 0 || ft_strcmp(".cub", file + (len - 4)))
// 		exit_error(map, INVALID_FD_NAME);
// 	fd = open(file, O_RDONLY);
// 	if (fd == -1)
// 		exit_error(map, FD_ERR);
// 	len = 0;
// 	while (fd >= 0)
// 	{
// 		ret = ft_get_next_line(fd);
// 		if (!ret.line)
// 			break ;
// 		free(ret.line);
// 		len++;
// 	}
// 	if (!len)
// 	{
// 		close(fd);
// 		exit_error(map, MAP_EMPTY_ERR);
// 	}
// 	map->lines = len;
// 	return ((void)close(fd), len);
// }

// void	map_read(t_map *map, const char *file)
// {
// 	int		fd;
// 	int		len;
// 	t_gnl	ret;

// 	fd = open(file, O_RDONLY);
// 	if (fd == -1)
// 		exit_error(map, FD_ERR);
// 	len = map_height(map, fd, file);
// 	map->arr = (char **)ft_calloc(len + 1, sizeof(char *));
// 	map->cpy = (char **)ft_calloc(len + 1, sizeof(char *));
// 	if (!map->arr || !map->cpy)
// 		exit_error(map, MALLOC_ERR);
// 	len = 0;
// 	while (fd >= 0)
// 	{
// 		ret = ft_get_next_line(fd);
// 		if (ret.error)
// 			return ((void)close(fd), exit_error(map, READ_ERR));
// 		if (!ret.line)
// 			break ;
// 		map->arr[len] = ret.line;
// 		map->cpy[len] = ft_strdup(ret.line);
// 		len++;
// 	}
// 	close(fd);
// }

// void	map_parsing(t_map *map)
// {
// 	map->height = (map->lines + 1) * PX;
// 	map->width = (ft_strlen(map->arr[0]) - 1) * PX;
// 	if (map->height == map->width)
// 		exit_error(map, SQR_MAP_ERR);
// 	parse_lineslength(map, map->arr, map->lines);
// 	parse_chars(map, map->arr, map->lines);
// 	parse_counters(map, map->arr);
// 	parse_validpath(map, map->cords.x, map->cords.y);
// 	ft_free(&(map->cpy), 'a');
// 	if (!map->is_valid)
// 		exit_error(map, PATH_ERR);
// }

// void	map_draw(t_vars *vars)
// {
// 	char	**arr;
// 	int		x;
// 	int		y;

// 	arr = vars->map.arr;
// 	y = 0;
// 	while (arr[y])
// 	{
// 		x = 0;
// 		while (arr[y][x] && arr[y][x] != '\n')
// 		{
// 			if (arr[y][x] != '1' && arr[y][x] != '0')
// 				draw_img(vars, '0', x, y);
// 			draw_img(vars, arr[y][x], x, y);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// int	map_updates(t_vars *vars)
// {
// 	static int	delay;
// 	int			x;
// 	int			y;

// 	y = 1;
// 	if (delay == 5000)
// 	{
// 		update_steps(vars);
// 		spirit_animation(vars);
// 		while (vars->map.arr[y])
// 		{
// 			x = 1;
// 			while (vars->map.arr[y][x] && vars->map.arr[y][x] != '\n')
// 			{
// 				delete_attack(vars, x, y);
// 				x = monster_move(vars, x, y);
// 				x++;
// 			}
// 			y++;
// 		}
// 		delay = 0;
// 	}
// 	delay++;
// 	return (0);
// }
