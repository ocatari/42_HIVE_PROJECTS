/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:07:39 by corellan          #+#    #+#             */
/*   Updated: 2023/05/04 18:54:16 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_addr_textures(t_cub3d *cub3d)
{
	cub3d->no_tex.address = mlx_get_data_addr(cub3d->no_tex.image,
			&cub3d->no_tex.bits_per_pixel, &cub3d->no_tex.line_length,
			&cub3d->no_tex.endianness);
	cub3d->so_tex.address = mlx_get_data_addr(cub3d->so_tex.image,
			&cub3d->so_tex.bits_per_pixel, &cub3d->so_tex.line_length,
			&cub3d->so_tex.endianness);
	cub3d->ea_tex.address = mlx_get_data_addr(cub3d->ea_tex.image,
			&cub3d->ea_tex.bits_per_pixel, &cub3d->ea_tex.line_length,
			&cub3d->ea_tex.endianness);
	cub3d->we_tex.address = mlx_get_data_addr(cub3d->we_tex.image,
			&cub3d->we_tex.bits_per_pixel, &cub3d->we_tex.line_length,
			&cub3d->we_tex.endianness);
}

static void	fill_array_loop(t_cub3d *cub3d, int i, int width, int y)
{
	char	*pixel;
	int		x;

	x = 0;
	while (x < width)
	{
		if (i == 0)
			pixel = cub3d->no_tex.address + (y * cub3d->no_tex.line_length
					+ (x * (cub3d->no_tex.bits_per_pixel / 8)));
		if (i == 1)
			pixel = cub3d->so_tex.address + (y * cub3d->so_tex.line_length
					+ (x * (cub3d->so_tex.bits_per_pixel / 8)));
		if (i == 2)
			pixel = cub3d->we_tex.address + (y * cub3d->we_tex.line_length
					+ (x * (cub3d->we_tex.bits_per_pixel / 8)));
		if (i == 3)
			pixel = cub3d->ea_tex.address + (y * cub3d->ea_tex.line_length
					+ (x * (cub3d->ea_tex.bits_per_pixel / 8)));
		cub3d->textures[i][x + (y * width)] = *(unsigned int *)pixel;
		x++;
	}
}

static int	fill_array(t_cub3d *cub3d, int width, int heigth, int i)
{
	int		y;

	y = 0;
	cub3d->textures[i] = malloc(sizeof(int) * (width * heigth));
	if (!cub3d->textures[i])
		return (1);
	while (y < heigth)
	{
		fill_array_loop(cub3d, i, width, y);
		y++;
	}
	return (0);
}

void	create_int_array_textures(t_cub3d *cub3d)
{
	cub3d->textures = malloc(sizeof(int *) * 4);
	if (!cub3d->textures)
		return ;
	if (fill_array(cub3d, cub3d->no_tex.width_tex,
			cub3d->no_tex.height_tex, 0) || \
		fill_array(cub3d, cub3d->so_tex.width_tex,
			cub3d->so_tex.height_tex, 1) || \
		fill_array(cub3d, cub3d->we_tex.width_tex,
			cub3d->we_tex.height_tex, 2) || \
		fill_array(cub3d, cub3d->ea_tex.width_tex,
			cub3d->ea_tex.height_tex, 3))
	{
		free(cub3d->textures);
		destroy(cub3d);
	}
}
