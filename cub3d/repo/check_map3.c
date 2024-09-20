/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:04:00 by corellan          #+#    #+#             */
/*   Updated: 2023/04/28 12:30:23 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_emp_lines_aux(char **map, t_cub3d *cub, int n_ar, char **str)
{
	int	i;

	i = 0;
	while (i < n_ar)
	{
		if (ft_strncmp((*str), map[i], ft_strlen(map[i])) != 0)
			break ;
		free((*str));
		(*str) = get_next_line(cub->fd);
		i++;
	}
	close(cub->fd);
	if (i < n_ar)
	{
		print_error(INVALID_MAP);
		if ((*str) != NULL)
			free((*str));
		return (1);
	}
	if ((*str) != NULL)
		free((*str));
	return (0);
}

int	check_empty_lines(char **map, t_cub3d *cub3d)
{
	int		n_array;
	char	*str;

	n_array = ft_array_len(map);
	cub3d->fd = open((*(cub3d->av_addr))[1], O_RDONLY);
	str = ft_calloc(1, 1);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(cub3d->fd);
		if (ft_strncmp(str, map[0], ft_strlen(map[0])) == 0)
			break ;
	}
	return (check_emp_lines_aux(map, &(*cub3d), n_array, &str));
}

int	check_after_flood_fill(char ***map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while ((*map)[i] != NULL)
	{
		j = 0;
		while ((*map)[i][j] != '\0')
		{
			if (((*map)[i][j] != ' ') && ((*map)[i][j] != '3'))
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 1)
			break ;
		i++;
	}
	if (flag == 1)
		return (1);
	return (0);
}

void	flood_fill(char ***temp, t_coord *id, int ro, int co)
{
	if (ro >= id->row || co >= id->col)
		return ;
	if (ro < 0 || co < 0)
		return ;
	if ((*temp)[ro][co] == ' ' || (*temp)[ro][co] == '\0')
		return ;
	if ((*temp)[ro][co] == 'N' || (*temp)[ro][co] == 'S' || \
		(*temp)[ro][co] == 'E' || (*temp)[ro][co] == 'W' || \
		(*temp)[ro][co] == '1' || (*temp)[ro][co] == '0')
	{
		(*temp)[ro][co] = '3';
		flood_fill(&(*temp), &(*id), (ro - 1), co);
		flood_fill(&(*temp), &(*id), (ro + 1), co);
		flood_fill(&(*temp), &(*id), ro, (co - 1));
		flood_fill(&(*temp), &(*id), ro, (co + 1));
	}
}
