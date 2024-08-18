/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:56:17 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/18 14:37:06 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	validate_img(t_cub *cub, void **img, char *line)
{
	char	**split;
	int		width;
	int		height;

	if (*img)
		exit_failure(cub, ELEMENTS_EXIST_ERR);
	split = ft_split(line, ' ');
	if (!split)
		exit_failure(cub, MALLOC_ERR);
	if ((!split[0] || !split[1] || split[2]) && (ft_free(&split, 'a'), 1))
		exit_failure(cub, ELEMENTS_SPACE_ERR);
	if (!ft_strrchr(split[1], '.xpm'))
		return (ft_free(&split, 'a'), exit_failure(cub, ELEMENTS_IMG_NAME_ERR));
	*img = mlx_xpm_file_to_image(cub->mlx, split[1], &width, &height);
	ft_free(&split, 'a');
	if (!*img)
		exit_failure(cub, ELEMENTS_IMG_CORRUPTED_ERR);
}

static void	validate_color(t_cub *cub, int *color_arr, char *line)
{
	int	colors_counter;
	int	commas_counter;
	int	letters_counter;

	colors_counter = 0;
	commas_counter = 0;
	letters_counter = 0;
	while (*line)
	{
		while (*line && ft_isspace(*line))
			line++;
		line += ft_iscomma(*line, &commas_counter);
		line += ft_isletter(*line, &letters_counter);
		line += is_color(cub, line, &colors_counter, color_arr);
		if (letters_counter > 1 || commas_counter > 2 || colors_counter > 3)
			exit_failure(cub, COLOR_ERR);
	}
	if (letters_counter != 1 || commas_counter != 2 || colors_counter != 3)
		exit_failure(cub, COLOR_ERR);
}

static void	validate_elements(t_cub *cub, t_file *file, char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (ft_strnstr(line, "NO", len))
		validate_img(cub, &file->no_path, line);
	else if (ft_strnstr(line, "SO", len))
		validate_img(cub, &file->so_path, line);
	else if (ft_strnstr(line, "WE", len))
		validate_img(cub, &file->we_path, line);
	else if (ft_strnstr(line, "EA", len))
		validate_img(cub, &file->ea_path, line);
	else if (ft_strnstr(line, "F", len) && ++cub->file.is_valid_colors)
		validate_color(cub, cub->file.f_color, line);
	else if (ft_strnstr(line, "C", len) && ++cub->file.is_valid_colors)
		validate_color(cub, cub->file.c_color, line);
	if (is_elements_ready(&cub->file))
		cub->file.stage++;
}

static void	validate_map(t_cub *cub, t_file *file, int st)
{
	int	is_empty_line_exist;

	is_empty_line_exist = 0;
	if (!file->map_st || !file->map_end)
		exit_failure(cub, MAP_EMPTY_ERR);
	file->map_height = file->map_end - file->map_st;
	if (file->map_height < 3)
		exit_failure(cub, MAP_HEIGHT_ERR);
	while (st <= file->map_end && file->file_arr[st])
	{
		set_map_width(file, file->file_arr[st]);
		is_player(cub, file->file_arr[st]);
		is_empty_line_exist += ft_isempty_str(file->file_arr[st]);
		file->wall_counter += ft_iswall(file->file_arr[st]);
		if (file->player_counter && !file->wall_counter)
			exit_failure(cub, MAP_WALL_ERR);
		else if (is_empty_line_exist && ft_ismap_line(file->file_arr[st]))
			exit_failure(cub, MAP_EMPTY_LINE);
		st++;
	}
	if (file->player_counter != 1)
		exit_failure(cub, MAP_CHARS_ERR);
	if (file->wall_counter < 2)
		exit_failure(cub, MAP_WALL_ERR);
}

void	validate_file(t_cub *cub, t_file *file)
{
	char	**file_arr;
	int		i;

	file_arr = file->file_arr;
	i = 0;
	while (file->stage == 1 && file_arr[i])
	{
		if (ft_isempty_str(file_arr[i]))
			i++;
		else if (ft_iselement_line(file_arr[i]))
			validate_elements(cub, file, file_arr[i++]);
		else
			exit_failure(cub, ELEMENTS_ERR);
	}
	while (file->stage == 2 && file_arr[i])
	{
		while (file_arr[i] && ft_isempty_str(file_arr[i]))
			i++;
		if (!file->map_st && !ft_iselement_line(file_arr[i]))
			file->map_st = i++;
		else
			break ;
	}
	file->map_end = file->file_len;
	validate_map(cub, file, file->map_st);
}

/*
	*	validate_file(t_cub *cub, t_file *file)
		- This function is used to validate the file.
		- It has 2 while loops:
			-	One for the element portion of the file.
			-	The other for the map portion of the file.

		It has 3 sections
		1- Elements while loop (Stage 1)
			- It has 3 conditions:
				-	Empty line => just increment the i.
				-	Element line => parse it and validate it.
				-	Not Empty and not element line while the stage still 1
					=> exit error.
				-	One we got all our elements ready and accepted 
					=> increment the stage to stage 2 (the map stage).
		2- Map while loop (Stage 2)
			- It has 3 conditions:
				-	Empty line => just increment the i.
				-	We didn't set the starting index of the map && NOT Element
					line => set the map start index and increment the i.
				-	We sat the index && !empty line 
					=> increment the i.
				-	Once we finish the loop, we set the map end index.
				-	The purpose of this loop is to:
					set the map start and end index of the map.
		3- Validate the map


	*	validate_elements(t_cub *cub, t_file *file, char *line)
		- This function is used to validate the elements of the file.
		- It has 5 conditions:
			-	NO => validate the image path.
			-	SO => validate the image path.
			-	WE => validate the image path.
			-	EA => validate the image path.
			-	F or C => validate the color.
			-	Once we got all the elements ready, we increment the stage to 2.

	*	validate_img(t_cub *cub, char *line)
		- This function is used to validate the image path.
		- It has 3 sections:
			-	Split the line by a whitespace.
				-	If it splits into more than 2 parts => exit error.
					i.e. the line should be like "NO ./path/to/img.xpm"
					but not like "NO ./path/to/img.xpm 100 100"
				- 	So if NOT split[0] || NOT split[1] || split[2] 
					=> exit error.
			-	Set the img to whatever mlx_xpm_file_to_image returns.
			-	Return the img and save into it's variable.

	*	validate_color(t_cub *cub, int *color_arr, char *line)
		- This function is used to validate the color.
		- It takes the color_arr based on what color we are validating.
		- It has 2 sections:
			-	While loop:
				-	If i's a comma => increment the commas counter.
				-	If i's a letter => increment the letters counter.
				-	If i's a digit => use the atoi function to convert it
					to an int and store it in the proper index.
				-	The color_idx is used to keep a trace of how many colors we
					extracted from the line, if it's not 3 => exit error.
				-	While i's a whitespace => increment the i.
			-	If Condition:
				-	If the letters counter is not 1 => exit error.
					i.e. FF or F 10T,10,10
				-	If the commas counter is not 2 => exit error.
					i.e. F 10,10 10
				-	If the color_idx is not 3 => exit error.
					i.e. F 10,10
	
	*	validate_map(t_cub *cub, t_file *file, int st)
		- This function is used to validate the map in these aspects:
			-	Count the player character.
			-	Count the walls.
			-	Count the map lines.
			-	Validate the empty lines within & after the map,
				and check if it's valid to create it not early exit.
			-	After this function we are sure that we have 1 player 2 walls
				and the map is valid (there's no empty lines within the map).
			-	We didn't yet check if the map it self is valid or not.
			-	We will do that after we create the map.
		- It has 4 sections:
			-	If map start index or end index == 0 => exit error.
			-	If 200 > map length < 3 => exit error  .
			-	While loop:
				-	While we didn't reach the map end index.
				-	For each line:
					-	Count how many player character we have.
					-	If the wall counter is less than 2 and the line is
						not a map line => exit error.
					-	If the wall counter is more than or equal to 2
						and the line is not empty => exit error.
					-	If the line is a wall line => increment the wall counter.
				-	Increment the st to move to the next map line.
			-	If the player counter != 1 => exit error.
			-	If the wall counter != 2 => exit error.
*/
