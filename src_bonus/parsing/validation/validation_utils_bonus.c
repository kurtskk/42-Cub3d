/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:14:37 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:15:01 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static char	*allocate_and_copy_line(char *src, int width);

void	free_grid(char **grid)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (grid[i])
		free(grid[i++]);
	free(grid);
}

char	**copy_grid_padded(t_map *map)
{
	char	**new_grid;
	int		i;

	new_grid = ft_calloc(map->height + 1, sizeof(char *));
	if (!new_grid)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		new_grid[i] = allocate_and_copy_line(map->grid[i], map->width);
		if (!new_grid[i])
		{
			while (--i >= 0)
				free(new_grid[i]);
			free(new_grid);
			return (NULL);
		}
		i++;
	}
	new_grid[i] = NULL;
	return (new_grid);
}

static char	*allocate_and_copy_line(char *src, int width)
{
	char	*new_line;
	int		j;
	int		len;

	new_line = ft_calloc(width + 1, sizeof(char));
	if (!new_line)
		return (NULL);
	ft_strlcpy(new_line, src, width + 1);
	len = ft_strlen(src);
	j = len;
	while (j < width)
		new_line[j++] = ' ';
	new_line[j] = '\0';
	return (new_line);
}
