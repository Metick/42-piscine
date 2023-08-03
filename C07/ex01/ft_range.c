/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:49:55 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/27 15:23:31 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	index;

	if (min >= max)
		return (0);
	array = malloc(sizeof(int) * (max - min));
	if (!array)
		return (0);
	index = 0;
	while (min <= max)
	{
		array[index] = min;
		min++;
		index++;
	}
	return (array);
}

/*int	main(void)
{
	int min = 5;
	int max = 11;
	int *array = ft_range(min, max);
	if (!array)
		return (0);
	for (int i = 0; i <= (max - min); i++)
	{
		printf("%i\n", array[i]);
	}

	free(array);
	return (0);
}*/