/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_texture_pixel_colours_helpers.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:48:48 by tpoho             #+#    #+#             */
/*   Updated: 2023/05/05 12:53:53 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	which_wall_side(t_cub3d *cub3d)
{
	if (cub3d->render_walls.which_side_hit == 0)
	{
		if (cub3d->render_walls.ray_direction_x > 0)
			return (0);
		else
			return (1);
	}
	if (cub3d->render_walls.ray_direction_y > 0)
		return (2);
	else
		return (3);
}

int	relative_hight_texture(t_cub3d *cub3d, int y_coord, int nswe)
{
	return ((int)((((double) y_coord - cub3d->render_walls.draw_limit_low)
			/ (cub3d->render_walls.draw_limit_high
				- cub3d->render_walls.draw_limit_low))
		* return_texture_height(cub3d, nswe)));
}

double	exact_coord_x_for_wall(t_cub3d *cub3d)
{
	double	exact_wall_x_coord;

	if (cub3d->render_walls.which_side_hit == 0)
	{
		exact_wall_x_coord = cub3d->player_position_y
			+ cub3d->render_walls.straight_wall_distance
			* cub3d->render_walls.ray_direction_y;
	}
	else
	{
		exact_wall_x_coord = cub3d->player_position_x
			+ cub3d->render_walls.straight_wall_distance
			* cub3d->render_walls.ray_direction_x;
	}
	exact_wall_x_coord -= floor((exact_wall_x_coord));
	return (exact_wall_x_coord);
}

int	return_texture_width(t_cub3d *cub3d, int nswe)
{
	if (nswe == 0)
		return (cub3d->no_tex.width_tex);
	if (nswe == 1)
		return (cub3d->so_tex.width_tex);
	if (nswe == 2)
		return (cub3d->we_tex.width_tex);
	if (nswe == 3)
		return (cub3d->ea_tex.width_tex);
	return (0);
}

int	return_texture_height(t_cub3d *cub3d, int nswe)
{
	if (nswe == 0)
		return (cub3d->no_tex.height_tex);
	if (nswe == 1)
		return (cub3d->so_tex.height_tex);
	if (nswe == 2)
		return (cub3d->we_tex.height_tex);
	if (nswe == 3)
		return (cub3d->ea_tex.height_tex);
	return (0);
}
