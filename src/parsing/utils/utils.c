/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:06:13 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/17 21:57:07 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] && !ft_isdigit(map_line[i]) && !isspace(map_line[i]))
		{
			cub->file.player_position = map_line[i];
			cub->file.player_counter++;
		}
		i++;
	}
	if (cub->file.player_counter > 1)
		exit_failure(cub, PLAYER_ERR);
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

void	use_atoi(t_cub *cub, char *str_nbr, int *counter)
{
	t_atoi	res;
	int		nbr;

	if (!str_nbr || !*str_nbr)
		return (exit_failure(cub, COLOR_ERR));
	res = ft_atoi(str_nbr);
	if (res.error)
		return (exit_failure(cub, COLOR_ERR));
	nbr = (int)res.nbr;
	if (nbr < 0 || nbr > 255)
		return (exit_failure(cub, COLOR_ERR));
	*counter = nbr;
}
