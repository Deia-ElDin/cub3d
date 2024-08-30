/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:23:54 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/30 21:01:05 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
		return (0);
	if (!cub.mlx_ptr)
		exit_failure(&cub, MLX_ERR);
	init(&cub, av[1]);
	cub.mlx_ptr = mlx_init();
	parsing(&cub, av[1]);
	execution(&cub);
	return (0);
}
