/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:25:26 by sgrootve          #+#    #+#             */
/*   Updated: 2023/08/02 17:37:13 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"
#include <stdio.h>

void	run_map(t_map_file *map, int fd, char *buffer,
				unsigned long buffer_size)
{
	if (!read_file(fd, buffer, buffer_size))
	{
		free(buffer);
		my_print_str("map error\n");
		return ;
	}
	if (!parse_file(&map, buffer))
	{
		free(buffer);
		my_print_str("map error\n");
		return ;
	}
	if (!close_file(fd))
	{
		free(buffer);
		my_print_str("map error\n");
		return ;
	}
	permutations(map);
	free_map(map);
	free(buffer);
}

void	display_map(char *map_buffr)
{
	t_map_file		*map;
	int				fd;
	unsigned long	buffer_size;
	char			*buffer;

	buffer_size = calc_total_buffer(map_buffr);
	buffer = (char *)malloc(sizeof(char) * buffer_size);
	fd = open_file(map_buffr);
	if (fd == -1)
	{
		free(buffer);
		my_print_str("map error\n");
		return ;
	}
	run_map(map, fd, buffer, buffer_size);
}

int	main(int argc, char *argv[])
{
	int	index;

	index = 1;
	if (argc < 2)
		return (0);
	while (index < argc)
	{
		display_map(argv[index]);
		index++;
	}
	return (0);
}
