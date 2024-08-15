/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:23:54 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/15 15:47:14 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
		return (0);
	init(&cub, av[1]);
	cub.mlx = mlx_init();
	if (!cub.mlx)
		exit_failure(&cub, MLX_ERR);
	parsing(&cub, av[1]);
	// cub.win = mlx_new_window(cub.mlx, &cub.width, &cub.height, "so_long");
	// if (!cub.win)
	// 	exit_failure(&cub, MLX_ERR);
	return (0);
}

// todo check the file name and what if he passed empty file and should i clean whatever prior to the /