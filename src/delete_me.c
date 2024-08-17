/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_me.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:23:51 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/17 21:38:04 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_elements(t_cub *cub)
{
	t_file	*file;

	file = &cub->file;
	ft_printf(1, "\nPrint Elements\n");
	if (file->no_path)
		ft_printf(1, "NO Path = %s\n", file->no_path);
	if (file->so_path)
		ft_printf(1, "SO Path = %s\n", file->so_path);
	if (file->we_path)
		ft_printf(1, "WE Path = %s\n", file->we_path);
	if (file->ea_path)
		ft_printf(1, "EA Path = %s\n", file->ea_path);
	if (file->c_color[0] != -1)
		ft_printf(1, "C Colors = %d, %d, %d\n",
			file->c_color[0], file->c_color[1], file->c_color[2]);
	if (file->f_color[0] != -1)
		ft_printf(1, "F Colors = %d, %d, %d\n",
			file->f_color[0], file->f_color[1], file->f_color[2]);
}
