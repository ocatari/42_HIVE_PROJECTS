/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:25:40 by corellan          #+#    #+#             */
/*   Updated: 2023/04/27 16:37:29 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**process_array_aux(char ***temp, char ***array, int i, int j)
{
	while ((*array)[i] != NULL)
	{
		if (ft_count_space((*array)[i]) != (int)ft_strlen((*array)[i]))
		{
			(*temp)[j] = ft_strdup((*array)[i]);
			j++;
		}
		i++;
	}
	ft_free_split((*array));
	return ((*temp));
}

static char	**process_array(char ***array)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	j = 0;
	while ((*array)[i] != NULL)
	{
		if (ft_count_space((*array)[i]) != (int)ft_strlen((*array)[i]))
			j++;
		i++;
	}
	temp = (char **)malloc(sizeof(char *) * (j + 1));
	if (temp == NULL)
	{
		ft_free_split((*array));
		return (NULL);
	}
	temp[j] = NULL;
	i = 0;
	j = 0;
	return (process_array_aux(&temp, &(*array), i, j));
}

static int	get_map(t_cub3d *cub3d)
{
	int		len;
	int		i;
	char	**temp;

	i = 0;
	temp = ((cub3d->file) + 6);
	len = ft_array_len(temp);
	cub3d->map = (char **)malloc(sizeof(char *) * (len + 1));
	if (cub3d->map == NULL)
		return (1);
	cub3d->map[len] = NULL;
	if (len < 3)
	{
		if (len < 3 && len > 0)
			print_error(INVALID_MAP);
		else if (len == 0)
			print_error(NO_MAP);
		return (1);
	}
	while (i < len)
	{
		cub3d->map[i] = ft_strdup(temp[i]);
		i++;
	}
	return (0);
}

static int	check_file_map_aux(char **doc, t_cub3d *cub3d)
{
	cub3d->file = NULL;
	cub3d->file = ft_split((*doc), '\n');
	cub3d->file = process_array(&(cub3d->file));
	free(*doc);
	if (check_presence_textures(cub3d->file, &(*cub3d)) == 1 || \
		check_floor_ceiling(cub3d->file, &(*cub3d)) == 1)
	{
		ft_free_split(cub3d->file);
		return (1);
	}
	if (get_map(&(*cub3d)) == 1)
	{
		ft_free_split(cub3d->file);
		ft_free_split(cub3d->map);
		return (1);
	}
	if (check_map(cub3d->map, &(*cub3d)) == 1)
	{
		ft_free_split(cub3d->file);
		ft_free_split(cub3d->map);
		return (1);
	}
	return (0);
}

int	check_file_map(char **av, t_cub3d *cub3d)
{
	char	*str;
	char	*doc;
	int		flag;

	cub3d->fd = open(av[1], O_RDONLY);
	flag = 0;
	cub3d->av_addr = &av;
	if (cub3d->fd == -1)
	{
		print_error(INVALID_FILE);
		return (1);
	}
	str = ft_calloc(1, 1);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(cub3d->fd);
		if (flag == 0)
			doc = ft_strdup("");
		if (str != NULL)
			doc = ft_strjoin_free(doc, str);
		flag = 1;
	}
	close(cub3d->fd);
	return (check_file_map_aux(&doc, &(*cub3d)));
}
