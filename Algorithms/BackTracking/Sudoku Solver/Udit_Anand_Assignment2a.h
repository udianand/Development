#pragma once
/*
*  sudoku.h
*  Sudoku
*  Created by Prof. Ramavarapu Sreenivas
*  Inspired by: http://web.eecs.utk.edu/courses/spring2012/cs140/Notes/Sudoku/index.html
*  Reference: http://www.sanfoundry.com/cpp-program-solve-sudoku-problem-backtracking/
*  Reference: http://www.sanfoundry.com/cpp-program-solve-sudoku-problem-backtracking/
*/

#ifndef sudoku
#define sudoku

#include <vector>
#include <fstream>
#include <iostream>

#define ZERO 0
#define START 1
#define BLOCK_SIZE 3
#define END 9


using std::vector;
using namespace std;
class Sudoku
{
	// Private
	int puzzle[9][9];

	// Private member function that checks if the named row is valid
	bool row_valid(int row, int num)
	{
		// write code that checks if "row" is valid
		for (int col = ZERO; col < END; col++)
			if (puzzle[row][col] == num)
				return true;
		return false;
	}

	// Private member function that checks if the named column is valid
	bool col_valid(int col, int num)
	{
		for (int row = ZERO; row < END; row++)
			if (puzzle[row][col] == num)
				return true;
		return false;
	}

	// Private member function that checks if the named 3x3 block is valid
	bool block_valid(int row, int col, int num)
	{
		// check 3 x 3 block validity 
		for (int i = ZERO; i < BLOCK_SIZE; i++)
			for (int j = ZERO; j < BLOCK_SIZE; j++)
				if (puzzle[i + row][j + col] == num)
					return true;
		return false;
	}

public:
	// Public member function that reads the incomplete puzzle
	// we are not doing any checks on the input puzzle -- that is,
	// we are assuming they are indeed valid
	void read_puzzle(int argc, char * const argv[])
	{
		int valueFromFile;

		ifstream inputFile(argv[1]);

		if (inputFile.is_open() && inputFile.good())
		{
			cout << "The file is now open and can be read." << endl;
			
				for (int i = ZERO; i < END; i++)
				{
					for (int j = ZERO; j < END; j++)
					{
						inputFile >> valueFromFile;
						puzzle[i][j] = valueFromFile;
					}
				}
		}

		else
			cout << "Input file does not exist." << endl;
	}

	// Public member function that prints the puzzle when called
public:
	void print_puzzle()
	{
		std::cout << std::endl << "Board Position" << std::endl;
		for (int i = 0; i < END; i++)
		{
			for (int j = 0; j < END; j++)
			{
				// check if we have a legitimate integer between 1 and 9
				if ((puzzle[i][j] >= START) && (puzzle[i][j] <= END))
				{
					// printing initial value of the puzzle with some formatting
					std::cout << puzzle[i][j] << " ";
				}
				else {
					// printing initial value of the puzzle with some formatting
					std::cout << "X ";
				}
			}
			std::cout << std::endl;
		}
	}

private:
	bool findZero(int &row, int &col)
	{
		for (row = ZERO; row < END; row++)
		{
			for (col = ZERO; col < END; col++)
			{
				if (puzzle[row][col] == ZERO)
					return true;
			}
		}
		return false;

	}

public:
	bool Solve(int row, int col)
	{
		
		if (!findZero(row, col))
		{
			print_puzzle();
			return true;
		}
		
		for (int prospective = START; prospective <= END; prospective++)
			{
			
				if (!row_valid(row, prospective) && !col_valid(col, prospective) && !block_valid((row - row % 3), (col - col % 3), prospective))
				{
					puzzle[row][col] = prospective;

					if (Solve(row, col))
						return true;

					puzzle[row][col] = ZERO;

				}

			}

		
		return false;
	}
};

#endif