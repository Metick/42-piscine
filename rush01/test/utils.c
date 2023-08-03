/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:51:28 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/23 12:17:08 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c)
{
	write(1, &c, 1);
}

void	print2(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		print(str[index]);
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
