/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:44:37 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/16 11:52:40 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d"

void	elements_validate(t_cub *cub, t_file *file, char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (ft_strnstr(line, "NO", len))
		file->no_path = validate_img(cub, line);
	else if (ft_strnstr(line, "SO", len))
		file->so_path = validate_img(cub, line);
	else if (ft_strnstr(line, "WE", len))
		file->we_path = validate_img(cub, line);
	else if (ft_strnstr(line, "EA", len))
		file->ea_path = validate_img(cub, line);
	else if (ft_strnstr(line, "F", len))
		validate_color(cub, file->f_color, line);
	else if (ft_strnstr(line, "C", len))
		validate_color(cub, file->c_color, line);
	if (is_elements_ready(file))
		file->stage++;
}

