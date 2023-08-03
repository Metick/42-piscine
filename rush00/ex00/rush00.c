/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rush00.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvan-de- <kvan-de-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/16 13:32:10 by kvan-de-      #+#    #+#                 */
/*   Updated: 2023/07/16 13:56:18 by kvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_top(int w, int x)
{
	if (w == 0)
	{
		ft_putchar('o');
	}
	if (w == x - 1)
	{
		ft_putchar('o');
	}
	if (w != 0 && w != x - 1)
	{
		ft_putchar('-');
	}
}

void	print_bottom(int w, int x)
{
	if (w == 0)
	{
		ft_putchar('o');
	}
	if (w == x - 1)
	{
		ft_putchar('o');
	}
	if (w != 0 && w != x - 1)
	{
		ft_putchar('-');
	}
}

void	print_middle(int w, int x)
{
	if (w != 0 && w != x - 1)
	{
		ft_putchar(' ');
	}
	else
	{
		ft_putchar('|');
	}
}

void	rush(int x, int y)
{
	int	w;
	int	h;

	h = 0;
	while (h < y)
	{
		w = 0;
		while (w < x)
		{
			if (h == 0)
				print_top(w, x);
			if (h == y - 1)
				print_bottom(w, x);
			if (h != 0 && h != y - 1)
				print_middle(w, x);
			w++;
		}
		ft_putchar('\n');
		h++;
	}
}
