/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_edges.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:03:43 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:04:21 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_top_edge(char **grid, int width);
static int	check_bottom_edge(char **grid, int width, int height);
static int	check_side_edges(char **grid, int width, int height);

static int	is_open_cell(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	check_top_edge(char **grid, int width)
{
	int	x;

	x = 0;
	while (x < width && grid[0][x])
	{
		if (is_open_cell(grid[0][x]))
			return (1);
		x++;
	}
	return (0);
}

static int	check_bottom_edge(char **grid, int width, int height)
{
	int	x;

	x = 0;
	while (x < width && grid[height - 1][x])
	{
		if (is_open_cell(grid[height - 1][x]))
			return (1);
		x++;
	}
	return (0);
}

static int	check_side_edges(char **grid, int width, int height)
{
	int	y;

	y = 0;
	while (y < height)
	{
		if (is_open_cell(grid[y][0]))
			return (1);
		if (is_open_cell(grid[y][width - 1]))
			return (1);
		y++;
	}
	return (0);
}

int	has_open_on_edges(char **grid, int width, int height)
{
	if (check_top_edge(grid, width))
		return (1);
	if (check_bottom_edge(grid, width, height))
		return (1);
	if (check_side_edges(grid, width, height))
		return (1);
	return (0);
}
