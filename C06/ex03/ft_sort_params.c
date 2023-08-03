/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:03:46 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/26 12:39:33 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	my_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] != '\0' || s2[index] != '\0')
	{
		if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return (0);
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

int	main(int argc, char *argv[])
{
	int		index;
	int		index2;
	char	*smallest;

	index = 1;
	while (index < argc)
	{
		index2 = index;
		smallest = argv[index];
		while (index2 < argc)
		{
			if (my_strcmp(smallest, argv[index2]) > 0)
			{
				smallest = argv[index2];
				argv[index2] = argv[index];
				argv[index] = smallest;
			}
			index2++;
		}
		print(smallest);
		print("\n");
		index++;
	}
	return (0);
}
