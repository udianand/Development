// Sudoku Solver.cpp : Defines the entry point for the console application.
// Provides all the solutions to the sudoko problem.
//

#include "stdafx.h"
#include "Udit_Anand_Assignment2b.h"

int main(int argc, char * const argv[])
{
Sudoku x;
x.read_puzzle(argc, argv);
x.print_puzzle();
x.Solve(0, 0);

return 0;
}


