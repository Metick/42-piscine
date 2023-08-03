/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:04:14 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/25 16:03:31 by sgrootve         ###   ########.fr       */
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
	if (argc >= 1)
		print(argv[0]);
	return (0);
}
