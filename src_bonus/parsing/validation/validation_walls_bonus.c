/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_walls_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:14:40 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:14:58 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	is_open_cell(char c);
static int	check_side_edges(char **grid, int width, int height);
static int	has_open_on_edges(char **grid, int width, int height);
static int	check_top_bottom_edges(char **grid, int width, int height);

int	check_walls(t_map *map)
{
	char			**temp_grid;
	int				ret;
	t_flood_params	params;

	temp_grid = copy_grid_padded(map);
	if (!temp_grid)
		return (ft_putstr_fd(ERR_MALLOC, 2), 1);
	if (has_open_on_edges(temp_grid, map->width, map->height))
	{
		free_grid(temp_grid);
		return (ft_putstr_fd("Error\nOpen cells on border\n", 2), 1);
	}
	params.grid = temp_grid;
	params.height = map->height;
	params.width = map->width;
	ret = flood_fill_scan(&params, map->player_x, map->player_y);
	free_grid(temp_grid);
	if (ret)
		return (ft_putstr_fd("Error\nMap is not closed\n", 2), 1);
	return (0);
}

static int	has_open_on_edges(char **grid, int width, int height)
{
	if (check_top_bottom_edges(grid, width, height))
		return (1);
	if (check_side_edges(grid, width, height))
		return (1);
	return (0);
}

static int	is_open_cell(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E')
		return (1);
	if (c == 'W' || c == 'D' || c == 'X' || c == 'J')
		return (1);
	return (0);
}

static int	check_top_bottom_edges(char **grid, int width, int height)
{
	int	x;

	x = 0;
	while (x < width && grid[0][x])
	{
		if (is_open_cell(grid[0][x]))
			return (1);
		x++;
	}
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
		if (width - 1 < (int)ft_strlen(grid[y]))
		{
			if (is_open_cell(grid[y][width - 1]))
				return (1);
		}
		y++;
	}
	return (0);
}
