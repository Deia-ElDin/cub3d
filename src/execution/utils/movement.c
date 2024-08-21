/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:21:28 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/21 14:02:06 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_grid(char **map, int x, int y)
{
	if (map[y][x])
	{
		if (map[y][x] == '0')
			return (1);
		else if (ft_strchr("NSWE", map[y][x]))
			return (1);
		else
			return (0);
	}
	return (0);
}


static void move(t_cub *cub, int keycode)
{
    t_player	*player;
    double		dx;
    double		dy;

	player = &cub->player;
    calculate_deltas(player, keycode, &dx, &dy);
    if (is_valid_grid(cub->map.map_arr, round(dx), round(dy)))
    {
        player->plyr_x = dx;
        player->plyr_y = dy;
    }
}


static void	rotate(t_cub *cub, int keycode)
{
	t_player	*player;
	int 		direction;
	
	direction = 0;
	if (keycode == 123)
		direction = 1;
	else if (keycode == 124)
		direction = -1;
	if (!direction)
		return ;
	player = &cub->player;
	// printf("prev angle: %f\n", player->angle);
	player->angle += direction * ROTATION_SPEED;
	// printf("new angle: %f\n", player->angle);
	if (player->angle < 0)
		player->angle += 2 * M_PI;
	if (player->angle > 2 * M_PI)
		player->angle -= 2 * M_PI;
}

int	movement(int keycode, t_cub *cub)
{
	t_map		*map;
	t_player	*player;
	char		**map_arr;
	int			x;
	int			y;

	map = &cub->map;
	player = &cub->player;
	map_arr = map->map_arr;
	x = player->plyr_x;
	y = player->plyr_y;
	// print_player(cub);
	if (keycode == 2 || keycode == 0 || keycode == 13 || keycode == 1)
		move(cub, keycode);
	if (keycode == 123 || keycode == 124)
		rotate(cub, keycode);
	else if (keycode == 53)
		exit_success(cub);
	return (0);
}

/*
Imagine the Player as an Arrow:
Forward (W key, no extra angle added):

The arrow moves in the direction it is pointing (forward).
Math: x += cos(angle) * speed, y -= sin(angle) * speed
Backward (S key, no extra angle added):

The arrow moves directly backward, opposite to its direction.
Math: x -= cos(angle) * speed, y += sin(angle) * speed
Left (A key, with + M_PI_2 added):

The arrow moves left relative to its current direction. This is perpendicular to the forward direction.
Math: x += cos(angle + M_PI_2) * speed, y -= sin(angle + M_PI_2) * speed
Right (D key, with + M_PI_2 added):

The arrow moves right relative to its current direction. This is perpendicular to the forward direction.
Math: x -= cos(angle + M_PI_2) * speed, y += sin(angle + M_PI_2) * speed
Why + M_PI_2?
M_PI_2 (90 degrees) rotates the direction by 90 degrees:
Left (+ M_PI_2): 90 degrees left of the direction the arrow is pointing.
Right (+ M_PI_2): 90 degrees right of the direction the arrow is pointing.
Without + M_PI_2, left and right movements would not be perpendicular to the forward direction, and the player would not strafe properly.

When you move left or right in a 2D space, you still need to update both the x and y coordinates because the player’s movement is not confined to just one axis.

Explanation:
Strafing Left (A key): The player moves to the left relative to their current direction. This involves both a horizontal and vertical shift, depending on the angle.

Example: If the player is facing diagonally, moving left would require both x and y to change.
Strafing Right (D key): Similarly, moving to the right also involves both axes, as the movement is perpendicular to the direction the player is facing.

Why dy Is Needed:
Even if you intend to move left or right (which intuitively seems like only an x change), the actual movement involves a small y adjustment based on the angle, ensuring the player moves accurately in a perpendicular direction.
*/