/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_safety_movement_buffer.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:31:40 by tpoho             #+#    #+#             */
/*   Updated: 2023/05/04 18:34:46 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	insert_safety_movement_buffer(t_cub3d *cub3d, int x_or_y, int backward)
{
	if (x_or_y == 0)
	{
		if (cub3d->player_direction_x > 0)
		{
			return (PLAYER_COLLISION_DISTANCE * backward);
		}
		else
			return (-PLAYER_COLLISION_DISTANCE * backward);
	}
	if (x_or_y == 1)
	{
		if (cub3d->player_direction_y > 0)
		{
			return (PLAYER_COLLISION_DISTANCE * backward);
		}
		else
			return (-PLAYER_COLLISION_DISTANCE * backward);
	}
	return (0);
}

double	insert_safety_movement_buffer_strafe(t_cub3d *cub3d,
	int x_or_y, int backward)
{
	if (x_or_y == 0)
	{
		if (cub3d->camera_plane_x > 0)
		{
			return (PLAYER_COLLISION_DISTANCE * backward);
		}
		else
			return (-PLAYER_COLLISION_DISTANCE * backward);
	}
	if (x_or_y == 1)
	{
		if (cub3d->camera_plane_y > 0)
		{
			return (PLAYER_COLLISION_DISTANCE * backward);
		}
		else
			return (-PLAYER_COLLISION_DISTANCE * backward);
	}
	return (0);
}
