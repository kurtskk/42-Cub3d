/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_walls_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:14:46 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:14:51 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	mark_cell(t_flood_params *params, int x, int y);
static int	is_on_edge(t_flood_params *params, int x, int y);
static int	is_out_of_bounds(t_flood_params *params, int x, int y);
static int	check_space_leaks(t_flood_params *params, int x, int y);

int	mark_adjacent_cells(t_flood_params *params, int x, int y)
{
	int	result;
	int	changed;

	changed = 0;
	result = mark_cell(params, x + 1, y);
	if (result < 0)
		return (-1);
	changed += result;
	result = mark_cell(params, x - 1, y);
	if (result < 0)
		return (-1);
	changed += result;
	result = mark_cell(params, x, y + 1);
	if (result < 0)
		return (-1);
	changed += result;
	result = mark_cell(params, x, y - 1);
	if (result < 0)
		return (-1);
	changed += result;
	return (changed);
}

static int	mark_cell(t_flood_params *params, int x, int y)
{
	if (is_out_of_bounds(params, x, y))
		return (-1);
	if (params->grid[y][x] == ' ')
	{
		if (check_space_leaks(params, x, y))
			return (-1);
		params->grid[y][x] = 'V';
		return (1);
	}
	if (params->grid[y][x] == '1' || params->grid[y][x] == 'V')
		return (0);
	params->grid[y][x] = 'V';
	return (1);
}

static int	is_out_of_bounds(t_flood_params *params, int x, int y)
{
	if (x < 0 || y < 0 || y >= params->height || x >= params->width)
		return (1);
	if (x >= (int)ft_strlen(params->grid[y]))
		return (1);
	if (params->grid[y][x] == '\0')
		return (1);
	return (0);
}

static int	is_on_edge(t_flood_params *params, int x, int y)
{
	if (x == 0 || y == 0)
		return (1);
	if (x == params->width - 1 || y == params->height - 1)
		return (1);
	return (0);
}

static int	check_space_leaks(t_flood_params *params, int x, int y)
{
	if (is_out_of_bounds(params, x, y))
		return (1);
	if (is_on_edge(params, x, y))
		return (1);
	return (0);
}
