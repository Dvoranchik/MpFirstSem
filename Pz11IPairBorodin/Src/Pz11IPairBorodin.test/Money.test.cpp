#include "stdafx.h"
TEST(Money,Constructor)
{
	Money dollary(22,54);
	ASSERT_EQ(dollary.GetRubles(), 22);
	ASSERT_EQ(dollary.GetPennies(), 54);
}

TEST(Money, Set)
{
	Money dollary(22, 54);
	dollary.SetMoney(34, 78);
	ASSERT_EQ(dollary.GetRubles(), 34);
	ASSERT_EQ(dollary.GetPennies(), 78);
}

TEST(Money, OperatorAssignments)
{
	Money dollary(22, 54);
	Money ruble(44, 78);
	dollary = ruble;
	ASSERT_EQ(dollary.GetRubles(), 44);
	ASSERT_EQ(dollary.GetPennies(), 78);
}

TEST(Money, Copyrater)
{
	Money dollary(22, 54);
	Money arc(dollary);
	ASSERT_EQ(arc.GetRubles(), 22);
	ASSERT_EQ(arc.GetPennies(), 54);
}

TEST(Money, OperatorMulty)
{
	Money dollary(22, 54);
	Money Ruble(44, 78);
	Money Result = dollary * Ruble;
	ASSERT_EQ(Result.GetRubles(),1010);
	ASSERT_EQ(Result.GetPennies(), 12);
}

TEST(Money, OperatorSum)
{
	Money dollary(22, 54);
	Money Ruble(44, 78);
	Money Result = dollary + Ruble;
	ASSERT_EQ(Result.GetRubles(),67);
	ASSERT_EQ(Result.GetPennies(), 32);
}

TEST(Money, OperatorIn )
{
	Money k(22,77);
	std::ofstream fout("Money");
	fout << k;
	fout.close();
}

TEST(Money, OperatorOut)
{
	Money d(33, 66);
	std::ifstream fin("Money");
	fin >> d;
	fin.close();
	ASSERT_EQ(d.GetPennies(), 77);
	ASSERT_EQ(d.GetRubles(), 22);
}

TEST(Money, ThrowConstructor)
{
	ASSERT_THROW(Money D(23, 111), std::logic_error);
}

TEST(Money, ThrowSetter)
{
	Money A(22, 1);
	ASSERT_THROW(A.SetMoney(22, 1111), std::logic_error);
}