/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:23:56 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/18 14:41:30 by dehamad          ###   ########.fr       */
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
	print_elements(cub);
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
		if (idx == 0 && ft_isempty_str(file->file_arr[st]) && ++st)
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

static void	map_validate(t_cub *cub, t_file *file, char **map, char invalid)
{
	int		y;
	int		x;

	y = -1;
	printf("map_height: %d\n", file->map_height);
	printf("map_width: %d\n", file->map_width);
	ft_printf(1, "%a", map);
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
	printf("done\n");
}

/*
 .1111                  .
there's 2 walls but both below the player, the last wall isn't a wall

NO        textures/bluestone.png






F    32,     250, 255            0









NO textures/bluestone.xpm
WE textures/greenlight.xpm 
SO textures/colorstone.xpm
EA textures/eagle.xpm

       C  150,150,150
F    32,     250, 255          








 0
1111
1111             1111
1 111           111N1
1 11 1             111
11111011           
     1                                          1
*/
