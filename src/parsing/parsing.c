/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:23:56 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/17 22:52:51 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	file_len(t_cub *cub, char *input_file);
static void	file_create(t_cub *cub, t_file *file, char *input_file);
static void	map_create(t_cub *cub, t_file *file, int st, int end);
static void	map_validate(t_cub *cub, t_file *file, char **map, char invalid);

void	parsing(t_cub *cub, char *input_file)
{
	t_file	*file;
	int		len;

	file = &cub->file;
	len = cub->file.filename_len;
	if ((len - 4) <= 0 || ft_strcmp(".cub", input_file + (len - 4)))
		exit_failure(cub, INVALID_FILE_NAME);
	file_len(cub, input_file);
	file_create(cub, &cub->file, input_file);
	validate_file(cub, &cub->file);
	map_create(cub, file, file->map_st, file->map_end);
	map_validate(cub, file, file->map, '\0');
}

static void	file_len(t_cub *cub, char *input_file)
{
	int		fd;
	t_gnl	ret;

	fd = open(input_file, O_RDONLY);
	if (fd == -1)
		exit_failure(cub, INVALID_FD);
	while (fd >= 0)
	{
		ret = ft_get_next_line(fd);
		if (ret.error)
			return ((void)close(fd), exit_failure(cub, READ_ERR));
		if (!ret.line)
			break ;
		ft_free(&ret.line, 'p');
		cub->file.file_len++;
	}
	close(fd);
	if (!cub->file.file_len)
		exit_failure(cub, INVALID_FILE_EMPTY);
}

static void	file_create(t_cub *cub, t_file *file, char *input_file)
{
	int		fd;
	int		idx;
	t_gnl	ret;

	fd = open(input_file, O_RDONLY);
	if (fd == -1)
		exit_failure(cub, INVALID_FD);
	file->file_arr = (char **)ft_calloc(file->file_len + 1, sizeof(char *));
	if (!file->file_arr)
		exit_failure(cub, MALLOC_ERR);
	idx = 0;
	while (fd >= 0)
	{
		ret = ft_get_next_line(fd);
		if (ret.error)
			return ((void)close(fd), exit_failure(cub, READ_ERR));
		if (!ret.line)
			break ;
		file->file_arr[idx++] = ret.line;
	}
	close(fd);
}

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
	if (file->map_height < MIN_HEIGHT || file->map_height > MAX_HEIGHT)
		exit_failure(cub, MAP_HEIGHT_ERR);
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
				return (exit_failure(cub, SPACE_ERR));
			if (x < file->map_width - 1 && map[y][x + 1] == invalid)
				return (exit_failure(cub, SPACE_ERR));
			if (y > 0 && map[y - 1][x] == invalid)
				return (exit_failure(cub, SPACE_ERR));
			if (y < file->map_height - 1 && map[y + 1][x] == invalid)
				return (exit_failure(cub, SPACE_ERR));
		}
	}
}

/*
 
there's 2 walls but both below the player, the last wall isn't a wall
1
1111             1111
11011           1111
1N11 1             111
11111011

*/