/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:50:51 by sgrootve          #+#    #+#             */
/*   Updated: 2023/08/02 16:24:22 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

unsigned long	get_row_count2(int fd, char *map_buffr, unsigned long row_size)
{
	unsigned long	row_count;
	unsigned long	row_check;
	int				first_line;
	char			buffer[1];

	row_count = 0;
	row_check = 0;
	first_line = 0;
	while (read_file(fd, buffer, sizeof(buffer)))
	{
		if (*buffer == '\n')
		{
			if (first_line && row_check != row_size)
				return (0);
			first_line = 1;
			row_count++;
			row_check = 0;
		}
		row_check++;
	}
	return (row_count);
}

unsigned long	get_row_count(char *map_buffr, unsigned long row_size)
{
	int				fd;
	unsigned long	row_count;

	fd = open_file(map_buffr);
	if (!fd)
		return (0);
	row_count = get_row_count2(fd, map_buffr, row_size);
	if (!close_file(fd))
		return (0);
	return (row_count);
}

unsigned long	get_buffer_size_column(char *map_buffr)
{
	unsigned long	count;
	int				fd;
	char			buffer[1];

	fd = open_file(map_buffr);
	if (!fd)
		return (0);
	count = 0;
	while (read_file(fd, buffer, sizeof(buffer)))
	{
		if (*buffer == '\n')
			break ;
		count++;
	}
	if (!close_file(fd))
		return (0);
	return (count);
}

unsigned long	get_buffer_size_row(char *map_buffr)
{
	unsigned long	count;
	int				new_line_count;
	int				fd;
	char			buffer[1];

	fd = open_file(map_buffr);
	if (!fd)
		return (0);
	count = 0;
	new_line_count = 0;
	while (read_file(fd, buffer, sizeof(buffer)))
	{
		if (*buffer == '\n' && new_line_count == 1)
			break ;
		if (*buffer == '\n')
			new_line_count = 1;
		if (new_line_count == 1)
			count++;
	}
	if (!close_file(fd))
		return (0);
	return (count);
}

unsigned long	calc_total_buffer(char *map_buffr)
{
	char			*buffer;
	int				fd;
	unsigned long	row_size;		
	unsigned long	total_buffer;
	unsigned long	column_size;

	column_size = get_buffer_size_column(map_buffr);
	row_size = get_buffer_size_row(map_buffr);
	buffer = (char *)malloc(sizeof(char) * column_size + 1);
	fd = open_file(map_buffr);
	if (!fd)
		return (0);
	if (!read_file(fd, buffer, column_size))
		return (0);
	total_buffer = my_atoi(buffer);
	free(buffer);
	if (!close_file(fd))
		return (0);
	if (total_buffer != get_row_count(map_buffr, row_size) - 1 
		|| total_buffer == 0)
		return (0);
	return ((total_buffer * row_size)
		+ (column_size + 1));
}
