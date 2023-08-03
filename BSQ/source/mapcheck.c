/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:42:08 by maraasve          #+#    #+#             */
/*   Updated: 2023/08/02 15:30:21 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

void	map_check(char *buffer, t_map_file *map)
{
	int		line_len;
	int		index;

	line_len = 0;
	index = 0;
	while (buffer[index] != '\0')
	{
		if (buffer[index] == '\n')
		{
			if (line_len != map->row_size)
				exit_program();
			line_len = 0;
		}
		index++;
		line_len++;
	}
}
