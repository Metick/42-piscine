/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sodoku_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:41:00 by bluo              #+#    #+#             */
/*   Updated: 2023/07/23 17:08:22 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//input: array row, array column, sodoku board
//output: array [4][4]

#include <stdlib.h>
#include <stdio.h>

int	is_unique_array(int *array, int size)
{
	int	base;
	int comp;
	
	base = 0;
	comp = 0;
	while (base < size - 1)
	{
		comp = base + 1;
		while (comp < size)
		{
			if (array[base] == array[comp])
			{
				return (0);
			}
			comp++;
		}
		base++;
	}
	return (1);
}

int	is_view_OK(int requirement, int *array, int size)
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
		{
			view++;
		}
	}
	if (skyscrapers == requirement)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int *reverse_array(int *array, int size)
{
	int *new_array = (int*)malloc(sizeof(int) * size);
	int start;
	int	end;

	start = 0;
	end = size - 1;
	while (end >= 0)
	{
		new_array[start] = array[end];
		end--;
		start++;
	}
	return (new_array);
}

int	*get_column_from_array(int **grid, int size, int col)
{
	int	row;
	int *col_array = (int *)malloc(sizeof(int)*size);

	row = 0;
	while (row < size)
	{
		col_array[row] = grid[row][col];
		row++;
	}
	return (col_array);
}

int	check_all(int **grid, int size, int *col_up,
	int *col_down,
	int *row_left,
	int *row_right)
{
	int	row = 0;
	int	col = 0;
	int	result = 1;
	int	*array;

	while (row < size)
	{
		array = grid[row];
		if (
			// is_unique_array(array, size)
			 is_view_OK(row_left[row], array, size)
			// && is_unique_array(reverse_array(array,size), size)
			&& is_view_OK(row_right[row], reverse_array(array,size), size)
		)
		{
			result = result * 1;
		}
		else
		{
			return (0);
		}
		row++;
	}
	while (col < size)
	{
		array = get_column_from_array(grid, size, col);
		if (
			// is_unique_array(array, size)
			 is_view_OK(col_up[col], array, size)
			// && is_unique_array(reverse_array(array,size), size)
			&& is_view_OK(col_down[col], reverse_array(array,size), size)
		)
		{
			result = result * 1;
		}
		else
		{
			return (0);
		}
		col++;
	}
	return (result);		
}

#include <stdio.h>
void print_grid(int **grid, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
}

void generate_and_check_grids(int **grid, int row, int col, int size, int *col_up, int *col_down, int *row_left, int *row_right, int *row_used_digits, int *col_used_digits) {
    if (row == size) {
        // We have generated a complete grid, check if it satisfies the condition
        int result = check_all(grid, size, col_up, col_down, row_left, row_right);
        if (result == 1) {
			printf("This is OK!!!!!!!!!!!!!!!!!!!!!! \n");
            // Print the final grid that satisfies the condition
            print_grid(grid, size, size);
            exit(0); // Exit the program, as we found a solution
        }
        return;
    }
    printf("This is NOK \n");
	print_grid(grid, size, size);

    // Loop through digits from 1 to 4 for the current cell
    for (int digit = 1; digit <= 4; digit++) {
        // If the digit is already used in the current row or column, skip it
        if (row_used_digits[row] & (1 << digit) || col_used_digits[col] & (1 << digit)) {
            continue; // Skip this digit and move to the next one
        }

        // Mark the digit as used in the current row and column
        row_used_digits[row] |= (1 << digit);
        col_used_digits[col] |= (1 << digit);

        grid[row][col] = digit;

        // Move to the next cell (row-wise, column-wise)
        int nextRow = row;
        int nextCol = col + 1;
        if (nextCol == size) {
            nextRow++;
            nextCol = 0;
        }

        // Recursively generate and check the next grid
        generate_and_check_grids(grid, nextRow, nextCol, size, col_up, col_down, row_left, row_right, row_used_digits, col_used_digits);

        // Unmark the digit as used in the current row and column for backtracking
        row_used_digits[row] &= ~(1 << digit);
        col_used_digits[col] &= ~(1 << digit);
    }
}


int	main(void)
{
	// int	array[4] = {1,2,2,4};

	// printf("%d \n", is_unique_array(array, 4));
	

	//Test2
	// int requirement = 3;
	// // int array[4] = {3,2,4,1};
	// int array[4] = {1,2,4,3};
	// printf("%d \n", is_view_OK(requirement, array, 4));

	//Test 3
	// int array[4] = {1,2,4,3};
	// int *new_array;
	// new_array = reverse_array(array, 4);
	// int i = 0;
	// while (i < 4)
	// {
	// 	printf("%d ", new_array[i]);
	// 	i++;
	// }

	// free(new_array);

	//Test 4
	
	// int rows = 4;
    // int cols = 4;

    // // Test grid - a 4x4 grid with example values
    // int **grid = (int **)malloc(rows * sizeof(int *));
    // for (int i = 0; i < rows; i++) {
    //     grid[i] = (int *)malloc(cols * sizeof(int));
    // }

    // // Fill the grid with some values
    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < cols; j++) {
    //         grid[i][j] = i * cols + j + 1; // Some example values
    //     }
    // }
	// /*
    // // Call the function to get the first column (column index 0)
    // int *first_column = get_column_from_array(grid, rows, 0);

    // // Print the elements of the first column
    // printf("First column elements:\n");
    // for (int i = 0; i < rows; i++) {
    //     printf("%d\n", first_column[i]);
    // }

    // // Don't forget to free the dynamically allocated memory.
    // for (int i = 0; i < rows; i++) {
    //     free(grid[i]);
    // }
	// */
	// int result = 0;

	// int col_up[4] = {4, 3, 2, 1}/*up*/;
	// int col_down[4] = {1, 2, 2, 2}/*down*/;
	// int row_left[4] = {4, 3, 2, 1}/*left*/; 
	// int	row_right[4] = {1, 2, 2, 2}/*right*/;
	// result = check_all(grid, 4, col_up, col_down, row_left, row_right);
	// printf("%d ", result);
    // free(grid);
    // // free(first_column);
	
	
	//  Test all combined
    int rows = 4;
    int cols = 4;

    // Allocate memory for the 4x4 grid
    int **grid = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int *)malloc(cols * sizeof(int));
    }

    // Arrays for col_up, col_down, row_left, and row_right with example values
    int col_up[4] = {4, 3, 2, 1};
    int col_down[4] = {1, 2, 2, 2};
    int row_left[4] = {4, 3, 2, 1};
    int row_right[4] = {1, 2, 2, 2};
	
	int	row_used_digits[4] = {0,0,0,0};
	int	col_used_digits[4] = {0,0,0,0};

    // Call the recursive function to generate and check all 4x4 grids
    generate_and_check_grids(grid, 0, 0, rows, col_up, col_down, row_left, row_right, row_used_digits, col_used_digits);

    // Free the dynamically allocated memory.
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;

}