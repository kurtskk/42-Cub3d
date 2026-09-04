/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_parser_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:14:14 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:15:22 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	count_doors(t_map *map);
static void	store_door_positions(t_map *map);

int	parse_doors(t_map *map)
{
	int	count;

	count = count_doors(map);
	if (count == 0)
	{
		map->doors = NULL;
		map->num_doors = 0;
		return (0);
	}
	map->doors = ft_calloc(count, sizeof(t_door));
	if (!map->doors)
		return (1);
	map->num_doors = count;
	store_door_positions(map);
	return (0);
}

static int	count_doors(t_map *map)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width && map->grid[y][x])
		{
			if (map->grid[y][x] == 'D')
				count++;
		}
	}
	return (count);
}

static void	store_door_positions(t_map *map)
{
	int	y;
	int	x;
	int	idx;

	idx = 0;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width && map->grid[y][x])
		{
			if (map->grid[y][x] == 'D')
			{
				map->doors[idx].x = x;
				map->doors[idx].y = y;
				map->doors[idx].is_open = 0;
				map->doors[idx].open_offset = 0.0f;
				map->doors[idx].anim_frame = 0;
				idx++;
			}
		}
	}
}
