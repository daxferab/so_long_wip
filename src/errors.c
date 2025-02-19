/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:12:41 by daxferna          #+#    #+#             */
/*   Updated: 2025/02/19 21:02:19 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(int errno, t_map *game)
{
	ft_putstr_fd("Error\n", 2);
	if (errno == 1)
	{
		free_game(game);
		ft_putstr_fd("No se pudo inicializar la ventana\n", 2);
	}
	if (errno == 2)
		ft_putstr_fd("Número incorrecto de argumentos\n", 2);
	else if (errno == 3)
		ft_putstr_fd("El argumento no es un archivo válido (.ber)\n", 2);
	else if (errno == 4)
		ft_putstr_fd("No contiene los caracteres necesarios\n", 2);
	else if (errno == 5)
		ft_putstr_fd("El mapa es demasiado pequeño\n", 2);
	else if (errno == 6)
		ft_putstr_fd("El mapa no es rectangular\n", 2);
	else if (errno == 7)
		ft_putstr_fd("El mapa no está cerrado\n", 2);
	else if (errno == 8)
		ft_putstr_fd("El mapa contiene caracteres inválidos\n", 2);
	else if (errno == 9)
		ft_putstr_fd("El mapa no es solucionable\n", 2);
	exit(1);
}
