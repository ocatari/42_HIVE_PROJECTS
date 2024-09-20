/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_functions_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:52:29 by tpoho             #+#    #+#             */
/*   Updated: 2023/04/27 13:54:20 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_right(t_cub3d *cub3d)
{
	double	temp_direction_x;
	double	temp_camera_plane_x;

	temp_direction_x = cub3d->player_direction_x;
	cub3d->player_direction_x = cub3d->player_direction_x
		* cos(-TURNING_SPEED) - cub3d->player_direction_y * sin(-TURNING_SPEED);
	cub3d->player_direction_y = temp_direction_x * sin(-TURNING_SPEED)
		+ cub3d->player_direction_y * cos(-TURNING_SPEED);
	temp_camera_plane_x = cub3d->camera_plane_x;
	cub3d->camera_plane_x = cub3d->camera_plane_x * cos(-TURNING_SPEED)
		- cub3d->camera_plane_y * sin(-TURNING_SPEED);
	cub3d->camera_plane_y = temp_camera_plane_x * sin(-TURNING_SPEED)
		+ cub3d->camera_plane_y * cos(-TURNING_SPEED);
}

void	turn_left(t_cub3d *cub3d)
{
	double	temp_direction_x;
	double	temp_camera_plane_x;

	temp_direction_x = cub3d->player_direction_x;
	cub3d->player_direction_x = cub3d->player_direction_x * cos(TURNING_SPEED)
		- cub3d->player_direction_y * sin(TURNING_SPEED);
	cub3d->player_direction_y = temp_direction_x * sin(TURNING_SPEED)
		+ cub3d->player_direction_y * cos(TURNING_SPEED);
	temp_camera_plane_x = cub3d->camera_plane_x;
	cub3d->camera_plane_x = cub3d->camera_plane_x * cos(TURNING_SPEED)
		- cub3d->camera_plane_y * sin(TURNING_SPEED);
	cub3d->camera_plane_y = temp_camera_plane_x * sin(TURNING_SPEED)
		+ cub3d->camera_plane_y * cos(TURNING_SPEED);
}
