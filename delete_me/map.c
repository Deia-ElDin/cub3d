/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:05:13 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/18 12:06:57 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_create(t_cub *cub, t_file *file, int st, int end)
{
	int	idx;

	file->map = ft_calloc(file->map_height + 1, sizeof(char *));
	if (!file->map)
		exit_failure(cub, MALLOC_ERR);
	idx = 0;
	while (file->file_arr[st] && *file->file_arr[st] && st <= end)
	{
		if (idx == 0 && !ft_iswall(file->file_arr[st]) && ++st)
			continue ;
		file->map[idx] = set_map_line(cub, file, file->file_arr[st]);
		if (!file->map[idx])
			exit_failure(cub, MALLOC_ERR);
		st++;
		idx++;
	}
	file->map_end = st;
	file->map_height = file->map_end - file->map_st;
	if (file->map_height < 3)
		exit_failure(cub, MAP_HEIGHT_ERR);
}

bool	is_valid_pos(t_file *file, int y, int x)
{
	char	**map;
	char	invalid;

	map = file->map;
	if (map[y][x] == ' ')
		invalid = '0';
	else if (map[y][x] == file->player_position)
		invalid = ' ';
	if (x > 0 && map[y][x - 1] == invalid)
		return (false);
	if (x < file->map_width - 1 && map[y][x + 1] == invalid)
		return (false);
	if (y > 0 && map[y - 1][x] == invalid)
		return (false);
	if (y < file->map_height - 1 && map[y + 1][x] == invalid)
		return (false);
	return (true);
}

static void	map_validate(t_cub *cub, t_file *file, char **map, char invalid)
{
	int		y;
	int		x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == ' ')
				invalid = '0';
			else if (map[y][x] == file->player_position)
				invalid = ' ';
			else
				continue ;
			if (x > 0 && map[y][x - 1] == invalid)
				return (exit_failure(cub, MAP_SPACE_ERR));
			if (x < file->map_width - 1 && map[y][x + 1] == invalid)
				return (exit_failure(cub, MAP_SPACE_ERR));
			if (y > 0 && map[y - 1][x] == invalid)
				return (exit_failure(cub, MAP_SPACE_ERR));
			if (y < file->map_height - 1 && map[y + 1][x] == invalid)
				return (exit_failure(cub, MAP_SPACE_ERR));
		}
	}
}

// ' ' =>  !0 !P
// P   =>  !' '

void	map(t_cub *cub)
{
	t_file	*file;

	file = &cub->file;
	map_create(cub, file, file->map_st, file->map_end);
	map_validate(cub, file, file->map, '\0');
}
// printf("map->width = %d\n", file->map_width);
// ft_printf(1, "%a", file->map);

// static int	space_is_validpath(t_file *file, char **map_cpy, int x, int y)
// {
// 	int		i;
// 	int		j;

// 	i = 1;
// 	if (map_cpy[y][x] != '1')
// 	{
// 		map_cpy[y][x] = '1';
// 		while (map_cpy[i] && i < map->lines - 1)
// 		{
// 			j = 1;
// 			while (map_cpy[i][j] && map_cpy[i][j] != '\n')
// 			{
// 				if (map_cpy[i][j] == 'E' || map_cpy[i][j] == 'C')
// 					return (1);
// 				j++;
// 			}
// 			i++;
// 		}
// 		file->is_valid_map = true;
// 	}
// 	return (0);
// }

// void	map_validate_spaces(t_cub *cub, t_file *file)
// {
// 	file->cpy_arr[y][x] = '1';
// 	if (!file->is_valid_map && space_is_valid(file, map, x, y - 1))
// 		parse_validpath(map, x, y - 1);
// 	if (!file->is_valid_map && space_is_valid(file, map, x + 1, y))
// 		parse_validpath(map, x + 1, y);
// 	if (!file->is_valid_map && space_is_valid(file, map, x, y + 1))
// 		parse_validpath(map, x, y + 1);
// 	if (!file->is_valid_map && space_is_valid(file, map, x - 1, y))
// 		parse_validpath(map, x - 1, y);
// }

// static void	map_read(t_cub *cub, t_file *file, int st)
// {
// 	int	i;

// 	if (!file->map_st || !file->map_end)
// 		exit_failure(cub, MAP_ERR);
// 	file->map_height = file->map_end - file->map_st;
// 	if (file->map_height < MIN_HEIGHT || file->map_height > MAX_HEIGHT)
// 		exit_failure(cub, MAP_ERR);
// 	while (file->file_arr[st] && st <= file->map_end)
// 	{
// 		i = -1;
// 		while (file->file_arr[st][++i])
// 			if (!ft_isdigit(file->file_arr[st][i])
// 				&& !isspace(file->file_arr[st][i]))
// 				file->player_counter++;
// 		if (file->wall_counter < 2 && !ft_ismap_line(file->file_arr[st]))
// 			exit_failure(cub, MAP_ERR);
// 		else if (file->wall_counter >= 2 && !ft_isempty_str(file->file_arr[st]))
// 			exit_failure(cub, MAP_ERR);
// 		else if (ft_iswall(file->file_arr[st]))
// 			file->wall_counter++;
// 		st++;
// 		i++;
// 	}
// 	if (file->player_counter != 1 || file->wall_counter != 2)
// 		exit_failure(cub, MAP_ERR);
// }

// static void	map_read(t_cub *cub, t_file *file)
// {
// 	int	st;
// 	int	line_len;
// 	int	biggest_len;
// 	int	wall_counter;

// 	if (!file->map_st || !file->map_end)
// 		exit_failure(cub, MAP_ERR);
// 	file->map_height = file->map_end - file->map_st;
// 	if ((file->map_end - file->map_st) < 3)
// 		exit_failure(cub, MAP_ERR);
// 	st = file->map_st;
// 	line_len = 0;
// 	biggest_len = 0;
// 	wall_counter = 0;
// 	while (file->file_arr[st] && st <= file->map_end)
// 	{
// 		if (ft_iswall(file->file_arr[st]))
// 			wall_counter++;
// 		else if (!ft_ismap_line(file->file_arr[st]))
// 			exit_failure(cub, MAP_ERR);
// 		line_len = ft_strlen(file->file_arr[st]);
// 		if (line_len > biggest_len)
// 			biggest_len = line_len;
// 		st++;
// 	}
// 	file->map_line_len = biggest_len;
// 	printf("\n wall_counter = %d\n", wall_counter);
// 	printf("\n map_line_len = %d\n", file->map_line_len);
// }

// void	map_validate_empty_lines(t_cub *cub, t_file *file, int st)
// {
// 	int	i;

// 	if (!file->map_st || !file->map_end)
// 		exit_failure(cub, MAP_ERR);
// 	file->map_height = file->map_end - file->map_st;
// 	if (file->map_height < MIN_HEIGHT || file->map_height > MAX_HEIGHT)
// 		exit_failure(cub, MAP_ERR);
// 	while (file->file_arr[st] && st <= file->map_end)
// 	{
// 		i = -1;
// 		while (file->file_arr[st][++i])
// 			if (!ft_isdigit(file->file_arr[st][i])
// 				&& !isspace(file->file_arr[st][i]))
// 				file->player_counter++;
// 		if (file->wall_counter < 2 && !ft_ismap_line(file->file_arr[st]))
// 			exit_failure(cub, MAP_ERR);
// 		else if (file->wall_counter >= 2 && !ft_isempty_str(file->file_arr[st]))
// 			exit_failure(cub, MAP_ERR);
// 		else if (ft_iswall(file->file_arr[st]))
// 			file->wall_counter++;
// 		st++;
// 		i++;
// 	}
// 	if (file->player_counter != 1 || file->wall_counter != 2)
// 		exit_failure(cub, MAP_ERR);
// }

// void	map_validate_spaces(t_cub *cub, t_file *file)
// {
// 	int		x;
// 	int		y;
// 	char	letter;

// 	y = 0;
// 	while (file->map[y])
// 	{
// 		x = 0;
// 		while (file->map[y][x])
// 		{
// 			letter = file->map[y][x];
// 			if (letter == ' ' || letter == file->player_position)
// 			{
// 				if (y == 0 || y == file->map_height - 1
// 					|| x == 0 || x == file->map_line_len - 1)
// 					exit_failure(cub, MAP_ERR);
// 				if (file->map[y - 1][x] == ' '
// 					|| file->map[y + 1][x] == ' '
// 					|| file->map[y][x - 1] == ' '
// 					|| file->map[y][x + 1] == ' ')
// 					exit_failure(cub, MAP_ERR);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

// static void	map_create(t_cub *cub, t_file *file, int st, int end)
// {
// 	int	idx;

// 	file->map = (t_map *)ft_calloc(file->map_height + 1, sizeof(t_map));
// 	if (!file->map)
// 		exit_failure(cub, MALLOC_ERR);
// 	idx = 0;
// 	while (file->file_arr[st] && *file->file_arr[st] && st <= end)
// 	{
// 		if (idx == 0 && !ft_iswall(file->file_arr[st]) && ++st)
// 			continue ;
// 		file->map[idx].line = ft_strdup(file->file_arr[st]);
// 		if (!file->map[idx].line)
// 			exit_failure(cub, MALLOC_ERR);
// 		file->map[idx].len = ft_strlen(file->file_arr[st]);
// 		st++;
// 		idx++;
// 	}
// 	file->map_end = st;
// 	file->map_height = file->map_end - file->map_st;
// 	if (file->map_height < MIN_HEIGHT || file->map_height > MAX_HEIGHT)
// 		exit_failure(cub, MAP_HEIGHT_ERR);
// }

// bool	is_valid_pos(t_file *file, int y, int x, int invalid)
// {
// 	char	**map;

// 	map = file->map;
// 	if (y == 0)
// 	{
// 		if (x == 0)
// 			return (map[y][x + 1] != invalid || map[y + 1][x] != invalid);
// 		else if (x == file->map_width - 1)
// 			return (map[y][x - 1] != invalid || map[y + 1][x] != invalid);
// 		else
// 			return (map[y][x - 1] != invalid || map[y][x + 1] != invalid
// 				|| map[y + 1][x] != invalid);
// 	}
// 	else if (y == file->map_height - 1)
// 	{
// 		if (x == 0)
// 			return (map[y][x + 1] != invalid || map[y - 1][x] != invalid);
// 		else if (x == file->map_width - 1)
// 			return (map[y][x - 1] != invalid || map[y - 1][x] != invalid);
// 		else
// 			return (map[y][x - 1] != invalid || map[y][x + 1] != invalid
// 				|| map[y - 1][x] != invalid);
// 	}
// 	else
// 	{
// 		if (x == 0)
// 			return (map[y][x + 1] != invalid
// 				|| map[y - 1][x] != invalid || map[y + 1][x] != invalid);
// 		if (x == file->map_width - 1)
// 			return (map[y][x - 1] != invalid
// 				|| map[y - 1][x] != invalid || map[y + 1][x] != invalid);
// 		else
// 			return (map[y][x - 1] != invalid || map[y][x + 1] != invalid
// 				|| map[y + 1][x] != invalid || map[y - 1][x] != invalid);
// 	}
// }
