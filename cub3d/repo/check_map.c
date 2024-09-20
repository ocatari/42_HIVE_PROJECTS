/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:16:40 by corellan          #+#    #+#             */
/*   Updated: 2023/04/28 12:37:46 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	middle_aux2(char **map, int index, int i)
{
	int	len_next;
	int	len_pre;

	len_next = ft_strlen(map[index + 1]);
	len_pre = ft_strlen(map[index - 1]);
	if ((i >= len_next) || (i >= len_pre))
		return (1);
	else if (map[index + 1][i] == ' ')
		return (1);
	else if (map[index - 1][i] == ' ')
		return (1);
	else if ((map[index + 1][i + 1] == ' ') || (map[index + 1][i + 1] == '\0'))
		return (1);
	else if ((map[index - 1][i + 1] == ' ') || (map[index - 1][i + 1] == '\0'))
		return (1);
	else if ((i > 0) && ((map[index - 1][i - 1] == ' ') || \
		(map[index - 1][i - 1] == '\0')))
		return (1);
	else if ((i > 0) && ((map[index + 1][i - 1] == ' ') || \
		(map[index + 1][i - 1] == '\0')))
		return (1);
	else if (map[index][i + 1] == '\0' || (map[index][i + 1] == ' '))
		return (1);
	return (0);
}

static int	middle_aux(char **map, int *flag, int index, int i)
{
	if ((map[index][i] != ' ') && (map[index][i] != '1') && \
		(map[index][i] != '0') && (map[index][i] != 'N') && \
		(map[index][i] != 'S') && (map[index][i] != 'E') && \
		(map[index][i] != 'W'))
		return (1);
	if (((*flag) == 0) && ((map[index][i] == 'N') || \
		(map[index][i] == 'S') || (map[index][i] == 'E') || \
		(map[index][i] == 'W')))
		(*flag) = 1;
	else if (((*flag) == 1) && ((map[index][i] == 'N') || \
		(map[index][i] == 'S') || (map[index][i] == 'E') || \
		(map[index][i] == 'W')))
		return (1);
	if (map[index][i] == '0' || ((map[index][i] == 'N') || \
		(map[index][i] == 'S') || (map[index][i] == 'E') || \
		(map[index][i] == 'W')))
	{
		if (middle_aux2(map, index, i) == 1)
			return (1);
	}
	if (map[index][i] == ' ' && map[index][i] == ' ')
		return (0);
	return (0);
}

static int	middle(char **map, int *flag, int index)
{
	int	i;
	int	sp;

	i = 0;
	while (map[index][i] != '\0')
	{
		if (i == 0)
		{
			sp = ft_count_space(map[index]);
			if (map[index][sp] != '1')
				break ;
		}
		if (middle_aux(map, &(*flag), index, i) == 1)
			break ;
		i++;
	}
	if (i < (int)ft_strlen(map[index]))
		return (1);
	return (0);
}

static int	first_and_last(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '1')
			break ;
		i++;
	}
	if (i < (int)ft_strlen(str))
		return (1);
	return (0);
}

int	check_map(char **map, t_cub3d *cub3d)
{
	int	len;
	int	flag;
	int	i;

	len = ft_array_len(map);
	flag = 0;
	i = 1;
	if ((first_and_last(map[0]) == 1) || (first_and_last(map[len - 1]) == 1))
	{
		print_error(INVALID_MAP);
		return (1);
	}
	while (i < (len - 1))
	{
		if (middle(map, &(flag), i) == 1)
		{
			print_error(INVALID_MAP);
			return (1);
		}
		i++;
	}
	if (check_mases(map, flag, cub3d) == 1 || \
		check_empty_lines(map, &(*cub3d)) == 1)
		return (1);
	return (0);
}
