/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:38:30 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/29 19:51:34 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	exit_clean(t_cub *cub)
{
	ft_free(&cub->file.file_arr, 'a');
	ft_free(&cub->map->map_arr, 'a');
	if (cub->txtrs)
	{
		free(cub->txtrs->no);
		free(cub->txtrs->so);
		free(cub->txtrs->we);
		free(cub->txtrs->ea);
		free(cub->txtrs);
	}
	free(cub->map);
	free(cub->player);
	free(cub->img);
	free(cub->ray);
	if (cub->mlx_ptr)
		free(cub->mlx_ptr);
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
