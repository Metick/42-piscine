/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:27:17 by maraasve          #+#    #+#             */
/*   Updated: 2023/08/02 15:49:26 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/common.h"

t_bool	char_check(char c, t_map_file *file_strct)
{
	if (c < ' ' || c > '~' || (c != file_strct->info.empty
			&& c != file_strct->info.obstacle)
		|| c == file_strct->info.filled_in)
		return (FALSE);
	return (TRUE);
}

int	count_chars(char *buffer)
{
	int	count;

	while (*buffer != '\n')
		buffer++;
	buffer++;
	count = 0;
	while (buffer[count] != '\n')
		count++;
	return (count);
}

t_bool	get_characters(t_map_file *file_strct, char *buffer)
{
	int	count;

	count = 0;
	while (buffer[count] != '\n')
		count++; 
	if (count <= 3)
		return (FALSE);
	if ((buffer[count - 3] == buffer[count - 2])
		|| buffer[count - 3] == buffer[count - 1]
		|| buffer[count - 2] == buffer[count - 1])
		return (FALSE);
	file_strct->info.empty = buffer[count - 3];
	file_strct->info.obstacle = buffer[count - 2];
	file_strct->info.filled_in = buffer[count - 1];
	return (TRUE);
}

t_bool	fill(t_map_file *map, char *buffer)
{
	int	i;
	int	ii;

	while (*buffer != '\n')
		buffer++;
	buffer++;
	i = 0;
	while (i < map->info.column_size)
	{
		ii = 0;
		while (*buffer != '\n' && *buffer != '\0')
		{
			map->grid[i][ii] = *buffer;
			if (!char_check (map->grid[i][ii], map))
				return (FALSE);
			buffer++;
			ii++;
		}
		map->grid[i][ii] = '\0';
		buffer++;
		i++;
	}
	return (TRUE);
}

t_bool	parse_file(t_map_file **file_strct, char *buffer)
{
	int	column_size;
	int	row_size;

	column_size = my_atoi(buffer);
	if (column_size == -1)
		return (FALSE);
	row_size = count_chars(buffer);
	if (!create_map(file_strct, column_size, row_size))
		return (FALSE);
	if (!get_characters(*file_strct, buffer))
	{
		free_map(*file_strct);
		return (FALSE);
	}
	if (!fill(*file_strct, buffer))
	{
		free_map(*file_strct);
		return (FALSE);
	}
	return (TRUE);
}
