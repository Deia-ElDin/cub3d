/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:27:03 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/15 22:58:33 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*validate_img(t_cub *cub, char *line)
{
	char	**split;
	// char	*clean_path;
	void	*img;
	int		width;
	int		height;

	split = ft_split(line, ' ');
	if (!split)
		exit_failure(cub, MALLOC_ERR);
	if ((!split[0] || !split[1] || split[2]) && (ft_free(&split, 'a'), 1))
		exit_failure(cub, ELEMENTS_ERR);
	// clean_path = ft_strtrim(split[1], " \n\t");
	// ft_free(&split, 'a');
	// if (!clean_path)
	// 	exit_failure(cub, MALLOC_ERR);
	img = mlx_xpm_file_to_image(cub->mlx, split[1], &width, &height);
	ft_free(&split, 'a');
	if (!img)
		exit_failure(cub, IMG_ERR);
	return (img);
}
