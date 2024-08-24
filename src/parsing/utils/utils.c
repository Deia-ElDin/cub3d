/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:06:13 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/18 15:58:32 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_color(t_cub *cub, char *line, int *color_idx, int *color_arr)
{
	if (!line || !*line)
		return (0);
	if (*line && ft_isdigit(*line))
	{
		if (*color_idx == 3)
			exit_failure(cub, COLOR_ERR);
		use_atoi(cub, line, &color_arr[(*color_idx)]);
		return (ft_intlen(color_arr[(*color_idx)++]));
	}
	return (0);
}

bool	is_elements_ready(t_file *file)
{
	if (ft_isempty_str(file->no_path)
		|| ft_isempty_str(file->so_path)
		|| ft_isempty_str(file->we_path)
		|| ft_isempty_str(file->ea_path)
		|| file->is_valid_colors != 2)
		return (false);
	return (true);
}

void	is_player(t_cub *cub, char *map_line)
{
	int		i;

	if (!map_line || !*map_line)
		return ;
	i = 0;
	while (map_line[i])
	{
		if (!isspace(map_line[i]) && map_line[i] != '0' && map_line[i] != '1')
		{
			if (!ft_strchr("NSWE", map_line[i]))
				exit_failure(cub, MAP_CHARS_ERR);
			cub->file.player_position = map_line[i];
			cub->file.player_counter++;
		}
		i++;
	}
	if (cub->file.player_counter > 1)
		exit_failure(cub, MAP_CHARS_ERR);
}

void	set_map_width(t_file *file, char *map_line)
{
	int	len;

	len = (int)ft_strlen(map_line);
	if (len > file->map_width)
		file->map_width = len;
}

char	*set_map_line(t_cub *cub, t_file *file, char *map_line)
{
	int		len;
	int		diff;
	char	*tmp;
	char	*fill;
	char	*res;

	len = (int)ft_strlen(map_line);
	tmp = ft_strdup(map_line);
	if (!tmp)
		exit_failure(cub, MALLOC_ERR);
	if (len == file->map_width)
		return (tmp);
	diff = file->map_width - len;
	fill = ft_calloc(diff + 1, sizeof(char));
	if (!fill)
		exit_failure(cub, MALLOC_ERR);
	while (diff--)
		fill[diff] = ' ';
	res = ft_strjoin(tmp, fill);
	if (!res)
		exit_failure(cub, MALLOC_ERR);
	return (ft_free(&tmp, 'p'), ft_free(&fill, 'p'), res);
}

/*
	*	is_color(t_cub *cub, char *line, int *color_idx, int *color_arr)
	{
		We use this function to parse the color from the line.
		
		Parameters:
			t_cub *cub - the main struct of the game.
			char *line - the current line we are parsing.
			int *color_idx - the index of the color we are parsing.
			int *color_arr - the array of the color we are parsing.
		
		Logic:
			-	if the line is empty or NULL, we return 0.
			-	if the first character of the line is digit, we parse the color.
			-	if the color index is 3, we exit the program.
				imagine this:
					we got indx 0, we parse the first color && ++idx => idx = 1.
					we got indx 1, we parse the second color && ++idx => idx = 2.
					we got indx 2, we parse the third color && ++idx => idx = 3.
					now if we found another digit which is a number,
					we will call this function with color_idx = 3,
					which means it's an error. i.e F 1,2,3,4
			-	if the idx is below 3 we use our use_atoi which is a wrapper fn,
				we sat the value of that color into that array with that idx.
			-	we return the length of the color 
				and we increment line len outside the function.
	}

	*	is_elements_ready(t_file *file)
	{
		We use this function to check if all the elements portion of the file
		is ready or not.
		
		Parameters:
			t_file *file - the file struct of the game.
		
		Logic:
			-	if there's any element missing we return false.
	}

	*	is_player(t_cub *cub, char *map_line)
	{
		We use this function to check if the character,
		and if that character is a valid player or not,
		also how many player character we have.
		
		Parameters:
			t_cub *cub - the main struct of the game.
			char *map_line - the current map line we are parsing.
		
		Logic:
			-	if the map line is empty or NULL, we return.
			-	if the character is not a space or not 0 or not 1,
				so it might be a player or any other character,
					-	if it's not a valid player character, we exit error.
					-	else we set the player postion
						and we increment the player counter.
			-	if the player counter is more than 1, we early exit error.
	}

	*	set_map_width(t_file *file, char *map_line)
	{
		We use this function to set the map width.
		
		Parameters:
			t_file *file - the file struct of the game.
			char *map_line - the current map line we are parsing.
		
		Logic:
			-	if the length of the map line > than the map width,
				we set the map width to that length.
	}

	*	set_map_line(t_cub *cub, t_file *file, char *map_line)
	{
		We use this function to fill the empty spaces in the map.
		
		Parameters:
			t_cub *cub - the main struct of the game.
			t_file *file - the file struct of the game.
			char *map_line - the current map line we are parsing.
		
		Logic:
			-	get the length of the map line.
			-	we create the tmp.
			-	if len == tmp => we return the tmp.
			-	else we calculate the difference between the tmp and the len.
			-	we create the fill based on the difference.
			-	we fill it with spaces.
			-	we join the tmp with the fill in the res.
			-	we return the res.
	}
*/
