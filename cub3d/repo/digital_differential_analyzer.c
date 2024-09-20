/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digital_differential_analyzer.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:25:59 by tpoho             #+#    #+#             */
/*   Updated: 2023/04/27 18:11:07 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	take_one_step_back_in_dda(t_cub3d *cub3d)
{
	cub3d->render_walls.straight_wall_distance
		= cub3d->render_walls.length_of_ray_to_next_y
		- cub3d->render_walls.delta_distance_to_next_y;
	if (cub3d->render_walls.which_side_hit == 0)
	{
		cub3d->render_walls.straight_wall_distance
			= cub3d->render_walls.length_of_ray_to_next_x
			- cub3d->render_walls.delta_distance_to_next_x;
	}
}

void	compute_ray_distance_with_dda(t_cub3d *cub3d)
{
	while (cub3d->render_walls.wall_hit == 0)
	{
		if (cub3d->render_walls.length_of_ray_to_next_x
			< cub3d->render_walls.length_of_ray_to_next_y)
		{
			cub3d->render_walls.length_of_ray_to_next_x
				+= cub3d->render_walls.delta_distance_to_next_x;
			cub3d->render_walls.player_which_map_cell_x
				+= cub3d->render_walls.take_step_in_x;
			cub3d->render_walls.which_side_hit = 0;
		}
		else
		{
			cub3d->render_walls.length_of_ray_to_next_y
				+= cub3d->render_walls.delta_distance_to_next_y;
			cub3d->render_walls.player_which_map_cell_y
				+= cub3d->render_walls.take_step_in_y;
			cub3d->render_walls.which_side_hit = 1;
		}
		if (cub3d->map_int[cub3d->render_walls.player_which_map_cell_x]
			[cub3d->render_walls.player_which_map_cell_y] > 0)
				cub3d->render_walls.wall_hit = 1;
	}
	take_one_step_back_in_dda(cub3d);
}
