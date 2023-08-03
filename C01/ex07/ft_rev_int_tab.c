/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:44:40 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/17 13:50:02 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	tmp;
	int	even;

	even = 0;
	index = 0;
	if (size % 2 == 0)
		even = 1;
	while (index <= (size / 2) - even)
	{
		if (index != (size - index - 1))
		{
			tmp = tab[index];
			tab[index] = tab[size - index - 1];
			tab[size - index - 1] = tmp;
		}
		index++;
	}
}

/*int main(void)
{
	int arr[]= {1, 2, 3, 4, 5, 6, 7};

	ft_rev_int_tab(arr, sizeof(arr) / sizeof(arr[0]));

	for(int i = 0; i < (int)(sizeof(arr) / sizeof(arr[0])); i++)
		printf("%i\n", arr[i]);

	return (0);
}*/
