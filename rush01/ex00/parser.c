/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:12:17 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/23 18:25:54 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	first visualisation of input parser, still using forbidden funcs for now
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	is_integer(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	get_size(char *str)
{
	int	index[2];
	int	new_word;

	new_word = 1;
	index[0] = 0;
	index[1] = 0;
	while (str[index[0]] != '\0')
	{
		while (str[index[0]] == ' ')
		{
			new_word++;
			index[0]++;
		}
		if (is_integer(str[index[0]]) && new_word == 1)
		{
			index[1]++;
			new_word = 0;
		}
		else
			return (0);
		index[0]++;
	}
	return (index[1]);
}

int	**parse_setup(char *str)
{
	int	**array;
	int	i;
	int	size;

	size = get_size(str);
	if (size == 0 || size % 4 != 0 || size < 16)
		return (0);
	size = size / 4;
	array = (int **)malloc(sizeof(int) * (size * size));
	i = 0;
	while (i < size)
	{
		array[i] = (int *)malloc(sizeof(int) * size);
		i++;
	}
	return (array);
}

int	**parse(char *input, int **array, int size)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	index = 0;
	while ((input[index] != '\0') && (i < size))
	{
		j = 0;
		while (j < size)
		{
			if (input[index] != ' ')
			{
				array[i][j] = input[index] - '0';
				j++;
			}
			else
				array[i][j] = 0;
			index++;
		}
		i++;
	}
	return (array);
}

int	**input_filter(char *input)
{
	int	**array;
	int	size;

	array = parse_setup(input);
	if (array == 0)
		return (0);
	size = get_size(input);
	return (parse(input, array, size / 4));
}
