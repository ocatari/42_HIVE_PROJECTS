/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:51:27 by corellan          #+#    #+#             */
/*   Updated: 2023/05/04 10:52:16 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_null_or_free(t_cub3d *cub3d, char **file, int flag)
{
	if ((flag == 1) && (!cub3d->no_path || !cub3d->so_path || \
		!cub3d->ea_path || !cub3d->we_path))
	{
		print_error(WRONG_INPUT);
		ft_free_split(file);
		check_null_or_free(&(*cub3d), file, 3);
		return (1);
	}
	if ((flag == 2) && (!cub3d->no_tex.image || !cub3d->so_tex.image || \
		!cub3d->ea_tex.image || !cub3d->we_tex.image))
	{
		print_error(TEXTURE_NOT_FOUND);
		ft_free_split(file);
		check_null_or_free(&(*cub3d), file, 3);
		return (1);
	}
	if (flag == 3)
	{
		free(cub3d->no_path);
		free(cub3d->so_path);
		free(cub3d->ea_path);
		free(cub3d->we_path);
	}
	return (0);
}

static char	*get_path_textures(char **file, int idx)
{
	char	**temp;
	char	*str;

	temp = ft_split((file[idx] + 2), ' ');
	if (temp == NULL)
		return (NULL);
	if (temp[0] == NULL || temp[1] != NULL)
	{
		ft_free_split(temp);
		return (NULL);
	}
	str = ft_strdup(temp[0]);
	ft_free_split(temp);
	return (str);
}

int	check_textures(char **file, t_cub3d *cub)
{
	cub->no_path = get_path_textures(file, cub->idx_no);
	cub->so_path = get_path_textures(file, cub->idx_so);
	cub->ea_path = get_path_textures(file, cub->idx_ea);
	cub->we_path = get_path_textures(file, cub->idx_we);
	if (check_null_or_free(cub, file, 1) == 1)
		return (1);
	cub->no_tex.image = mlx_xpm_file_to_image(cub->mlx.mlx, cub->no_path, \
		&(cub->no_tex.width_tex), &(cub->no_tex.height_tex));
	cub->so_tex.image = mlx_xpm_file_to_image(cub->mlx.mlx, cub->so_path, \
		&(cub->so_tex.width_tex), &(cub->so_tex.height_tex));
	cub->ea_tex.image = mlx_xpm_file_to_image(cub->mlx.mlx, cub->ea_path, \
		&(cub->ea_tex.width_tex), &(cub->ea_tex.height_tex));
	cub->we_tex.image = mlx_xpm_file_to_image(cub->mlx.mlx, cub->we_path, \
		&(cub->we_tex.width_tex), &(cub->we_tex.height_tex));
	if (check_null_or_free(&(*cub), file, 2) == 1)
		return (1);
	check_null_or_free(&(*cub), file, 3);
	return (0);
}

int	check_presence_textures(char **array, t_cub3d *cub3d)
{
	int	len;

	cub3d->idx_no = ft_find_word_array(array, "NO");
	cub3d->idx_so = ft_find_word_array(array, "SO");
	cub3d->idx_ea = ft_find_word_array(array, "EA");
	cub3d->idx_we = ft_find_word_array(array, "WE");
	len = ft_array_len(array);
	if (cub3d->idx_no == len || cub3d->idx_so == len || \
		cub3d->idx_ea == len || cub3d->idx_we == len)
	{
		print_error(TEXTURES_MISSING);
		return (1);
	}
	else if (cub3d->idx_no > 5 || cub3d->idx_so > 5 || cub3d->idx_ea > 5 || \
		cub3d->idx_we > 5)
	{
		print_error(WRONG_INPUT);
		return (1);
	}
	return (0);
}
