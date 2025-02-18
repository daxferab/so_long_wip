/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:12:41 by daxferna          #+#    #+#             */
/*   Updated: 2025/02/18 22:58:26 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(int errno, t_map *game)
{
	//TODO: Implementar mensajes de error mas descriptivos
	if (errno == 1)
		ft_putstr_fd("Error\nNúmero incorrecto de argumentos\n", 2);
	else if (errno == 2)
		ft_putstr_fd("Error\nEl argumento no es un archivo válido (.ber)\n", 2);
	else if (errno == 3)
		ft_putstr_fd("Error\nEl archivo no es un mapa válido\n", 2);
	else if (errno == 4)
	{
		free_game(game);
		ft_putstr_fd("Error\nNo se pudo inicializar la ventana\n", 2);
	}
	exit(1);
}
