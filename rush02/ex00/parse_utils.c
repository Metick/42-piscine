/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:44:21 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/30 21:14:37 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	find_amount_lines(char *buf)
{
	int	index;
	int	count;

	count = 0;
	index = 0;
	while (buf[index] != '\0')
	{
		if (buf[index] == '\n')
			count++;
		index++;
	}
	return (count);
}

int	is_printable(char c)
{
	return (c >= 32 && c <= 127);
}

char	*mem_s(char **ptr, int size, char *buf, int index)
{
	int	i;

	*ptr = (char *)malloc(sizeof(char) * size + 1);
	if (!(*ptr))
		return (0);
	while (buf[(index - 1)] == ' ')
		index--;
	i = 0;
	while (i < size)
	{
		(*ptr)[i] = buf[((index - size)) + i];
		i++;
	}
	(*ptr)[size] = '\0';
	return (*ptr);
}
