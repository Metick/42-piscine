/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:25:32 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/17 13:52:03 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	sort_lowest(int *tab, int size, int index2, int *lowest_value)
{
	while (index2 < size)
	{
		if (lowest_value[0] > tab[index2])
		{
			lowest_value[0] = tab[index2];
			lowest_value[1] = index2;
		}
		index2++;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	index;
	int	index2;
	int	lowest_value[2];

	index = 0;
	while (index < size)
	{
		lowest_value[0] = tab[index];
		lowest_value[1] = index;
		index2 = index;
		sort_lowest(tab, size, index2, lowest_value);
		if (index != lowest_value[1])
		{
			tab[index] = tab[index] ^ tab[lowest_value[1]];
			tab[lowest_value[1]] = tab[index] ^ tab[lowest_value[1]];
			tab[index] = tab[index] ^ tab[lowest_value[1]];
		}
		index++;
	}
}

/*int	main(void)
{
	int	arr[] = {9, 6, 3, 5,2,8,5,1, 4, 7, 9, 1, 1 ,2};

	ft_sort_int_tab(arr, sizeof(arr) / sizeof(arr[0]));

	for(int i =0; i < (int)(sizeof(arr) / sizeof(arr[0])); i++)
	{
		printf("%i", arr[i]);
	}

	return (0);
}*/
