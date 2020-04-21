#include "stdafx.h"
#include "Pz14MazeBorodin.h"
TEST(Maze, OpenLabirint)
{
	std::string test = "RRRDDDDDDRRUURRUUUURDRDDDDDDDDRR";
	ASSERT_EQ(MazeWay("MazeOpen.txt"), test);
}

TEST(Maze, CloseLabirint)
{
	std::string test = "";
	ASSERT_EQ(MazeWay("MazeClose.txt"), test);
}

TEST(Maze, SamllMaze)
{
	std::string test = "RRD";
	ASSERT_EQ(MazeWay("SmallMaze.txt"),test);
}

TEST(Maze, WithOutDoor)
{
	std::string test = "";
	ASSERT_EQ(MazeWay("MazeMiddleClose.txt"),test);
}