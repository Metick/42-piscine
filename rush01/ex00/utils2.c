/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluo <bluo@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:29:40 by bluo              #+#    #+#             */
/*   Updated: 2023/07/23 19:06:45 by bluo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_grid
{
	int	**grid;
}	t_grid;

typedef struct s_scrapers
{
	int	*col_up;
	int	*col_down;
	int	*row_left;
	int	*row_right;
}	t_scrapers;

typedef struct s_scratchpad
{
	int	**used_row;
	int	**used_column;
}	t_scratchpad;

typedef struct s_board
{
	t_grid			grid;
	t_scrapers		scrapers;
	t_scratchpad	scratchpad;
	int				size;
}	t_board;

int	*get_column_from_array(int **grid, int size, int col)
{
	int	row;
	int	*col_array;

	row = 0;
	col_array = (int *)malloc(sizeof(int) * size);
	while (row < size)
	{
		col_array[row] = grid[row][col];
		row++;
	}
	return (col_array);
}

void	mark_used(t_board board, int row, int col, int digit)
{
	board.grid.grid[row][col] = digit + 1;
	board.scratchpad.used_row[row][digit] = 1;
	board.scratchpad.used_column[col][digit] = 1;
}

void	mark_not_used(t_board board, int row, int col, int digit)
{
	board.scratchpad.used_row[row][digit] = 0;
	board.scratchpad.used_column[col][digit] = 0;
}

int	repeat_skip(t_board board, int row, int col, int digit)
{
	if (board.scratchpad.used_row[row][digit]
	|| board.scratchpad.used_column[col][digit])
		return (1);
	else
		return (0);
}
