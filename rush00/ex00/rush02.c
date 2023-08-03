/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rush02.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 17:55:24 by sramos        #+#    #+#                 */
/*   Updated: 2023/07/16 12:16:00 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_top(int index2, int x)
{
	if (index2 == 0)
		ft_putchar('A');
	if (index2 == x - 1)
		ft_putchar ('A');
	if (index2 != 0 && index2 != x - 1)
		ft_putchar('B');
}

void	print_bottom(int index2, int x)
{
	if (index2 == 0)
		ft_putchar('C');
	if (index2 == x - 1)
		ft_putchar('C');
	if (index2 != 0 && index2 != x - 1)
		ft_putchar('B');
}

void	print_inner(int index2, int x)
{
	if (index2 == 0)
		ft_putchar('B');
	if (index2 == x - 1)
		ft_putchar('B');
	if (index2 != 0 && index2 != x -1)
		ft_putchar(' ');
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
				print_top(index2, x);
			else if (index == y - 1)
				print_bottom(index2, x);
			else
				print_inner(index2, x);
			index2++;
		}
		ft_putchar('\n');
		index++;
	}
}
