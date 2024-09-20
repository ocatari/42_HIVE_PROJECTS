/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:22:46 by corellan          #+#    #+#             */
/*   Updated: 2023/05/05 11:03:36 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_argument(int ac, char **av)
{
	int	len_cub;
	int	len_str;

	len_cub = 0;
	if (ac == 1 || ac > 2)
	{
		if (ac == 1)
			print_error(NO_INPUT);
		else if (ac > 2)
			print_error(MANY_ARG);
		return (1);
	}
	len_str = ft_strlen(av[1]);
	if (ft_strnstr(av[1], ".cub", len_str) != NULL)
		len_cub = (int)ft_strlen(ft_strnstr(av[1], ".cub", len_str));
	if (len_cub != 4)
	{
		print_error(WRONG_FORMAT);
		return (1);
	}
	return (0);
}

static void	print_error_aux(int error)
{
	if (error == NO_MAP)
		write(STDERR_FILENO, "No map in the file\n", 19);
	else if (error == INVALID_MAP)
		write(STDERR_FILENO, "Invalid map\n", 12);
}

void	print_error(int error)
{
	write(STDERR_FILENO, "Error\n", 6);
	if (error == NO_INPUT)
		write(STDERR_FILENO, "Not enough arguments\n", 21);
	else if (error == MANY_ARG)
		write(STDERR_FILENO, "Too many arguments\n", 19);
	else if (error == WRONG_FORMAT)
		write(STDERR_FILENO, "The input file is not a .cub file\n", 34);
	else if (error == INVALID_FILE)
	{
		write(STDERR_FILENO, "The file does not have reading permissions", 42);
		write(STDERR_FILENO, " or the file does not exist\n", 28);
	}
	else if (error == TEXTURES_MISSING)
		write(STDERR_FILENO, "One or more of wall textures is missing\n", 40);
	else if (error == WRONG_INPUT)
		write(STDERR_FILENO, "Invalid map format\n", 19);
	else if (error == FLOOR_CELLING_MISSING)
	{
		write(STDERR_FILENO, "The color range to paint the ", 29);
		write(STDERR_FILENO, "floor or the celling is missing\n", 32);
	}
	else if (error == TEXTURE_NOT_FOUND)
		write(STDERR_FILENO, "Error charging textures\n", 24);
	print_error_aux(error);
}
