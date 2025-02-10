/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:05:21 by daxferna          #+#    #+#             */
/*   Updated: 2025/02/11 00:25:57 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_map	game;

	if (argc != 2)
		error(1, &game);
	validate_arg(argv[1], &game);
	init_map(&game);
	mlx_key_hook(game.window, &key_hook, &game);
	mlx_loop_hook(game.window, &loop_hook, &game);
	mlx_loop(game.window);
	free_game(&game);
	return (0);
}
