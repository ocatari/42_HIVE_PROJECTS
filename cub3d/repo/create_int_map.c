/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_int_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:03:41 by corellan          #+#    #+#             */
/*   Updated: 2023/05/02 18:07:16 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_int_array_aux(t_cub3d *cub3d, int i, int j)
{
	if (cub3d->map[i][j] == '1')
		cub3d->map_int[i][j] = 1;
	if (cub3d->map[i][j] == '0' || cub3d->map[i][j] == 'N' || \
		cub3d->map[i][j] == 'S' || cub3d->map[i][j] == 'E' || \
		cub3d->map[i][j] == 'W')
		cub3d->map_int[i][j] = 0;
	if (cub3d->map[i][j] == ' ')
		cub3d->map_int[i][j] = 2;
}

static void	fill_int_array(t_cub3d *cub3d, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < rows)
	{
		j = 0;
		while (cub3d->map[i][j] != '\0')
		{
			fill_int_array_aux(cub3d, i, j);
			j++;
		}
		while (j < cols)
		{
			cub3d->map_int[i][j] = 2;
			j++;
		}
		i++;
	}
}

void	create_int_map(t_cub3d *cub3d)
{
	int	i;

	cub3d->height_map = ft_array_len(cub3d->map);
	i = 0;
	cub3d->width_map = longest_length(cub3d->map);
	cub3d->map_int = malloc(sizeof(int *) * (cub3d->height_map));
	while (i < cub3d->height_map)
	{
		cub3d->map_int[i] = malloc(sizeof(int) * (cub3d->width_map));
		if (cub3d->map_int[i] == NULL)
		{
			error_free_int(cub3d->map_int, i);
			return ;
		}
		i++;
	}
	fill_int_array(cub3d, cub3d->height_map, cub3d->width_map);
}
