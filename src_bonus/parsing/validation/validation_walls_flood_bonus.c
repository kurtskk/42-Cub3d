/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_walls_flood_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:14:42 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:14:55 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	mark_neighbors(t_flood_params *params);
static int	check_boundaries(t_flood_params *params);

int	flood_fill_scan(t_flood_params *params, int sx, int sy)
{
	int	changed;

	if (sx < 0 || sy < 0 || sy >= params->height || sx >= params->width)
		return (1);
	params->grid[sy][sx] = 'V';
	changed = 1;
	while (changed)
	{
		changed = mark_neighbors(params);
		if (changed < 0)
			return (1);
	}
	return (check_boundaries(params));
}

static int	mark_neighbors(t_flood_params *params)
{
	int	x;
	int	y;
	int	changed;
	int	result;

	changed = 0;
	y = -1;
	while (++y < params->height)
	{
		x = -1;
		while (++x < params->width && params->grid[y][x])
		{
			if (params->grid[y][x] == 'V')
			{
				result = mark_adjacent_cells(params, x, y);
				if (result < 0)
					return (-1);
				if (result > 0)
					changed = 1;
			}
		}
	}
	return (changed);
}

static int	check_boundaries(t_flood_params *params)
{
	int	x;
	int	y;

	y = -1;
	while (++y < params->height)
	{
		x = -1;
		while (++x < params->width && params->grid[y][x])
		{
			if (params->grid[y][x] == 'V' || params->grid[y][x] == 'S')
			{
				if (x == 0 || y == 0)
					return (1);
				if (x == params->width - 1 || y == params->height - 1)
					return (1);
			}
		}
	}
	return (0);
}
