/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:12:46 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:13:12 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	handle_mouse(int x, int y, t_cub *cub)
{
	int	diff_x;

	(void)y;
	diff_x = x - (WIN_WIDTH / 2);
	if (diff_x != 0)
		rotate_player(cub, diff_x * ROT_SPEED_MOUSE);
	mlx_mouse_move(cub->mlx, cub->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}
