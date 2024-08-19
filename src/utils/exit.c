/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:38:30 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/19 14:19:09 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	exit_clean(t_cub *cub)
{
	// t_file		*file;
	// t_texture	*texture;
	// t_map		*map;

	// file = &cub->file;
	// texture = &cub->texture;
	// map = &cub->map;
	ft_free(&cub->file.file_arr, 'a');
	ft_free(&cub->map.map_arr, 'a');
	// ft_free(&cub->file.no_path, 'p');
	// ft_free(&cub->file.so_path, 'p');
	// ft_free(&cub->file.we_path, 'p');
	// ft_free(&cub->file.ea_path, 'p');
	if (cub->mlx)
		free(cub->mlx);
}

void	exit_failure(t_cub *cub, char *err_msg)
{
	exit_clean(cub);
	if (*err_msg)
		ft_printf(2, "%s\n", err_msg);
	exit(EXIT_FAILURE);
}

void	exit_success(t_cub *cub)
{
	exit_clean(cub);
	exit(EXIT_SUCCESS);
}
