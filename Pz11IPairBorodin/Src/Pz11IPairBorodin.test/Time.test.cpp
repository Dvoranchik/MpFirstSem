#include "stdafx.h"
TEST(Time, Constructor)
{
	Time first(5, 54);
	ASSERT_EQ(first.GetHours(), 5);
	ASSERT_EQ(first.GetMinutes(), 54);
}

TEST(Time, Set)
{
	Time first(5, 54);
	first.SetTime(22, 48);
	ASSERT_EQ(first.GetHours(), 22);
	ASSERT_EQ(first.GetMinutes(), 48);
}

TEST(Time, OpratorAssignmentsTime)
{
	Time first(5, 54);
	Time second(10, 44);
	first = second;
	ASSERT_EQ(first.GetHours(), 10);
	ASSERT_EQ(first.GetMinutes(), 44);
	
}

TEST(Time, Copyrater)
{
	Time first(5, 54);
	Time arc(first);
	ASSERT_EQ(first.GetHours(), 5);
	ASSERT_EQ(first.GetMinutes(), 54);
}

TEST(Time, OperatorMultyTime)
{
	Time first(5, 54);
	Time second(10, 44);
	Time Result = first * second;
	ASSERT_EQ(Result.GetHours(), 17);
	ASSERT_EQ(Result.GetMinutes(), 36);
}

TEST(Time, OperatorSumTime)
{
	Time first(5, 54);
	Time second(10, 44);
	Time Result = first + second;
	ASSERT_EQ(Result.GetHours(), 16);
	ASSERT_EQ(Result.GetMinutes(), 38);
}

TEST(Time,OperatorIn)
{
	Time k(22, 7);
	std::ofstream fout("Time");
	fout << k;
	fout.close();
}

TEST(Time, OperatorOut)
{
	Time d(20, 56);
	std::ifstream fin("Time");
	fin >> d;
	fin.close();
	ASSERT_EQ(d.GetHours(), 22);
	ASSERT_EQ(d.GetMinutes(), 7);
}

TEST(Time, ThrowConstructor)
{
	ASSERT_THROW(Time D(33, 22), std::logic_error);
}

TEST(Time, ThrowSet)
{
	Time A(5, 6);
	ASSERT_THROW(A.SetTime(44, 77), std::logic_error);
}