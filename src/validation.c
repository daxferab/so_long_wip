/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:16:45 by daxferna          #+#    #+#             */
/*   Updated: 2024/12/24 16:57:11 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	is_map_valid(char	*arg)
{
	return(true);
}

bool	is_ber_extension(char	*archive)
{
	char	*tmp;
	int		archive_len;

	tmp = archive;
	archive_len = ft_strlen(archive);
	if (archive_len < 4)
		return (false);
	if (ft_strncmp(archive + archive_len - 4, ".ber", 4) != 0)
		return (false);
	return (true);
}

void	validate_arg(char	*arg)
{
	if (!is_ber_extension(arg))
		error(2);
	if (!is_map_valid(arg))
		error(3);
}
