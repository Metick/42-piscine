/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:21:09 by maraasve          #+#    #+#             */
/*   Updated: 2023/08/02 14:58:55 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	my_put_char(char c)
{
	write(1, &c, 1);
}

int	my_print_str(char *str)
{
	int	index;

	if (str == 0)
		return (0);
	index = 0;
	while (str[index] != '\0')
	{
		my_put_char(str[index]);
		index++;
	}
	return (1);
}

void	exit_program(void)
{
	my_print_str("map error\n");
	exit(0);
}

int	my_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	return (len);
}

int	my_atoi(char *nb)
{
	int	sum;
	int	index;
	int	length;

	sum = 0;
	index = 0;
	length = my_strlen(nb);
	while (*nb && index < length - 3)
	{
		if (*nb >= '0' && *nb <= '9')
			sum = sum * 10 + *nb - '0';
		else
			break ;
		nb++;
		index++;
	}
	return (sum);
}
