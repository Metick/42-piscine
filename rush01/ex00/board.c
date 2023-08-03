/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluo <bluo@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:42:17 by sgrootve          #+#    #+#             */
/*   Updated: 2023/07/23 19:51:08 by bluo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	print(char *str);
void	printchar(char c);
void	my_memcpy(int *dest, int *src, int size);
void	my_memset(int *dest, int value, int size);
int		get_size(char *str);

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

t_board	create_board(int size)
{
	int		index;
	t_board	new_board;

	new_board.grid.grid = (int **)malloc(sizeof(int *) * size);
	new_board.scratchpad.used_row = (int **)malloc(sizeof(int *) * size);
	new_board.scratchpad.used_column = (int **)malloc(sizeof(int *) * size);
	new_board.scrapers.col_up = (int *)malloc(sizeof(int) * size);
	new_board.scrapers.col_down = (int *)malloc(sizeof(int) * size);
	new_board.scrapers.row_left = (int *)malloc(sizeof(int) * size);
	new_board.scrapers.row_right = (int *)malloc(sizeof(int) * size);
	index = 0;
	while (index < size)
	{
		new_board.grid.grid[index] = (int *)malloc(sizeof(int) * size);
		new_board.scratchpad.used_row[index] = (int *)malloc(
				sizeof(int) * size);
		new_board.scratchpad.used_column[index] = (int *)malloc(
				sizeof(int) * size);
		index++;
	}
	new_board.size = size;
	return (new_board);
}

void	free_board(t_board board)
{
	int	index;

	index = 0;
	while (index < board.size)
		free(board.grid.grid[index++]);
	index = 0;
	while (index < board.size)
	{
		free(board.scratchpad.used_row[index]);
		free(board.scratchpad.used_column[index]);
		index++;
	}
	free(board.grid.grid);
	free(board.scratchpad.used_row);
	free(board.scratchpad.used_column);
	free(board.scrapers.col_up);
	free(board.scrapers.col_down);
	free(board.scrapers.row_left);
	free(board.scrapers.row_right);
	board.size = 0;
}

void	board_add_scrapers(t_board board, int **scrapers)
{
	int	size;
	int	index;

	size = board.size;
	index = 0;
	while (index < 4)
	{
		if (index == 0)
			my_memcpy(board.scrapers.col_up, scrapers[index],
				sizeof(int) * size);
		else if (index == 1)
			my_memcpy(board.scrapers.col_down, scrapers[index],
				sizeof(int) * size);
		else if (index == 2)
			my_memcpy(board.scrapers.row_left, scrapers[index],
				sizeof(int) * size);
		else if (index == 3)
			my_memcpy(board.scrapers.row_right, scrapers[index],
				sizeof(int) * size);
		index++;
	}
}

void	print_board(t_board board)
{
	int	i;
	int	j;

	i = 0;
	while (i < board.size)
	{
		j = 0;
		while (j < board.size)
		{
			printchar(board.grid.grid[i][j] + '0');
			if (j < board.size - 1)
				printchar(' ');
			j++;
		}
		printchar('\n');
		i++;
	}
}

t_board	generate_board(int size, int **scrapers)
{
	t_board	board;
	int		digit;

	board = create_board(size);
	board_add_scrapers(board, scrapers);
	digit = 0;
	while (digit < board.size)
	{
		my_memset(&board.scratchpad.used_row[digit][0],
			0, sizeof(int) * board.size);
		my_memset(&board.scratchpad.used_column[digit][0],
			0, sizeof(int) * board.size);
		digit++;
	}
	return (board);
}
