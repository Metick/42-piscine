/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:10:40 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/25 16:02:58 by sgrootve         ###   ########.fr       */
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

	index = argc - 1;
	while (index > 0)
	{
		print(argv[index]);
		index--;
	}
	return (0);
}
