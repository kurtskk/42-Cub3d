/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:58:41 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 13:58:45 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cleanup_map_lines(t_list **map_lines)
{
	if (map_lines && *map_lines)
	{
		ft_lstclear(map_lines, free);
		*map_lines = NULL;
	}
}

int	cleanup_parse_error(t_cub *cub, t_list **map_lines)
{
	cleanup_map_lines(map_lines);
	return (cleanup_cub_return(cub));
}
