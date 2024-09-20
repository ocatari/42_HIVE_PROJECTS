/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:13:19 by corellan          #+#    #+#             */
/*   Updated: 2023/05/04 19:29:56 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroy(t_cub3d *cub3d)
{
	mlx_destroy_image(cub3d->mlx.mlx, cub3d->no_tex.image);
	mlx_destroy_image(cub3d->mlx.mlx, cub3d->so_tex.image);
	mlx_destroy_image(cub3d->mlx.mlx, cub3d->ea_tex.image);
	mlx_destroy_image(cub3d->mlx.mlx, cub3d->we_tex.image);
	mlx_destroy_image(cub3d->mlx.mlx, cub3d->image_1.image);
	mlx_destroy_image(cub3d->mlx.mlx, cub3d->image_2.image);
	mlx_destroy_window(cub3d->mlx.mlx, cub3d->mlx.mlx_window);
	ft_free_int(cub3d->map_int, cub3d->height_map);
	ft_free_int(cub3d->textures, 4);
	cub3d->mlx.mlx = NULL;
	cub3d->mlx.mlx_window = NULL;
	exit(0);
}
