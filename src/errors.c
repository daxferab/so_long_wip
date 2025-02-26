/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:12:41 by daxferna          #+#    #+#             */
/*   Updated: 2025/02/26 20:04:28 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(int errno, t_map *game)
{
	ft_putstr_fd("Error\n", 2);
	if (errno == 1)
	{
		free_game(game);
		ft_putstr_fd("Couldn't initialize window\n", 2);
	}
	if (errno == 2)
		ft_putstr_fd("Incorrect number of arguments\n", 2);
	else if (errno == 3)
		ft_putstr_fd("The argument is not a valid file (.ber)\n", 2);
	else if (errno == 4)
		ft_putstr_fd("The map doesn't have the right number of elements\n", 2);
	else if (errno == 5)
		ft_putstr_fd("The map is not rectangular\n", 2);
	else if (errno == 6)
		ft_putstr_fd("The map is not closed\n", 2);
	else if (errno == 7)
		ft_putstr_fd("The map has invalid characters\n", 2);
	else if (errno == 8)
		ft_putstr_fd("The map is not solvable\n", 2);
	exit(1);
}
