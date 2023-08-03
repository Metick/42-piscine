/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:07:15 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/26 14:46:59 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	print(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		put_char(str[index]);
		index++;
	}
	put_char('\n');
}

int	main(int argc, char *argv[])
{
	int	index;

	index = 1;
	while (index < argc)
	{
		print(argv[index]);
		index++;
	}
}
