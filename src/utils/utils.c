/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:58:17 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/22 19:33:37 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	use_atoi(t_cub *cub, char *str_nbr, int *counter)
{
	t_atoi	res;
	int		nbr;

	if (!str_nbr || !*str_nbr)
		return (exit_failure(cub, COLOR_ERR));
	res = ft_atoi(str_nbr);
	if (res.error)
		return (exit_failure(cub, COLOR_ERR));
	nbr = (int)res.nbr;
	if (nbr < 0 || nbr > 255)
		return (exit_failure(cub, COLOR_ERR));
	*counter = nbr;
}
