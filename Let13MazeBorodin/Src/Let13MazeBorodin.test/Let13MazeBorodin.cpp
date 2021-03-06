#include "stdafx.h"
#include "Let13MazeBorodin.h"

bool ExitLabirint(int** labirint, int x, int y,int rows,int colomns)
{
	if (x==rows-2 && y==colomns-2)
		return 1;
	labirint[x][y] = 1;
	if (labirint[x + 1][y] == 0)
		if (ExitLabirint(labirint, x + 1, y, rows, colomns))
			return true;
	if (labirint[x][y + 1] == 0)
		if (ExitLabirint(labirint, x, y + 1, rows, colomns))
			return true;
	if (labirint[x - 1][y] == 0)
		if (ExitLabirint(labirint, x - 1, y, rows, colomns))
			return true;
	if (labirint[x][y - 1] == 0)
		if (ExitLabirint(labirint, x, y - 1, rows, colomns))
			return true;

	return false;
}

bool MazeWay(const char* fileName)
{
	std::ifstream infile(fileName);

	if (!infile.is_open())
		return false;

	int count=0;
	int temp;
	while (!infile.eof())
	{
		infile >> temp;
		++count;
	}

	infile.seekg(0, std::ios::beg);
	infile.clear();

	int countSpace=0;
	char symbol;

	while (!infile.eof())
	{
		infile.get(symbol);
		if (symbol == ' ')
			++countSpace;
		if (symbol == '\n')
			break;
	}
	
	infile.seekg(0, std::ios::beg);
	infile.clear();

	int countRows = count / (countSpace + 1) +1;
	int countColomns = countSpace  ;

	int** maze = new int*[countRows];
	for (size_t i = 0; i < countRows; i++)
	{
		maze[i] = new int[countColomns];
	}
	for (int i = 0; i < countRows; ++i)
	{
		for (int j = 0; j < countColomns; ++j)
		{
			infile >> maze[i][j];
		}
	}
	return ExitLabirint(maze,1,1,countRows,countColomns);

	DeleteMaze(maze,countRows);
}

void DeleteMaze(int** maze,int countofRows)
{
	for (size_t i = 0; i < countofRows; ++i)
	{
		delete[] maze[i];
	}
	delete[] maze;
}