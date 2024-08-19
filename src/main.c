/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:23:54 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/19 14:59:31 by dehamad          ###   ########.fr       */
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
	// print_textures(cub);
	// execution(&cub);
	return (0);
}
