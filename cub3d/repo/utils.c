/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:54:02 by corellan          #+#    #+#             */
/*   Updated: 2023/04/22 11:57:26 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_is_number(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		return (1);
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (str[i] == '\0')
			return (1);
	}
	while ((str[i] <= 57 && str[i] >= 48))
		i++;
	if (i < ft_strlen(str))
		return (1);
	return (0);
}

int	check_valid_number(char const *str)
{
	int			i;
	long long	num;
	long long	neg;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] <= 57 && str[i] >= 48)
	{
		num *= 10;
		num += (str[i] - '0');
		i++;
	}
	if ((num < 0) || ((num * neg) > 255) || ((num * neg) < 0))
		return (1);
	return (0);
}

int	ft_count_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

int	ft_array_len(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return (i);
	while (array[i] != NULL)
		i++;
	return (i);
}

int	ft_find_word_array(char **array, char *needle)
{
	int	i;
	int	j;

	i = 0;
	j = ft_array_len(array);
	if (array == NULL)
		return (0);
	while ((i < j) && (ft_strncmp(needle, array[i], ft_strlen(needle)) != 0))
		i++;
	return (i);
}
