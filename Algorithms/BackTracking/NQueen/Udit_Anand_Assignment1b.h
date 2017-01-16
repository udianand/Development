#pragma once
//
//  hint.h
//  N Queens Problem
//
//  Created by Ramavarapu Sreenivas on 8/23/16.
//
//


#ifndef N_queens
#define N_queens
using namespace std;
class Board
{

	// private data member: size of the board
	int size;

	// pointer-to-pointer initialization of the board
	int **chess_board;

	int count = 0;

	/* private member function:  returns 'false' if
	the (row, col) position is not safe.
	returns 'true' if the (row,col) position is safe.*/
	bool is_this_position_safe(int row, int col)
	{

		int i;
		int j;

		// check column above the element.
		for (i = 0; i < row; i++)
		{
			if (chess_board[i][col])
				return false;
		}

		// check row to the left of the element.
		for (i = 0; i < col; i++)
		{
			if (chess_board[row][i])
				return false;
		}

		// check left upper diagonal.
		for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		{
			if (chess_board[i][j])
				return false;
		}

		// check left lower diagonal.
		for (i = row, j = col; i < size && j < size; i++, j++)
		{
			if (chess_board[i][j])
				return false;
		}

		// check right upper diagonal.
		for (i = row, j = col; i >= 0 && j < size; i--, j++)
		{
			if (chess_board[i][j])
				return false;
		}

		// check right upper diagonal.
		for (i = row, j = col; i < size && j >= 0; i++, j--)
		{
			if (chess_board[i][j])
				return false;
		}

		return true;
	}

	// private member function: Creates a (n x n) chessboard and  initializes the (n x n) chessboard.
	void initialize(int n)
	{
		size = n;

		// Create an array using 2D Dynamic Arrays.
		chess_board = new int*[size];
		for (int i = 0; i < size; i++)
			chess_board[i] = new int[size];

		// Initialize all elements of the array to zero.
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				chess_board[i][j] = 0;
		}

	}

	// private member function: prints the board position
	void print_board()
	{
		std::cout << size << "-Queens Problem Solution #" << count <<std::endl;

		// Print Arrays
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << " " << chess_board[i][j];
			}

			cout << endl;
		}

	}

	// private member function: recursive backtracking
	bool solve(int col)
	{
		/* Increases the number of solutions by count of 1
		and prints the current solution.*/
		if (col >= size)
		{
			count = count + 1;
			print_board();
		}

		/*Checks the Queen's position for each row in the specified column.
		If the position is safe mark the position as safe (= 1).
		Recursively solve for the next Queen by assugning it the
		next column number (col+1). Incase, the recursive solution returns false, backtrack
		by setting the column and row index to 0.

		Try for the next row.
		Incase all fails return false.*/

		for (int i = 0; i < size; i++)
		{
			if (is_this_position_safe(i, col))
			{
				chess_board[i][col] = 1;

				if (solve(col + 1))
				{		
					return true;
				}

				chess_board[i][col] = 0;

			}
		}

		return false;
	}

public:
	// Solves the n-Queens problem by (recursive) backtracking
	void nQueens(int n)
	{
		initialize(n);
		solve(0);

		cout << endl;
		std::cout << count << " Number of solutions to the Queens Problem" << std::endl;
	}
};
#pragma once
#endif
