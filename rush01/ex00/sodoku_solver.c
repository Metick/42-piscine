/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sodoku_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluo <bluo@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:41:00 by bluo              #+#    #+#             */
/*   Updated: 2023/07/23 19:51:26 by bluo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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

int		g_finished = 0;
int		**input_filter(char *input);
void	print(char *str);
void	my_memset(int *dest, int value, int size);
void	my_memcpy(int *dest, int *src, int size);
int		*reverse_array(int *array, int size);
void	board_add_scrapers(t_board board, int **scrapers);
int		*get_column_from_array(int **grid, int size, int col);
void	mark_used(t_board board, int row, int col, int digit);
void	mark_not_used(t_board board, int row, int col, int digit);
int		repeat_skip(t_board board, int row, int col, int digit);
t_board	create_board(int size);
void	print_board(t_board board);
void	free_board(t_board board);
t_board	generate_board(int size, int **scrapers);
int		get_size(char *str);

int	is_view_ok(int requirement, int *array, int size)
{
	int	stand;
	int	view;
	int	skyscrapers;

	stand = 0;
	skyscrapers = 1;
	view = stand + 1;
	while (view < size)
	{
		if (array[stand] < array[view])
		{
			skyscrapers++;
			stand = view;
			view++;
		}
		else
			view++;
	}
	if (skyscrapers == requirement)
		return (1);
	else
		return (0);
}

int	check_all(t_board board)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (i < board.size)
	{
		if (!(is_view_ok(
					board.scrapers.row_left[i], board.grid.grid[i], board.size)
				&& is_view_ok(
					board.scrapers.row_right[i],
					reverse_array(board.grid.grid[i], board.size),
					board.size)
				&& is_view_ok(board.scrapers.col_up[i], 
					get_column_from_array(board.grid.grid, board.size, i),
					board.size)
				&& is_view_ok(
					board.scrapers.col_down[i], reverse_array(
						get_column_from_array(board.grid.grid, board.size, i),
						board.size),
					board.size)))
			return (0);
		i++;
	}
	return (result);
}

void	generate_and_check_grids(t_board board, int row, int col);

void	recursive_generate(t_board board, int digit, int row, int col)
{
	int	nextrow;
	int	nextcol;

	nextrow = 0;
	nextcol = 0;
	while (digit < board.size)
	{
		if (repeat_skip(board, row, col, digit))
		{
			digit++;
			continue ;
		}
		mark_used(board, row, col, digit);
		nextrow = row;
		nextcol = col + 1;
		if (nextcol == board.size)
		{
			nextrow++;
			nextcol = 0;
		}
		generate_and_check_grids(board, nextrow, nextcol);
		mark_not_used(board, row, col, digit);
		digit++;
	}
}

void	generate_and_check_grids(t_board board, int row, int col)
{
	int	digit;

	digit = 0;
	if (row == board.size)
	{
		if (check_all(board))
		{
			g_finished = 1;
			print_board(board);
		}
		return ;
	}
	if (!g_finished)
		recursive_generate(board, digit, row, col);
}

int	main(int argc, char *argv[])
{
	t_board	board;
	int		**scrapers;

	if (argc != 2)
	{
		print("Error\n");
		return (1);
	}
	scrapers = input_filter(argv[1]);
	if (scrapers == 0)
	{
		print("Error\n");
		return (0);
	}
	board = generate_board(get_size(argv[1]) / 4, scrapers);
	generate_and_check_grids(board, 0, 0);
	if (!g_finished)
		print("Error\n");
	free_board(board);
	return (0);
}
