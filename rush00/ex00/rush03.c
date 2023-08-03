/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:40:19 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/16 14:02:06 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_top03(int index2, int x)
{
	if (index2 == 0)
	{
		ft_putchar('A');
	}
	if (index2 == (x - 1))
	{
		ft_putchar('C');
	}
	if (index2 != 0 && index2 != (x - 1))
	{
		ft_putchar('B');
	}
}

void	print_bottom03(int index2, int x)
{
	if (index2 == 0)
	{
		ft_putchar('A');
	}
	if (index2 == (x - 1))
	{
		ft_putchar('C');
	}
	if (index2 != 0 && index2 != (x - 1))
	{
		ft_putchar('B');
	}
}

void	print_inner03(int index2, int x)
{
	if (index2 == 0 || index2 == (x - 1))
	{
		ft_putchar('B');
	}
	if (index2 != 0 && index2 != (x - 1))
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	index;
	int	index2;

	index = 0;
	while (index < y)
	{
		index2 = 0;
		while (index2 < x)
		{
			if (index == 0)
				print_top03(index2, x);
			else if (index == (y - 1))
				print_bottom03(index2, x);
			else
				print_inner03(index2, x);
			index2++;
		}
		ft_putchar('\n');
		index++;
	}
}
