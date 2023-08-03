/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:09:18 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/25 16:08:12 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c)
{
	write(1, &c, 1);
}

void	calculate_positive(int nb)
{
	if (nb > 9)
	{
		if (nb / 10)
		{
			calculate_positive(nb / 10);
			print((nb % 10) + '0');
		}
		else
		{
			print(nb + '0');
		}
	}
	if (nb >= 0 && nb <= 9)
		print(nb + '0');
}

void	calculate_negative(int nb)
{
	if (nb / 10)
	{
		calculate_negative(nb / 10);
		print(-(nb % 10) + '0');
	}
	else
	{
		print('-');
		print((-nb) + '0');
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		calculate_negative(nb);
	}
	else
	{
		calculate_positive(nb);
	}
}

/*int	main(void)
{
	ft_putnbr(2147483647);
	return (0);
}*/
