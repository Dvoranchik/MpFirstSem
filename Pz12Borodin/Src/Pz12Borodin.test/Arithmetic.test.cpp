#include "stdafx.h"
TEST(PostfixNotation, PolishNotation)
{
	PostfixNotation t;
	std::string arr = "((6/2)*A+(8-5))/(E)";
	ASSERT_EQ(t.PolishNotation(arr),"62/A*85-+E/");
}

TEST(PostfixNotation, Multy)
{
	PostfixNotation t;
	std::string arr = "(5*4)/(E)";
	ASSERT_EQ(t.Result(arr), "5*4/E");
}

TEST(PostfixNotation, Result)
{
	PostfixNotation t;
	std::string arr = "(5+4)/(E)";
	ASSERT_EQ(t.Result(arr),"(5+4)/E");
}

TEST(PostfixNotation, PolishNotationTwoBrakets)
{
	PostfixNotation t;
	std::string arr = "((5+8)*(A+9))/2";
	
	ASSERT_EQ(t.PolishNotation(arr), "58+A9+*2/");
}

TEST(PostfixNotation, DePolishNotationTwoBraketsLowPriority)
{
	PostfixNotation t;
	std::string arr = "58*A9*+";
	ASSERT_EQ(t.DenotizationPolish(arr), "5*8+A*9");
}


TEST(PostfixNotation,SuperTest)
{
	PostfixNotation t;
	std::string arr = "58*A9++4/A/";
	ASSERT_EQ(t.DenotizationPolish(arr), "(5*8+A+9)/4/A");
}

TEST(PostfixNotation, DePolishNotationTwoBraketsHightPriority)
{
	PostfixNotation t;
	std::string arr = "58+A9+*";
	t.DenotizationPolish(arr);
	ASSERT_EQ(t.DenotizationPolish(arr), "(5+8)*(A+9)");
}

TEST(PostfixNotation, DePolishNotation)
{
	PostfixNotation t;
	std::string arr = "62/A*85-+E/";
	ASSERT_EQ(t.DenotizationPolish(arr), "(6/2*A+8-5)/E");
}

TEST(PostfixNotation, DePolishNotationShort)
{
	PostfixNotation t;
	std::string arr = "56+E/";
	ASSERT_EQ(t.DenotizationPolish(arr), "(5+6)/E");
}

TEST(PostfixNotation, DePolishNotationTwoSymbols)
{
	PostfixNotation t;
	std::string arr = "56+";
	ASSERT_EQ(t.DenotizationPolish(arr), "5+6");
}

TEST(PostfixNotation, DePolishNotationMedium)
{
	PostfixNotation t;
	std::string arr = "45/6+T-";
	ASSERT_EQ(t.DenotizationPolish(arr), "4/5+6-T");
}

TEST(PostfixNotation, DePolishNotationTwoDivision)
{
	PostfixNotation t;
	std::string arr = "45/6+T-8+4/";
	ASSERT_EQ(t.DenotizationPolish(arr), "(4/5+6-T+8)/4");
}

TEST(PostfixNotation, DePolishNotationALotTheSame)
{
	PostfixNotation t;
	std::string arr = "45/5/6/7/";
	ASSERT_EQ(t.DenotizationPolish(arr), "4/5/5/6/7");
}

TEST(PostfixNotation, DePolishNotationALotBrakets)
{
	PostfixNotation t;
	std::string arr = "45+5/6+7/";
	ASSERT_EQ(t.DenotizationPolish(arr), "((4+5)/5+6)/7");
}

TEST(PostfixNotation, ResultSmallData)
{
	PostfixNotation t;
	std::string arr = "((((4+9)*5)-3)+a)/(T)";
	ASSERT_EQ(t.Result(arr), "((4+9)*5-3+a)/T");
}

TEST(ZhelTEsts, ManyWordsSamePriority)
{
	PostfixNotation t;
	std::string arr = "(((d+a)*c / (b * c)))";
	ASSERT_EQ(t.PolishNotation(arr), "da+c*bc*/");
	ASSERT_EQ(t.DenotizationPolish("da+c*bc*/"), "((d+a)*c)/(b*c)");
}

TEST(ZhelTEsts, ManyWordsDifferentPrioirity)
{
	PostfixNotation t;
	std::string arr = "(((d+a)*c / (b + c)))";
	ASSERT_EQ(t.PolishNotation(arr), "da+c*bc+/");
	ASSERT_EQ(t.DenotizationPolish("da+c*bc+/"), "((d+a)*c)/(b+c)");
}

TEST(ZhelTEsts, LeftMarkLowPriority)
{
	PostfixNotation t;
	std::string arr = "(C/(d+a))";
	ASSERT_EQ(t.Result(arr), "C/(d+a)");
}

TEST(ZhelTEsts, LeftMarkSamePriority)
{
	PostfixNotation t;
	std::string arr = "(a / (b * c))";
	ASSERT_EQ(t.Result(arr), "a/(b*c)");
}

TEST(ZhelTEsts, ALotLeftMarks2)
{
	PostfixNotation t;
	std::string arr = "(a/(((a)))+((c)))/((b+c))";
	ASSERT_EQ(t.Result(arr), "(a/a+c)/(b+c)");
}

TEST(ZhelTEsts, ALotLeftMarks3773)
{
	PostfixNotation t;
	std::string arr = "a/(b/c)";
	std::cout << t.PolishNotation(arr) << std::endl;
	t.Result(arr);
	ASSERT_EQ(t.Result(arr), "a/(b/c)");
}

TEST(ZhelTEsts, ALotLeftMarks22)
{
	PostfixNotation t;
	std::string arr = "((a/d)/(b/c))";
	t.Result(arr);
	ASSERT_EQ(t.Result(arr), "(a/d)/(b/c)");
}

TEST(ZhelTEsts, ALotLeftMarks112)
{
	PostfixNotation t;
	std::string arr = "((a)/(a+b))";
	t.Result(arr);
	ASSERT_EQ(t.Result(arr), "a/(a+b)");
}

TEST(ZhelTEsts, ALotLeftMarksLast)
{
	PostfixNotation t;
	std::string arr = "()(a-(a/b))";
	t.Result(arr);
	ASSERT_EQ(t.Result(arr), "a-(a/b)");
}