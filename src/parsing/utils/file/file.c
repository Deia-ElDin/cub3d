/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:36:02 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/15 22:52:52 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static void	file_read(t_cub *cub, t_file *file, char *input_file)
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

static void	file_validate_elements(t_cub *cub, t_file *file, char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (ft_strnstr(line, "NO", len))
		file->no_path = validate_img(cub, line);
	else if (ft_strnstr(line, "SO", len))
		file->so_path = validate_img(cub, line);
	else if (ft_strnstr(line, "WE", len))
		file->we_path = validate_img(cub, line);
	else if (ft_strnstr(line, "EA", len))
		file->ea_path = validate_img(cub, line);
	else if (ft_strnstr(line, "F", len))
		validate_color(cub, file->f_color, line);
	else if (ft_strnstr(line, "C", len))
		validate_color(cub, file->c_color, line);
	if (is_elements_ready(file))
		file->stage++;
}

// static void	file_validation(t_cub *cub, t_file *file, char **file_arr)
// {
// 	int	i;

// 	i = 0;
// 	(void)file;
// 	while (file_arr[i])
// 	{
// 		while (file->stage == 1 && ft_isempty_str(file_arr[i]))
// 			i++;
// 		if (file->stage == 1 && is_map_line(file_arr[i]))
// 		{
// 			printf("\nis_map_line[%d] && stage 1 = %s.\n", i + 1, file_arr[i]);
// 			exit_failure(cub, MAP_ERR);
// 		}
// 		else if (file->stage == 1 && is_element_line(file_arr[i]))
// 			file_validate_elements(cub, file, file_arr[i++]);
// 		else
// 			i++;
// 	}
// 	if (!is_elements_ready(file))
// 		exit_failure(cub, ELEMENTS_ERR);
// }


static void	file_validation(t_cub *cub, t_file *file, char **file_arr)
{
	int	i;
	int	st;
	int	end;

	i = 0;
	st = 0;
	end = 0;
	while (file_arr[i] && file->stage == 1)
	{
		if (ft_isempty_str(file_arr[i]))
			i++;
		else if (is_element_line(file_arr[i]))
			file_validate_elements(cub, file, file_arr[i++]);
		else 
			exit_failure(cub, MAP_ERR);
	}
	while (file_arr[i] && file->stage == 2)
	{
		while (file_arr[i] && ft_isempty_str(file_arr[i]))
			i++;
		if (!st && !is_element_line(file_arr[i]))
			st = i++;
		else if (st && !is_element_line(file_arr[i]))
			end = i++;
	}
	// printf("\n\nst = %d, end = %d\n\n", st, end);
}

void	file(t_cub *cub, char *input_file)
{
	int	len;

	len = cub->file.filename_len;
	if ((len - 4) <= 0 || ft_strcmp(".cub", input_file + (len - 4)))
		exit_failure(cub, INVALID_FILE_NAME);
	file_len(cub, input_file);
	file_read(cub, &cub->file, input_file);
	ft_printf(1, "%a", cub->file.file_arr);
	// printf("*cub->file.file_arr[20] = %d", *cub->file.file_arr[20]);
	file_validation(cub, &cub->file, cub->file.file_arr);
	// ft_printf(1, "%a", cub->file.map_arr);
	// 	print_file_paths(cub);
}

/*
	*	if ((len - 4) <= 0 || ft_strcmp(".cub", input_file + (len - 4)))
		- len -  4 <= 0 === the file name is less than 4 characters (.cub)
		- ft_strcmp(".cub", input_file + (len - 4)) === the file name does not end with .cub
		
	*	file_len(cub, input_file);
		- get the number of lines in the file
		- we open the file we make sure we have a valid fd
		- we read the file line by line and increment the file_len 
		- if (!ret.line) == GNL returned NULL == no malloc, so we break
		- we close the file
		- if the file_len is 0 we exit with INVALID_FILE_NAME

	*	file_read(cub, &cub->file, input_file);
		- read the file and store it in file_arr
		- we open the file we make sure we have a valid fd
		- we read the file line by line and store it in file_arr
		- if (!ret.line) == GNL returned NULL == no malloc, so we break
		- we close the file

	*	file_validation(cub, &cub->file, cub->file.file_arr);
	
*/	

