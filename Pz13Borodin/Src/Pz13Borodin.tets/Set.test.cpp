#pragma once
#include "stdafx.h"


TEST(Set, ConstuctorInt)
{
	Set<int> Five(5);
	ASSERT_EQ(Five.Capacity(), 5);
}

TEST(Set, ConstuctorChar)
{
	Set<char> Eight(8);
	ASSERT_EQ(Eight.Capacity(), 8);
	
}

TEST(Set, ConstuctorTriangle)
{
	Set<Triangle> Four(4);
	ASSERT_EQ(Four.Capacity(), 4);
}

TEST(Set, PushInt)
{
	Set<int> Five(5);
	Five.Push(2);
	ASSERT_EQ(Five.Top(), 2);

	ASSERT_EQ(Five.Size(), 1);
	Five.Push(2);
	ASSERT_EQ(Five.Size(), 1);
}

TEST(Set, PushFindInt)
{
	Set<int> Five(5);
	Five.Push(2);
	Five.Push(4);
	Five.Push(5);
	Five.Push(5);
	ASSERT_EQ(Five.Size(), 3);
	Five.Push(4);
	ASSERT_EQ(Five.Size(), 3);
	ASSERT_EQ(Five.Top(), 5);
}

TEST(Set, PushChar)
{
	Set<char> Five(5);
	Five.Push('c');
	ASSERT_EQ(Five.Top(), 'c');

	ASSERT_EQ(Five.Size(), 1);
	Five.Push('c');
	ASSERT_EQ(Five.Size(), 1);
}

TEST(Set, PushFindChar)
{
	Set<char> Five(5);
	Five.Push('a');
	Five.Push('b');
	Five.Push('c');
	Five.Push('b');
	ASSERT_EQ(Five.Size(), 3);
	Five.Push('b');
	ASSERT_EQ(Five.Size(), 3);
	ASSERT_EQ(Five.Top(), 'c');
}

TEST(Set, PushTriangle)
{
	Set<Triangle> Five(5);
	Five.Push(Triangle(2,2));
	Five.Push(Triangle(2, 2));
	ASSERT_EQ(Five.Top(), Triangle(2, 2));

	ASSERT_EQ(Five.Size(), 1);
	Five.Push(Triangle(2, 2));
	ASSERT_EQ(Five.Size(), 1);
}

TEST(Set, PushFindTriangle)
{
	Set<Triangle> Five(5);
	Five.Push(Triangle(2,3));
	Five.Push(Triangle(3,4));
	Five.Push(Triangle(4,5));
	ASSERT_EQ(Five.Size(), 3);
	Five.Push(Triangle(3,4));
	ASSERT_EQ(Five.Size(), 3);
	ASSERT_EQ(Five.Top(), Triangle(4,5));
}

TEST(Set, CopyConstructorInt)
{
	Set<int> Four(4);
	Four.Push(3);
	Four.Push(4);
	Four.Push(2);
	Set<int> Ups(Four);
	
	ASSERT_EQ(Ups.Capacity(), 4);
	ASSERT_EQ(Ups.Size(), 3);

	ASSERT_EQ(Ups.Top(), 2);
	Ups.Delete(2);
	ASSERT_EQ(Ups.Top(), 4);
	Ups.Delete(4);
	ASSERT_EQ(Ups.Top(), 3);
}

TEST(Set, CopyConstructorChar)
{
	Set<int> Four(3);
	Four.Push('c');
	Four.Push('v');
	Four.Push('a');
	Set<int> Ups(Four);

	ASSERT_EQ(Ups.Capacity(), 3);
	ASSERT_EQ(Ups.Size(), 3);

	ASSERT_EQ(Ups.Top(), 'a');
	Ups.Delete('a');
	ASSERT_EQ(Ups.Top(), 'v');
	Ups.Delete('c');
	ASSERT_EQ(Ups.Top(), 'v');
}

TEST(Set, CopyConstructorTriangle)
{
	Set<Triangle> Five(5);
	Five.Push(Triangle(2, 3));
	Five.Push(Triangle(3, 4));
	Five.Push(Triangle(4, 5));
	Set<Triangle> Ups(Five);

	ASSERT_EQ(Ups.Capacity(), 5);
	ASSERT_EQ(Ups.Size(), 3);

	ASSERT_EQ(Ups.Top(), Triangle(4, 5));
	Ups.Delete(Triangle(4, 5));
	ASSERT_EQ(Ups.Top(), Triangle(3, 4));
	Ups.Delete(Triangle(3, 4));
	ASSERT_EQ(Ups.Top(), Triangle(2, 3));
}

TEST(Set, DeleteInt)
{
	Set<int> Four(4);
	Four.Push(3);
	Four.Push(4);
	Four.Push(2);
	ASSERT_EQ(Four.Size(), 3);
	Four.Delete(4);
	ASSERT_EQ(Four.Size(), 2);
	ASSERT_EQ(Four.Top(), 2);
	Four.Delete(2);
	ASSERT_EQ(Four.Top(), 3);
}

TEST(Set, DeleteTriangle)
{
	Set<Triangle> Four(4);
	Four.Push(Triangle(1,3));
	Four.Push(Triangle(4,3));
	Four.Push(Triangle(2,3));
	Four.Push(Triangle(1,7));
	ASSERT_EQ(Four.Size(), 4);
	Four.Delete(Triangle(2, 3));
	ASSERT_EQ(Four.Size(), 3);
	ASSERT_EQ(Four.Top(), Triangle(1, 7));
	Four.Delete(Triangle(1, 7));
	ASSERT_EQ(Four.Top(), Triangle(4, 3));
}

TEST(Set, DeleteThrow)
{
	Set<int> Four(4);
	ASSERT_THROW(Four.Delete(3), std::underflow_error);
	Four.Push(2);
	ASSERT_THROW(Four.Delete(3),std::domain_error);
}

TEST(Find, CriterionInt)
{
	Set<int> Four(4);
	Four.Push(4);
	Four.Push(5);
	Four.Push(2);
	Four.Push(7);
	ASSERT_EQ(Four.FindCriterion(5, Volume()),5);
}

TEST(Find, CriterionDouble)
{
	Set<double> Four(4);
	Four.Push(-4.1);
	Four.Push(-5.4);
	Four.Push(2.6);
	Four.Push(-7.9);
	ASSERT_EQ(Four.FindCriterion(5.4, Volume()), -5.4);
}

TEST(Find, CriterionTriangle)
{
	Set<Triangle> Four(4);
	Four.Push(Triangle(4, 3));
	Four.Push(Triangle(6, 3));
	Four.Push(Triangle(7, 3));
	Four.Push(Triangle(5, 3));
	ASSERT_EQ(Four.FindCriterion(18, Volume()), Triangle(6, 3));
}

TEST(FindCriterion, Throws)
{
	Set<double> Four(4);
	Four.Push(-4.1);
	Four.Push(-5.4);
	Four.Push(2.6);
	Four.Push(-7.9);
	ASSERT_THROW(Four.FindCriterion(5.5, Volume()), std::domain_error);
}

TEST(Set, OperatorAssignmentInt)
{
	Set<int> Four(4);
	Four.Push(3);
	Four.Push(4);
	Four.Push(2);
	Set<int> Ups(5);
	Ups = Four;

	ASSERT_EQ(Ups.Capacity(), 4);
	ASSERT_EQ(Ups.Size(), 3);

	ASSERT_EQ(Ups.Top(), 2);
	Ups.Delete(2);
	ASSERT_EQ(Ups.Top(), 4);
	Ups.Delete(4);
	ASSERT_EQ(Ups.Top(), 3);
}

TEST(Set, OperatorAssignmentChar)
{
	Set<int> Four(3);
	Four.Push('c');
	Four.Push('v');
	Four.Push('a');
	Set<int> Ups(3);
	Ups = Four;
	ASSERT_EQ(Ups.Capacity(), 3);
	ASSERT_EQ(Ups.Size(), 3);

	ASSERT_EQ(Ups.Top(), 'a');
	Ups.Delete('a');
	ASSERT_EQ(Ups.Top(), 'v');
	Ups.Delete('c');
	ASSERT_EQ(Ups.Top(), 'v');
}

TEST(Set, OperatorAssignmentTriangle)
{
	Set<Triangle> Five(5);
	Five.Push(Triangle(2, 3));
	Five.Push(Triangle(3, 4));
	Five.Push(Triangle(4, 5));
	Set<Triangle> Ups(8);
	Ups = Five;

	ASSERT_EQ(Ups.Capacity(), 5);
	ASSERT_EQ(Ups.Size(), 3);

	ASSERT_EQ(Ups.Top(), Triangle(4, 5));
	Ups.Delete(Triangle(4, 5));
	ASSERT_EQ(Ups.Top(), Triangle(3, 4));
	Ups.Delete(Triangle(3, 4));
	ASSERT_EQ(Ups.Top(), Triangle(2, 3));
}

TEST(Set, OperatorAssignmentSelf)
{
	Set<Triangle> Five(5);
	Five.Push(Triangle(2, 3));
	Five.Push(Triangle(3, 4));
	Five.Push(Triangle(4, 5));
	Five = Five;
	ASSERT_EQ(Five.Capacity(), 5);
	ASSERT_EQ(Five.Top(), Triangle(4, 5));
	Five.Delete(Triangle(4, 5));
	ASSERT_EQ(Five.Top(), Triangle(3, 4));
	Five.Delete(Triangle(3, 4));
	ASSERT_EQ(Five.Top(), Triangle(2, 3));
}

TEST(Set, OperatorSumInt)
{
	Set<int> Four(4);
	Four.Push(3);
	Four.Push(4);
	Four.Push(2);
	Set<int> Five(4);
	Five.Push(3);
	Five.Push(4);
	Five.Push(2);
	Five.Push(5);
	Set<int> Six = Four + Five;
	ASSERT_EQ(Six.Capacity(), 7);
	ASSERT_EQ(Six[0], 3);
	ASSERT_EQ(Six[1], 4);
	ASSERT_EQ(Six[2], 2);
	ASSERT_EQ(Six[3], 5);
}

TEST(Set, OperatorSumChar)
{
	Set<char> Four(4);
	Four.Push('c');
	Four.Push('d');
	Four.Push('a');
	Set<char> Five(4);
	Five.Push('v');
	Five.Push('b');
	Five.Push('t');
	Five.Push('q');
	Set<char> Six = Four + Five;
	ASSERT_EQ(Six.Capacity(), 7);
	ASSERT_EQ(Six[0], 'c');
	ASSERT_EQ(Six[1], 'd');
	ASSERT_EQ(Six[2], 'a');
	ASSERT_EQ(Six[3], 'v');
	ASSERT_EQ(Six[4], 'b');
	ASSERT_EQ(Six[5], 't');
	ASSERT_EQ(Six[6], 'q');
}

TEST(Set, OperatorSumTriangle)
{
	Set<Triangle> Four(4);
	Four.Push(Triangle(1, 3));
	Four.Push(Triangle(2, 3));
	Four.Push(Triangle(3, 3));
	Set<Triangle> Five(4);
	Five.Push(Triangle(1, 3));
	Five.Push(Triangle(4, 3));
	Five.Push(Triangle(5, 2));
	Five.Push(Triangle(6, 5));
	Set<Triangle> Six = Four + Five;
	ASSERT_EQ(Six.Capacity(), 7);
	ASSERT_EQ(Six[0], Triangle(1, 3));
	ASSERT_EQ(Six[1], Triangle(2, 3));
	ASSERT_EQ(Six[2], Triangle(3, 3));
	ASSERT_EQ(Six[3], Triangle(4, 3));
	ASSERT_EQ(Six[4], Triangle(5, 2));
	ASSERT_EQ(Six[5], Triangle(6, 5));
}

TEST(Set, OperaorMultyInt)
{
	Set<int> Four(4);
	Four.Push(3);
	Four.Push(4);
	Four.Push(2);
	Set<int> Five(4);
	Five.Push(3);
	Five.Push(4);
	Five.Push(2);
	Five.Push(5);
	Set<int> Six = Four * Five;
	ASSERT_EQ(Six.Capacity(), 3);
	ASSERT_EQ(Six[0], 3);
	ASSERT_EQ(Six[1], 4);
	ASSERT_EQ(Six[2], 2);
}

TEST(Set, OperatorMultyChar)
{
	Set<char> Four(4);
	Four.Push('c');
	Four.Push('d');
	Four.Push('a');
	Set<char> Five(4);
	Five.Push('v');
	Five.Push('b');
	Five.Push('t');
	Five.Push('q');
	Set<char> Six = Four * Five;
	ASSERT_EQ(Six.Capacity(), 3);
	ASSERT_EQ(Six.Size(), 0);

}

TEST(Set, OperatorMultyTriangle)
{
	Set<Triangle> Four(4);
	Four.Push(Triangle(1, 3));
	Four.Push(Triangle(2, 3));
	Four.Push(Triangle(3, 3));
	Set<Triangle> Five(4);
	Five.Push(Triangle(1, 3));
	Five.Push(Triangle(4, 3));
	Five.Push(Triangle(5, 2));
	Five.Push(Triangle(6, 5));
	Set<Triangle> Six = Four * Five;
	ASSERT_EQ(Six.Capacity(), 3);
	ASSERT_EQ(Six.Size(), 1);

	ASSERT_EQ(Six[0], Triangle(1, 3));
}

TEST(Set, OperaorDifferenceInt)
{
	Set<int> Four(4);
	Four.Push(3);
	Four.Push(4);
	Four.Push(2);
	Four.Push(1);
	Set<int> Five(4);
	Five.Push(3);
	Five.Push(4);
	Five.Push(2);
	Five.Push(5);
	Set<int> Six = Four - Five;
	ASSERT_EQ(Six.Capacity(), 4);
	ASSERT_EQ(Six[0], 1);
}

TEST(Set, OperatorDifferenceChar)
{
	Set<char> Four(4);
	Four.Push('c');
	Four.Push('d');
	Four.Push('a');
	Set<char> Five(4);
	Five.Push('v');
	Five.Push('b');
	Five.Push('t');
	Five.Push('q');
	Set<char> Six = Four - Five;
	ASSERT_EQ(Six.Capacity(), 4);
	ASSERT_EQ(Six.Size(), 3);
	ASSERT_EQ(Six[0], 'c');
	ASSERT_EQ(Six[1], 'd');
	ASSERT_EQ(Six[2], 'a');
}

TEST(Set, OperatorDifferenceTriangle)
{
	Set<Triangle> Four(4);
	Four.Push(Triangle(1, 3));
	Four.Push(Triangle(2, 3));
	Four.Push(Triangle(3, 3));
	Set<Triangle> Five(4);
	Five.Push(Triangle(1, 3));
	Five.Push(Triangle(4, 3));
	Five.Push(Triangle(5, 2));
	Five.Push(Triangle(6, 5));
	Set<Triangle> Six = Four - Five;
	ASSERT_EQ(Six.Capacity(), 4);
	ASSERT_EQ(Six.Size(), 2);

	ASSERT_EQ(Six.Top(), Triangle(2, 3));
	ASSERT_EQ(Six[0], Triangle(3, 3));
}

TEST(Set, OperatorOstreamInt)
{
	Set<int> Four(4);
	Four.Push(2);
	Four.Push(3);
	std::ofstream fileout("SetInt.txt");
	fileout << Four;
	fileout.close();
}

TEST(Set, OperatorOstreamChar)
{
	Set<char> Four(4);
	Four.Push('c');
	Four.Push('d');
	Four.Push('a');
	std::ofstream fileout("SetChar.txt");
	fileout << Four;
	fileout.close();
}

TEST(Set, OperatorOstreamTriangle)
{
	Set<Triangle> Four(4);
	Four.Push(Triangle(1, 3));
	Four.Push(Triangle(2, 2));
	Four.Push(Triangle(5, 6));
	std::ofstream fileout("SetTriangle.txt");
	fileout << Four;
	fileout.close();
}
