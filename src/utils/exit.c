/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:38:30 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/29 15:45:34 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	ft_delete_tex(t_texture *texture)
// {
// 	if (texture->no_img)
// 		mlx_delete_texture(texture->no_img);
// 	if (texture->so_img)
// 		mlx_delete_texture(texture->so_img);
// 	if (texture->we_img)
// 		mlx_delete_texture(texture->we_img);
// 	if (texture->ea_img)
// 		mlx_delete_texture(texture->ea_img);
// }

// void	exit_failure(t_cub *cub)
// {
// 	mlx_delete_image(cub->mlx, cub->img.img);
// 	mlx_close_window(cub->mlx);
// 	freelist(&cub->file.file_arr);
// 	free_map(&cub->map);
// 	ft_delete_tex(&cub->texture);
// 	free(cub->texture.no_img);
// 	free(cub->texture.so_img);
// 	free(cub->texture.we_img);
// 	free(cub->texture.ea_img);
// 	free(cub->player);
// 	free(cub->ray);
// 	mlx_terminate(cub->mlx);
// 	ft_putstr_fd("Game closed\n", 1);
// 	exit(0);
// }

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
