/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:12:39 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:13:22 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	init_keys(t_cub *cub);
static void	init_map_data(t_cub *cub);
static void	init_textures_and_sprites(t_cub *cub);

void	init_cub(t_cub *cub)
{
	cub->mlx = NULL;
	cub->win = NULL;
	cub->screen.img = NULL;
	cub->screen.addr = NULL;
	cub->z_buffer = NULL;
	cub->map.minimap.enabled = 1;
	cub->map.minimap.size = MINIMAP_SIZE;
	cub->map.minimap.scale = MINIMAP_SCALE;
	cub->player.last_mouse_x = -1;
	init_map_data(cub);
	init_textures_and_sprites(cub);
	init_keys(cub);
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
	map->doors = NULL;
	map->num_doors = 0;
}

static void	init_textures_and_sprites(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		cub->map.textures[i].img = NULL;
		i++;
	}
	i = 0;
	while (i < 9)
	{
		cub->map.sprite_frames[i].img = NULL;
		i++;
	}
}

static void	init_keys(t_cub *cub)
{
	cub->keys.w = 0;
	cub->keys.a = 0;
	cub->keys.s = 0;
	cub->keys.d = 0;
	cub->keys.left = 0;
	cub->keys.right = 0;
	cub->keys.up = 0;
	cub->keys.down = 0;
}

static void	init_map_data(t_cub *cub)
{
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
	cub->map.doors = NULL;
	cub->map.num_doors = 0;
	cub->map.sprites = NULL;
	cub->map.num_sprites = 0;
	cub->map.has_exit = 0;
}
