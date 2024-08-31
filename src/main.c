/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:23:54 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/31 13:34:02 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
		return (0);
	init(&cub, av[1]);
	cub.mlx_ptr = mlx_init();
	if (!cub.mlx_ptr)
		exit_failure(&cub, MLX_ERR);
	parsing(&cub, av[1]);
	start_the_game(&cub);
	return (0);
}
