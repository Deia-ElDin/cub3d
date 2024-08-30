/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:23:54 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/30 14:31:47 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
		return (0);
	(void)av;

	
	// cub.map = (t_map *)ft_calloc(1, sizeof(t_map));
	// cub.player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!cub.mlx_ptr)
		exit_failure(&cub, MLX_ERR);
	init(&cub, av[1]);
	cub.mlx_ptr = mlx_init();
	parsing(&cub, av[1]);
	execution(&cub);
	// exec(&cub);
	// exit_success(&cub);
	return (0);
}
