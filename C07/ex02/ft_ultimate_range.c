/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:28:22 by sgrootve          #+#    #+#             */
/*   Updated: 2023/08/02 17:24:27 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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

int	ft_ultimate_range(int **range, int min, int max)
{
	*range = ft_range(min, max);
	if (min >= max)
		return (0);
	if (range == 0)
		return (-1);
	return (max - min);
}

/* int	main(void)
{
	int *range;
	int min = 0;
	int max = 0;
	printf("%i\n", ft_ultimate_range(&range, min, max));
		for (int i = 0; i <= (max - min); i++)
	{
		printf("%i\n", range[i]);
	}
	return (0);
} */