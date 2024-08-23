/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:23:54 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/22 21:04:15 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	execution(&cub);
	// exec(&cub);
	exit_success(&cub);
	return (0);
}
