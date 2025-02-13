/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:05:21 by daxferna          #+#    #+#             */
/*   Updated: 2025/02/13 12:10:20 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_map	game;

	if (argc != 2)
		error(1, &game);
	validate_arg(argv[1], &game);
	game.window = NULL;
	init_map(&game);
	mlx_key_hook(game.window, &key_hook, &game);
	mlx_loop_hook(game.window, &loop_hook, &game);
	mlx_loop(game.window);
	free_game(&game);
	return (0);
}
//TODO: Norminette
//TODO: Sprites más bonitos
//TODO: bonus?: Animaciones, enemigos, contador en pantalla
