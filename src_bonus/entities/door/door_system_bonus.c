/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_system_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:12:25 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:13:41 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	update_door_state(t_cub *cub, int x, int y, int idx);

int	get_door_index(t_cub *cub, int x, int y)
{
	int	i;

	i = -1;
	while (++i < cub->map.num_doors)
	{
		if (cub->map.doors[i].x == x && cub->map.doors[i].y == y)
			return (i);
	}
	return (-1);
}

int	is_door_open(t_cub *cub, int x, int y)
{
	int	idx;

	idx = get_door_index(cub, x, y);
	if (idx >= 0)
		return (cub->map.doors[idx].is_open);
	return (0);
}

void	toggle_door(t_cub *cub)
{
	int	tx;
	int	ty;
	int	idx;

	tx = (int)(cub->player.pos_x + cub->player.dir_x * 1.2);
	ty = (int)(cub->player.pos_y + cub->player.dir_y * 1.2);
	if (tx < 0 || tx >= cub->map.width || ty < 0 || ty >= cub->map.height)
		return ;
	if (cub->map.grid[ty][tx] != 'D' && cub->map.grid[ty][tx] != 'O')
		return ;
	idx = get_door_index(cub, tx, ty);
	if (idx >= 0)
		update_door_state(cub, tx, ty, idx);
}

static void	update_door_state(t_cub *cub, int x, int y, int idx)
{
	int	p_x;
	int	p_y;

	p_x = (int)cub->player.pos_x;
	p_y = (int)cub->player.pos_y;
	if (cub->map.doors[idx].is_open)
	{
		if (p_x == x && p_y == y)
			return ;
		cub->map.grid[y][x] = 'D';
		cub->map.doors[idx].is_open = 0;
	}
	else
	{
		cub->map.grid[y][x] = 'O';
		cub->map.doors[idx].is_open = 1;
	}
}
