/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_parser_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:14:17 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:15:18 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	parse_exit(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width && map->grid[y][x])
		{
			if (map->grid[y][x] == 'J')
			{
				map->exit_pos.x = x + 0.5;
				map->exit_pos.y = y + 0.5;
				map->exit_pos.dist = 0.0;
				map->has_exit = 1;
				return (0);
			}
		}
	}
	map->has_exit = 0;
	return (0);
}
