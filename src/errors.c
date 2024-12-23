/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:12:41 by daxferna          #+#    #+#             */
/*   Updated: 2024/12/23 22:26:23 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(int errno)
{
	if (errno == 1)
		ft_putstr_fd("Error\nNúmero incorrecto de argumentos\n", 2);
	else if (errno == 2)
		ft_putstr_fd("Error\nEl argumento no es un archivo válido (.ber)\n", 2);
	else if (errno == 3)
		ft_putstr_fd("Error\nEl archivo no es un mapa válido\n", 2);
	exit(1);
}