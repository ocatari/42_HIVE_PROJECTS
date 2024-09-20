/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:59:51 by tpoho             #+#    #+#             */
/*   Updated: 2023/05/05 14:24:44 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_walls_run_loop(t_cub3d *cub3d, int x_coord)
{
	cub3d->render_walls.wall_hit = 0;
	compute_ray_position_and_direction(cub3d, x_coord);
	in_which_box_we_are_in_map(cub3d);
	compute_delta_distances(cub3d);
	compute_x_step_and_initial_length_to_next_x(cub3d);
	compute_y_step_and_initial_length_to_next_y(cub3d);
	compute_ray_distance_with_dda(cub3d);
	draw_window(cub3d, x_coord);
}

void	render_walls(t_cub3d *cub3d)
{
	int	x_coord;

	x_coord = 0;
	while (x_coord < WIDTH_WINDOW)
	{
		render_walls_run_loop(cub3d, x_coord);
		++x_coord;
	}
}

void	render_floor_ceiling(t_cub3d *cub3d)
{
	int	x;
	int	y;
	int	upper_half;

	upper_half = HEIGHT_WINDOW / 2;
	y = 0;
	while (y < upper_half)
	{
		x = 0;
		while (x < WIDTH_WINDOW)
		{
			put_pixel_in_image(cub3d, x, y, cub3d->colour_ceiling);
			put_pixel_in_image(cub3d, x, (y + upper_half), cub3d->colour_floor);
			++x;
		}
		++y;
	}
}
