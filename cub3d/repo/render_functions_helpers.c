/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_functions_helpers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:17:21 by tpoho             #+#    #+#             */
/*   Updated: 2023/04/27 15:32:12 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	in_which_box_we_are_in_map(t_cub3d *cub3d)
{
	cub3d->render_walls.player_which_map_cell_x
		= (int) cub3d->player_position_x;
	cub3d->render_walls.player_which_map_cell_y
		= (int) cub3d->player_position_y;
}

void	compute_ray_position_and_direction(t_cub3d *cub3d, int x_coord)
{
	cub3d->render_walls.ray_coordinate_in_camera_plane
		= (2 * ((double) x_coord / WIDTH_WINDOW)) - 1;
	cub3d->render_walls.ray_direction_x
		= cub3d->player_direction_x + cub3d->camera_plane_x
		* cub3d->render_walls.ray_coordinate_in_camera_plane;
	cub3d->render_walls.ray_direction_y
		= cub3d->player_direction_y + cub3d->camera_plane_y
		* cub3d->render_walls.ray_coordinate_in_camera_plane;
}

void	compute_delta_distances(t_cub3d *cub3d)
{
	cub3d->render_walls.delta_distance_to_next_x
		= fabs(1 / cub3d->render_walls.ray_direction_x);
	cub3d->render_walls.delta_distance_to_next_y
		= fabs(1 / cub3d->render_walls.ray_direction_y);
}

void	compute_x_step_and_initial_length_to_next_x(t_cub3d *cub3d)
{
	cub3d->render_walls.take_step_in_x = 1;
	cub3d->render_walls.length_of_ray_to_next_x
		= (cub3d->render_walls.player_which_map_cell_x
			+ 1.0 - cub3d->player_position_x)
		* cub3d->render_walls.delta_distance_to_next_x;
	if (cub3d->render_walls.ray_direction_x < 0)
	{
		cub3d->render_walls.take_step_in_x = -1;
		cub3d->render_walls.length_of_ray_to_next_x
			= (cub3d->player_position_x
				- cub3d->render_walls.player_which_map_cell_x)
			* cub3d->render_walls.delta_distance_to_next_x;
	}
}

void	compute_y_step_and_initial_length_to_next_y(t_cub3d *cub3d)
{
	cub3d->render_walls.take_step_in_y = 1;
	cub3d->render_walls.length_of_ray_to_next_y
		= (cub3d->render_walls.player_which_map_cell_y
			+ 1.0 - cub3d->player_position_y)
		* cub3d->render_walls.delta_distance_to_next_y;
	if (cub3d->render_walls.ray_direction_y < 0)
	{
		cub3d->render_walls.take_step_in_y = -1;
		cub3d->render_walls.length_of_ray_to_next_y
			= (cub3d->player_position_y
				- cub3d->render_walls.player_which_map_cell_y)
			* cub3d->render_walls.delta_distance_to_next_y;
	}
}
