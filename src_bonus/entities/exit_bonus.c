/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:12:33 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:13:30 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	show_win_message(t_cub *cub);

void	check_exit(t_cub *cub)
{
	int	map_x;
	int	map_y;

	map_x = (int)cub->player.pos_x;
	map_y = (int)cub->player.pos_y;
	if (map_x < 0 || map_x >= cub->map.width
		|| map_y < 0 || map_y >= cub->map.height)
		return ;
	if (cub->map.grid[map_y][map_x] == 'J')
	{
		show_win_message(cub);
		close_window(cub);
	}
}

static void	show_win_message(t_cub *cub)
{
	(void)cub;
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("╔════════════════════════════════════╗\n", 1);
	ft_putstr_fd("║   CONNECTION TERMINATED            ║\n", 1);
	ft_putstr_fd("║   JACK OUT SUCCESSFUL              ║\n", 1);
	ft_putstr_fd("║   EXITING CYBERSPACE...            ║\n", 1);
	ft_putstr_fd("╚════════════════════════════════════╝\n", 1);
	ft_putstr_fd("\n", 1);
}
