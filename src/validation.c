/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:16:45 by daxferna          #+#    #+#             */
/*   Updated: 2024/12/23 22:32:27 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	is_map_valid(char	*arg)
{

}

bool	is_ber_extension(char	*archive)
{
	
}

void	validate_arg(char	*arg)
{
	if (!is_ber_extension(arg))
		error(2);
	if (!is_map_valid(arg))
		error(3);
}
