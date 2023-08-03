/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:30:24 by sgrootve          #+#    #+#             */
/*   Updated: 2023/08/02 13:19:29 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/common.h"

/* Open file for both reading & writing. */
int	open_file(char *given_file)
{
	int	file;

	file = 0;
	file = open(given_file, O_RDWR);
	return (file);
}

t_bool	read_file(int file, char *buf, int size)
{
	return (read(file, buf, size) > 0);
}

t_bool	close_file(int file)
{
	return (close(file) == 0);
}
