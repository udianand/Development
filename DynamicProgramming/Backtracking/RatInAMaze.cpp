/*
 * RatInAMaze.cpp
 *
 *  Created on: May 25, 2016
 *      Author: Udit Anand
 */

#include<stdio.h>

bool solveMaze(int maze[][4]);
bool isSolvable(int maze[4][4]);
bool solveMazeUtil(int maze[4][4], int track[4][4],int x, int y);
bool isSafe();

bool solveMaze(int maze[][4])
{
	if (isSolvable(maze))
		return (true);

	return (false);
	}

bool isSolvable(int maze[4][4])
{
	int track[4][4] = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0,
				0, 0 } };
	solveMazeUtil(maze, track, 0, 0);
	return (false);
	}

bool solveMazeUtil(int maze[4][4], int track[4][4], int x, int y)
{
	if (x == 3 && y == 3)
		return (true);

	if (isSafe())
	{
		if (solveMazeUtil(maze, track, x+1, y) == true)
			return (true);

		if (solveMazeUtil(maze, track, x, y+1) == true)
			return (true);

		track[x][y] = 0;
		return (false);

	}

	return (false);
	}

bool isSafe()
{
	return (false);
	}

// driver program to test above function
int main() {


	int maze[4][4] = { { 1, 0, 0, 0 }, { 1, 1, 0, 1 }, { 0, 1, 0, 0 }, { 1, 1,
			1, 1 } };

	solveMaze(maze);
	return (0);
}

