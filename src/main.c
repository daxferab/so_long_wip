/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:05:21 by daxferna          #+#    #+#             */
/*   Updated: 2024/12/28 20:47:17 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_map	game_map;

	if (argc != 2)
		error(1);
	validate_arg(argv[1], &game_map);
	free_map(game_map.map);
	return (0);
}
