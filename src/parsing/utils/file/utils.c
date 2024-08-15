/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:07:47 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/15 22:47:58 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_element_line(char *line)
{
	while (*line)
	{
		if ((*line == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ')
			|| (*line == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ')
			|| (*line == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ')
			|| (*line == 'E' && *(line + 1) == 'A' && *(line + 2) == ' ')
			|| (*line == 'F' && *(line + 1) == ' ')
			|| (*line == 'C' && *(line + 1) == ' '))
			return (true);
		else
			line++;
	}
	return (false);
}

bool	is_map_line(char *line)
{
	while (*line)
	{
		if (!ft_strchr(MAP_CHARS, *line))
			return (false);
		line++;
	}
	return (true);
}

bool	is_elements_ready(t_file *file)
{
	if (ft_isempty_str(file->no_path)
		|| ft_isempty_str(file->so_path)
		|| ft_isempty_str(file->we_path)
		|| ft_isempty_str(file->ea_path)
		|| file->is_valid_color != 2)
		return (false);
	return (true);
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

void	validate_color(t_cub *cub, int *color_arr, char *line)
{
	int		idx;
	int		commas_counter;
	int		letters_counter;

	idx = 0;
	commas_counter = 0;
	letters_counter = 0;
	while (*line && letters_counter < 2)
	{
		if (*line && ft_issep(*line, ',') && line++)
			commas_counter++;
		if (*line && !ft_isdigit(*line) && !ft_isspace(*line) && !ft_issep(*line, ',') && line++)
			letters_counter++;
		if (*line && ft_isdigit(*line))
		{
			if (idx < 3 && (use_atoi(cub, line, &color_arr[idx]), 1))
				line += ft_intlen(color_arr[idx++]);
			else
				break;
		}
		while (*line && ft_isspace(*line))
			line++;
	}
	if (letters_counter != 1 || commas_counter != 2 || idx != 3 || !++cub->file.is_valid_color)
		exit_failure(cub, COLOR_ERR);
}
