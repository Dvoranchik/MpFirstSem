#include "stdafx.h"
#include "Let13MazeBorodin.h"

TEST(Maze, Open)
{
	ASSERT_TRUE(MazeWay("MazeOpen.txt"));
}

TEST(Maze, Close)
{
	ASSERT_FALSE(MazeWay("MazeClose.txt"));
}

TEST(Maze, SamllMaze)
{
	ASSERT_TRUE(MazeWay("SmallMaze.txt"));
}

TEST(Maze, WithOutDoor)
{
	ASSERT_FALSE(MazeWay("WithOutDoor.txt"));
}

TEST(Maze, MiddleClose)
{
	ASSERT_FALSE(MazeWay("MazeMiddleClose.txt"));
}