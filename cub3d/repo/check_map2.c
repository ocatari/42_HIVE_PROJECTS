/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:18:43 by corellan          #+#    #+#             */
/*   Updated: 2023/04/28 14:07:30 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	establish_direction(char ***temp, t_coord *id, t_cub3d *cub3d)
{
	if ((*temp)[id->i][id->j] == 'N')
		cub3d->starting_angle = 0;
	else if ((*temp)[id->i][id->j] == 'S')
		cub3d->starting_angle = PI;
	else if ((*temp)[id->i][id->j] == 'E')
		cub3d->starting_angle = ((3 * PI) / 2);
	else if ((*temp)[id->i][id->j] == 'W')
		cub3d->starting_angle = (PI / 2);
}

static int	find_player(char ***temp, t_coord *id, t_cub3d *cub3d)
{
	id->j = 0;
	while ((*temp)[id->i][id->j] != '\0')
	{
		if ((*temp)[id->i][id->j] == 'N' || (*temp)[id->i][id->j] == 'S' || \
			(*temp)[id->i][id->j] == 'E' || (*temp)[id->i][id->j] == 'W')
		{
			id->i_row = id->i;
			id->j_col = id->j;
			cub3d->player_position_x = (double)id->i + 0.5;
			cub3d->player_position_y = (double)id->j + 0.5;
			cub3d->player_direction_x = -1;
			cub3d->player_direction_y = 0;
			establish_direction(&(*temp), &(*id), &(*cub3d));
			return (1);
		}
		(id->j)++;
	}
	return (0);
}

static int	find_start(char ***temp, int rows, int cols, t_cub3d *cub3d)
{
	t_coord	idx;

	idx.col = cols;
	idx.row = rows;
	idx.i_row = 0;
	idx.j_col = 0;
	idx.i = 0;
	while ((*temp)[idx.i] != NULL)
	{
		if (find_player(&(*temp), &idx, cub3d) == 1)
			break ;
		(idx.i)++;
	}
	flood_fill(&(*temp), &idx, idx.i_row, idx.j_col);
	if (check_after_flood_fill(&(*temp)) == 1)
	{
		print_error(INVALID_MAP);
		ft_free_split((*temp));
		return (1);
	}
	ft_free_split((*temp));
	return (0);
}

static int	copy_rectangle(char ***temp, char **map, t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cub3d->height_map)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			(*temp)[i][j] = map[i][j];
			j++;
		}
		while (j < cub3d->width_map)
		{
			(*temp)[i][j] = ' ';
			j++;
		}
		(*temp)[i][j] = '\0';
		i++;
	}
	return (find_start(&(*temp), cub3d->height_map, cub3d->width_map, cub3d));
}

int	check_mases(char **map, int flag, t_cub3d *cub3d)
{
	char	**temp;
	int		i;

	if (flag == 0)
	{
		print_error(INVALID_MAP);
		return (1);
	}
	cub3d->height_map = ft_array_len(map);
	i = 0;
	cub3d->width_map = longest_length(map);
	temp = (char **)malloc(sizeof(char *) * (cub3d->height_map + 1));
	if (temp == NULL)
		return (1);
	temp[cub3d->height_map] = NULL;
	while (i < cub3d->height_map)
	{
		temp[i] = (char *)malloc(sizeof(char) * (cub3d->width_map + 1));
		if (temp[i] == NULL)
			return (error_free(temp, i));
		i++;
	}
	return (copy_rectangle(&temp, map, cub3d));
}
