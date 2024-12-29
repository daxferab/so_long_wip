/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:16:45 by daxferna          #+#    #+#             */
/*   Updated: 2024/12/29 01:14:37 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	is_ber_extension(char	*archive)
{
	int		archive_len;

	archive_len = ft_strlen(archive);
	if (archive_len < 5)
		return (false);
	if (ft_strncmp(archive + archive_len - 4, ".ber", 4) != 0)
		return (false);
	return (true);
}

void	validate_arg(char	*arg, t_map	*game_map)
{
	if (!is_ber_extension(arg))
		error(2);
	if (!is_map_valid(arg, game_map))
		error(3);
}
