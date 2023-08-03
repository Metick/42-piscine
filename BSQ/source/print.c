/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:50:50 by maraasve          #+#    #+#             */
/*   Updated: 2023/08/02 15:47:11 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	print_but_smaller(t_map_file *map, t_bsq_info *bsq,
		int grid[3], char *line)
{
	grid[1] = 0;
	while (grid[1] < map->info.row_size)
	{
		if (grid[1] >= bsq->row && grid[1] < bsq->row + bsq->size 
			&& grid[0] >= bsq->column && grid[0] < bsq->column + bsq->size)
			line[grid[1]] = map->info.filled_in;
		else
			line[grid[1]] = map->grid[grid[0]][grid[1]];
		grid[1]++;
	}
	line[grid[1]] = '\n';
	write(1, line, grid[2]);
}

t_bool	print(t_map_file *map, t_bsq_info *bsq)
{
	int		grid[3];
	char	*line;

	grid[2] = map->info.row_size + 1;
	line = (char *)malloc(sizeof(char) * grid[2]);
	if (line == NULL)
		return (FALSE);
	grid[0] = 0;
	while (grid[0] < map->info.column_size)
	{
		print_but_smaller(map, bsq, grid, line);
		grid[0]++;
	}
	free(line);
	return (TRUE);
}
