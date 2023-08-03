/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:51:28 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/23 18:26:56 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	printchar(char c)
{
	write(1, &c, 1);
}

void	print(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		write(1, &str[index], 1);
		index++;
	}
}

void	my_memcpy(int *dest, int *src, int size)
{
	int	len;

	len = 0;
	while (len < size)
	{
		dest[len] = src[len];
		len++;
	}
}

void	my_memset(int *dest, int value, int size)
{
	int	len;

	len = 0;
	while (len < size)
	{
		dest[len] = value;
		len++;
	}
}

int	*reverse_array(int *array, int size)
{
	int	*new_array;
	int	start;
	int	end;

	new_array = (int *)malloc(sizeof(int) * size);
	start = 0;
	end = size - 1;
	while (end >= 0)
	{
		new_array[start] = array[end];
		end--;
		start++;
	}
	return (new_array);
}
