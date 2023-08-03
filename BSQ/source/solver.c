/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:55:34 by maraasve          #+#    #+#             */
/*   Updated: 2023/08/02 16:39:22 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

int	empty_till_obstacle(t_map_file *map, int column, int row)
{
	int	count;

	count = 0;
	while (row < map->info.row_size + 1)
	{
		if (map->grid[column][row] == map->info.obstacle 
			|| map->grid[column][row] == '\0')
			return (count);
		count++;
		row++;
	}
	return (0);
}

t_bsq_info	set_data(int data, int column, int row)
{
	t_bsq_info	bsq;

	bsq.size = data;
	bsq.column = column;
	bsq.row = row;
	return (bsq);
}

t_bool	found_obstacle(int tmp[5], t_map_file *map, int row)
{
	tmp[2] = row;
	while (tmp[2] < (row + tmp[0]) && tmp[2] < map->info.row_size)
	{
		if (map->grid[tmp[1]][tmp[2]] == map->info.obstacle)
			return (TRUE);
		tmp[2]++;
	}
	return (FALSE);
}

t_bsq_info	find_square(t_map_file *map, int c, int row, int biggest_size)
{
	int			tmp[5];
	t_bsq_info	bsq;

	tmp[0] = 0;
	bsq.size = 0;
	tmp[3] = empty_till_obstacle(map, c, row);
	if (tmp[3] <= biggest_size)
		return (bsq);
	tmp[0] = biggest_size;
	while (tmp[0] <= tmp[3])
	{
		tmp[1] = c;
		tmp[4] = 0;
		while (tmp[1] < (c + tmp[0]) && tmp[1] < map->info.column_size)
		{
			if (found_obstacle(tmp, map, row))
				return (bsq);
			tmp[4]++;
			tmp[1]++;
		}
		if (tmp[0] > bsq.size && tmp[4] == tmp[0])
			bsq = set_data(tmp[0], c, row);
		tmp[0]++;
	}
	return (bsq);
}

t_bool	permutations(t_map_file *map)
{
	int			column;
	int			row;
	t_bsq_info	bsq;
	t_bsq_info	tmp_bsq;

	column = 0;
	bsq.size = 0;
	while (column < map->info.column_size)
	{
		row = 0;
		while (row < map->info.row_size)
		{
			tmp_bsq = find_square(map, column, row, bsq.size);
			if (bsq.size < tmp_bsq.size)
			{
				bsq.size = tmp_bsq.size;
				bsq.row = tmp_bsq.row;
				bsq.column = tmp_bsq.column;
			}
			row++;
		}
		column++;
	}
	print(map, &bsq);
	return (TRUE);
}
