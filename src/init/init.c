/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:01:27 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:02:01 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cub(t_cub *cub)
{
	cub->mlx = NULL;
	cub->win = NULL;
	cub->screen.img = NULL;
	cub->screen.addr = NULL;
	cub->map.no_texture = NULL;
	cub->map.so_texture = NULL;
	cub->map.we_texture = NULL;
	cub->map.ea_texture = NULL;
	cub->map.grid = NULL;
	cub->map.width = 0;
	cub->map.height = 0;
	cub->map.floor_color = -1;
	cub->map.ceil_color = -1;
	cub->map.player_dir = 0;
	cub->map.textures[0].img = NULL;
	cub->map.textures[1].img = NULL;
	cub->map.textures[2].img = NULL;
	cub->map.textures[3].img = NULL;
	cub->keys.w = 0;
	cub->keys.a = 0;
	cub->keys.s = 0;
	cub->keys.d = 0;
	cub->keys.left = 0;
	cub->keys.right = 0;
}

void	init_map(t_map *map)
{
	map->no_texture = NULL;
	map->so_texture = NULL;
	map->we_texture = NULL;
	map->ea_texture = NULL;
	map->floor_color = -1;
	map->ceil_color = -1;
	map->grid = NULL;
	map->player_dir = 0;
	map->width = 0;
	map->height = 0;
}
