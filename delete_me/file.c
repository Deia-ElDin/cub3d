/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:36:02 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/17 18:26:14 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	file_name(t_cub *cub, char *input_file)
{
	int	len;

	len = cub->file.filename_len;
	if ((len - 4) <= 0 || ft_strcmp(".cub", input_file + (len - 4)))
		exit_failure(cub, INVALID_FILE_NAME);
}

static void	file_len(t_cub *cub, char *input_file)
{
	int		fd;
	t_gnl	ret;

	fd = open(input_file, O_RDONLY);
	if (fd == -1)
		exit_failure(cub, INVALID_FD);
	while (fd >= 0)
	{
		ret = ft_get_next_line(fd);
		if (ret.error)
			return ((void)close(fd), exit_failure(cub, READ_ERR));
		if (!ret.line)
			break ;
		ft_free(&ret.line, 'p');
		cub->file.file_len++;
	}
	close(fd);
	if (!cub->file.file_len)
		exit_failure(cub, INVALID_FILE_EMPTY);
}

static void	file_create(t_cub *cub, t_file *file, char *input_file)
{
	int		fd;
	int		idx;
	t_gnl	ret;

	fd = open(input_file, O_RDONLY);
	if (fd == -1)
		exit_failure(cub, INVALID_FD);
	file->file_arr = (char **)ft_calloc(file->file_len + 1, sizeof(char *));
	if (!file->file_arr)
		exit_failure(cub, MALLOC_ERR);
	idx = 0;
	while (fd >= 0)
	{
		ret = ft_get_next_line(fd);
		if (ret.error)
			return ((void)close(fd), exit_failure(cub, READ_ERR));
		if (!ret.line)
			break ;
		file->file_arr[idx++] = ret.line;
	}
	close(fd);
}

void	file(t_cub *cub, char *input_file)
{
	file_name(cub, input_file);
	file_len(cub, input_file);
	file_create(cub, &cub->file, input_file);
	validate_file(cub, &cub->file);
}

/*
	*	file_name(cub);
		- check if the file name is valid
		- we get the length of the file name
		- we check if the file name is less than 4 characters (.cub)
		- we check if the file name does not end with .cub
		- if the file name is invalid we exit with INVALID_FILE_NAME	
		
	*	file_len(cub, input_file);
		- get the number of lines in the file
		- we open the file we make sure we have a valid fd
		- we read the file line by line and increment the file_len 
		- if (!ret.line) == GNL returned NULL == no malloc, so we break
		- we close the file
		- if the file_len is 0 we exit with INVALID_FILE_NAME

	*	file_create(cub, &cub->file, input_file);
		- read the file and store it in file_arr
		- we open the file we make sure we have a valid fd
		- we read the file line by line and store it in file_arr
		- if (!ret.line) == GNL returned NULL == no malloc, so we break
		- we close the file

	*	validate_file(cub, &cub->file, cub->file.file_arr);
		-	validate the whole file (elements and map)
*/	
