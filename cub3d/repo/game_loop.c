/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:57:56 by tpoho             #+#    #+#             */
/*   Updated: 2023/05/05 12:45:30 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_character(t_cub3d *cub3d)
{
	if (cub3d->key_w_down == 1)
		move_forward(cub3d);
	if (cub3d->key_a_down == 1)
		strafe_left(cub3d);
	if (cub3d->key_s_down == 1)
		move_backward(cub3d);
	if (cub3d->key_d_down == 1)
		strafe_right(cub3d);
	if (cub3d->key_arrow_right_down == 1)
		turn_right(cub3d);
	if (cub3d->key_arrow_left_down == 1)
		turn_left(cub3d);
}

int	game_loop(t_cub3d *cub3d)
{
	move_character(cub3d);
	render_floor_ceiling(cub3d);
	render_walls(cub3d);
	if (cub3d->which_image == 0)
		mlx_put_image_to_window(cub3d->mlx.mlx,
			cub3d->mlx.mlx_window, cub3d->image_1.image, 0, 0);
	else
		mlx_put_image_to_window(cub3d->mlx.mlx,
			cub3d->mlx.mlx_window, cub3d->image_2.image, 0, 0);
	cub3d->which_image = (cub3d->which_image + 1) % 2;
	return (0);
}
