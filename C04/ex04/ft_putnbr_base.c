/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:58:14 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/29 15:54:11 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print(char c)
{
	write(1, &c, 1);
}

int	my_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

void	calculate(int nb, int base_len, char *base)
{
	if (my_abs(nb / base_len))
	{
		calculate(nb / base_len, base_len, base);
		print(base[my_abs(nb % base_len)]);
	}
	else
	{
		if (nb < 0)
			print('-');
		print(base[my_abs(nb)]);
	}
}

int	check_base(char *str)
{
	int	len;
	int	index;

	if (str == 0)
		return (0);
	len = 0;
	while (str[len] != '\0')
	{
		index = len + 1;
		while (str[index] != '\0')
		{
			if (str[len] == str[index])
				return (0);
			index++;
		}
		if (str[len] == '+' || str[len] == '-')
			return (0);
		len++;
	}
	if (len <= 1)
		return (0);
	return (len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = check_base(base);
	if (!base_len)
		return ;
	calculate(nbr, base_len, base);
}

int	main(void)
{
	ft_putnbr_base(-500, "0123456789");
	printf("\n");
	return (0);
}
