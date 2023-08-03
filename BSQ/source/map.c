/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:27:26 by sgrootve          #+#    #+#             */
/*   Updated: 2023/08/02 15:30:33 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

t_bool	create_map(t_map_file **map, int column_size, int row_size)
{
	int	index;

	*map = (t_map_file *)malloc(sizeof(t_map_file));
	if (!(*map))
		return (FALSE);
	(*map)->grid = (char **)malloc(sizeof(char *) * column_size);
	if (!(*map)->grid)
		return (FALSE);
	index = 0;
	while (index < column_size)
	{
		(*map)->grid[index] = (char *)malloc(sizeof(char) * row_size + 1);
		if (!(*map)->grid[index])
			return (FALSE);
		index++;
	}
	(*map)->info.row_size = row_size;
	(*map)->info.column_size = column_size;
	return (TRUE);
}

void	free_map(t_map_file *map)
{
	int	index;

	index = 0;
	while (index < map->info.column_size)
	{
		if (map->grid[index])
			free(map->grid[index]);
		index++;
	}
	if (map->grid)
		free(map->grid);
	if (map)
		free(map);
}
