/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_me.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:23:51 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/15 19:08:53 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_file_paths(t_cub *cub)
{
	t_file	*file;

	file = &cub->file;
	ft_printf(1, "\nPrint File Paths\n");
	if (file->no_path)
		ft_printf(1, "NO Path = %s\n", file->no_path);
	if (file->so_path)
		ft_printf(1, "SO Path = %s\n", file->so_path);
	if (file->we_path)
		ft_printf(1, "WE Path = %s\n", file->we_path);
	if (file->ea_path)
		ft_printf(1, "EA Path = %s\n", file->ea_path);
	// if (file->c_color)
	// 	ft_printf(1, "C Path = %s\n", file->c_color);
	// if (file->f_color)
	// 	ft_printf(1, "F Path = %s\n", file->f_color);
}


// bool	is_empty_line(char *line)
// {
// 	if (!line)
// 		return (false);
// 	while (*line)
// 	{
// 		while (*line == ' ')
// 			line++;
// 		if (!*line || *line == '\n')
// 			return (true);
// 		else
// 			return (false);
// 	}
// 	return (true);
// }


// void	validate_img(t_cub *cub, void *ptr, char *path)
// {
// 	int		width;
// 	int		height;

// 	img = mlx_xpm_file_to_image(cub->mlx, path, &width, &height);
// 	if (!img)
// 		exit_failure(cub, IMG_ERR);
// }