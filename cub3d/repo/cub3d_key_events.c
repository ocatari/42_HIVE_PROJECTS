/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_key_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:19:59 by corellan          #+#    #+#             */
/*   Updated: 2023/04/27 14:06:28 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_up_event(int key_code, t_cub3d *cub3d)
{
	if (key_code == KEY_W)
		cub3d->key_w_down = 0;
	if (key_code == KEY_A)
		cub3d->key_a_down = 0;
	if (key_code == KEY_S)
		cub3d->key_s_down = 0;
	if (key_code == KEY_D)
		cub3d->key_d_down = 0;
	if (key_code == KEY_RIGHT)
		cub3d->key_arrow_right_down = 0;
	if (key_code == KEY_LEFT)
		cub3d->key_arrow_left_down = 0;
	return (0);
}

int	key_down_event(int key_code, t_cub3d *cub3d)
{
	if (key_code == KEY_ESC)
		destroy((cub3d));
	if (key_code == KEY_W)
		cub3d->key_w_down = 1;
	if (key_code == KEY_A)
		cub3d->key_a_down = 1;
	if (key_code == KEY_S)
		cub3d->key_s_down = 1;
	if (key_code == KEY_D)
		cub3d->key_d_down = 1;
	if (key_code == KEY_RIGHT)
		cub3d->key_arrow_right_down = 1;
	if (key_code == KEY_LEFT)
		cub3d->key_arrow_left_down = 1;
	return (0);
}
