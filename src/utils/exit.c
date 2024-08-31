/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:38:30 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/31 11:57:57 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	exit_clean(t_cub *cub)
{
	ft_free(&cub->file.file_arr, 'a');
	ft_free(&cub->map->map_arr, 'a');
	if (cub->txtrs)
	{
		// mlx_distory_image(cub->mlx_ptr, cub->txtrs->no->img);
		// mlx_distory_image(cub->mlx_ptr, cub->txtrs->so->img);
		// mlx_distory_image(cub->mlx_ptr, cub->txtrs->we->img);
		// mlx_distory_image(cub->mlx_ptr, cub->txtrs->ea->img);
		ft_free(&cub->txtrs->no, 'p');
		ft_free(&cub->txtrs->so, 'p');
		ft_free(&cub->txtrs->we, 'p');
		ft_free(&cub->txtrs->ea, 'p');
		ft_free(&cub->txtrs, 'p');
	}
	ft_free(&cub->map, 'p');
	ft_free(&cub->player, 'p');
	// if (cub->img->img)
	// 	mlx_destroy_image(cub->mlx_ptr, cub->img->img);
	ft_free(&cub->img, 'p');
	ft_free(&cub->ray, 'p');
	// if (cub->win_ptr)
	// 	mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
	// ft_free(&cub->mlx_ptr, 'p');
}

void	exit_failure(t_cub *cub, char *err_msg)
{
	exit_clean(cub);
	if (*err_msg)
		ft_printf(2, "%s\n", err_msg);
	exit(EXIT_FAILURE);
}

int	exit_success(t_cub *cub)
{
	exit_clean(cub);
	exit(EXIT_SUCCESS);
	return (0);
}
