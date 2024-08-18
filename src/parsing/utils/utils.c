/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:06:13 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/18 14:47:49 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_color(t_cub *cub, char *line, int *color_idx, int *color_arr)
{
	if (!line || !*line)
		return (0);
	if (*line && ft_isdigit(*line))
	{
		if (*color_idx == 3)
			exit_failure(cub, COLOR_ERR);
		use_atoi(cub, line, &color_arr[(*color_idx)]);
		return (ft_intlen(color_arr[(*color_idx)++]));
	}
	return (0);
}

bool	is_elements_ready(t_file *file)
{
	if (ft_isempty_str(file->no_path)
		|| ft_isempty_str(file->so_path)
		|| ft_isempty_str(file->we_path)
		|| ft_isempty_str(file->ea_path)
		|| file->is_valid_colors != 2)
		return (false);
	return (true);
}

void	is_player(t_cub *cub, char *map_line)
{
	int		i;

	if (!map_line || !*map_line)
		return ;
	i = 0;
	while (map_line[i])
	{
		if (!isspace(map_line[i]) && map_line[i] != '0' && map_line[i] != '1')
		{
			if (!ft_strchr("NSWE", map_line[i]))
				exit_failure(cub, MAP_CHARS_ERR);
			cub->file.player_position = map_line[i];
			cub->file.player_counter++;
		}
		i++;
	}
	if (cub->file.player_counter > 1)
		exit_failure(cub, MAP_CHARS_ERR);
}

void	set_map_width(t_file *file, char *map_line)
{
	int	len;

	len = (int)ft_strlen(map_line);
	if (len > file->map_width)
		file->map_width = len;
}

char	*set_map_line(t_cub *cub, t_file *file, char *map_line)
{
	int		len;
	int		diff;
	char	*tmp;
	char	*fill;
	char	*res;

	len = (int)ft_strlen(map_line);
	tmp = ft_strdup(map_line);
	if (!tmp)
		exit_failure(cub, MALLOC_ERR);
	if (len == file->map_width)
		return (tmp);
	diff = file->map_width - len;
	fill = ft_calloc(diff + 1, sizeof(char));
	if (!fill)
		exit_failure(cub, MALLOC_ERR);
	while (diff--)
		fill[diff] = ' ';
	res = ft_strjoin(tmp, fill);
	if (!res)
		exit_failure(cub, MALLOC_ERR);
	return (ft_free(&tmp, 'p'), ft_free(&fill, 'p'), res);
}
