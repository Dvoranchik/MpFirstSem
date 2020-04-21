#include "stdafx.h"


TEST(Multy,int)
{
	std::list<int> ls = { 1,4,5,6,7,12 };
	ls.push_back(4);
	ls.push_back(15);
	ls.push_back(8);
	auto it = ls.begin();
	auto it2 = ls.end();
	int k = Multy< std::list<int>::iterator,int>(it, it2);
	ASSERT_EQ(k, 1536);
}

TEST(Multy, char)
{
	char** arr = new char*[3]
	{
		const_cast<char*>("good"),
		const_cast<char*>("job"),
		const_cast<char*>("guys")
	};
	ASSERT_EQ((Multy<char**,std::string>(arr, arr+3)), "goodguys");
}


TEST(Sort,int)
{
	std::vector<int> ls = { 1,4,5,6,7,8 };
	ls.push_back(3);
	ls.push_back(2);
	ls.push_back(9);
	auto it = ls.begin();
	auto it2 = ls.end();
	PredicatsBrand x;
	Sort<std::vector<int>::iterator, int, PredicatsBrand>(it, it2, x);
	int k = 1;
	for (auto i = ls.begin(); i != ls.end(); ++i)
	{
		ASSERT_EQ(*i, k);
		++k;
	}
}

TEST(Find, int)
{
	std::vector<int> ls = { 1,4,5,6,7,8,2,3,2,4,2};
	ls.push_back(3);
	ls.push_back(2);
	ls.push_back(9);
	auto it = ls.begin();
	auto it2 = ls.end();
	FindCriterion x;
	std::list<int> result;
	result = Find<std::vector<int>::iterator, int, int, FindCriterion>(it,it2, x,2);
	auto it3 = result.begin();
	ASSERT_EQ(result.size(), 4);
	ASSERT_EQ(*it3, 2);
	++it3;
	ASSERT_EQ(*it3, 2);
	++it3;
	ASSERT_EQ(*it3, 2);
	++it3;
	ASSERT_EQ(*it3, 2);
	
}

TEST(BinarySearch, int)
{
	std::vector<int> ls = { 1,2,3,4,5,6,7,8 };
	auto it = ls.begin();
	auto it2 = ls.end();
	FindCriterion x;
	PredicatsBrand y;
	int t = BinarySearch<std::vector<int>::iterator, int, int, PredicatsBrand,FindCriterion>(it, it2, 2, y, x);
	ASSERT_EQ(t, 2);
}

TEST(BinarySearch, intLast)
{
	std::vector<int> ls = { 1,2,3,4,5,6,7,8,9 };
	auto it = ls.begin();
	auto it2 = ls.end();
	FindCriterion x;
	PredicatsBrand y;
	int t = BinarySearch<std::vector<int>::iterator, int,int, PredicatsBrand, FindCriterion>(it, it2, 9,y,x);
	ASSERT_EQ(t, 9);
}

TEST(BinarySearch,Throw)
{
	std::vector<char> ls = { 'a','b','c','c','v' };
	ls.push_back('v');
	ls.push_back('n');
	ls.push_back('b');
	auto it = ls.begin();
	auto it2 = ls.end();
	FindCriterion x;
	ASSERT_THROW((BinarySearch<std::vector<char>::iterator,char, char, FindCriterion, FindCriterion>(it, it2, 9, x, x)),std::domain_error);
}

TEST(LinaryFind, int)
{
	std::vector<int> ls = { 1,4,5,6,7,8,2,3,2,4,2 };
	ls.push_back(3);
	ls.push_back(2);
	ls.push_back(9);
	auto it = ls.begin();
	auto it2 = ls.end();
	FindCriterion x;
	ASSERT_EQ((LinaryFind<std::vector<int>::iterator,int, int, FindCriterion>(it, it2, 2, x)), 2);
}

TEST(LinaryFind, Throw)
{
	std::vector<char> ls = { 'a','b','c','c','v' };
	ls.push_back('v');
	ls.push_back('n');
	ls.push_back('b');
	auto it = ls.begin();
	auto it2 = ls.end();
	FindCriterion x;
	ASSERT_THROW((LinaryFind<std::vector<char>::iterator,char, char, FindCriterion>(it, it2, 'x', x)), std::domain_error);
}


TEST(QuantityFind, int)
{
	std::vector<int> ls = { 1,4,2,2,2,2,2,3,2,4,2 };
	ls.push_back(3);
	ls.push_back(2);
	ls.push_back(9);
	auto it = ls.begin();
	auto it2 = ls.end();
	FindCriterion x;
	std::list<int> result;
	result = QuantityFind<std::vector<int>::iterator, int, int, FindCriterion>(it, it2, x, 2,5);
	auto it3 = result.begin();
	ASSERT_EQ(result.size(), 5);
	ASSERT_EQ(*it3, 2);
	++it3;
	ASSERT_EQ(*it3, 2);
	++it3;
	ASSERT_EQ(*it3, 2);
	++it3;
	ASSERT_EQ(*it3, 2);
	++it3;
	ASSERT_EQ(*it3, 2);

}

TEST(QuantityFind, Someoneint)
{
	std::vector<int> ls = { 1,4,2,2,2,2,2,3,2,4,2 };
	ls.push_back(3);
	ls.push_back(2);
	ls.push_back(9);
	auto it = ls.begin();
	auto it2 = ls.end();
	PredicatsBrand x;
	std::list<int> result;
	result = QuantityFind<std::vector<int>::iterator, int, int, PredicatsBrand>(it, it2, x, 2, 5);
	auto it3 = result.begin();
	ASSERT_EQ(result.size(), 5);
	ASSERT_EQ(*it3, 4);
	++it3;
	ASSERT_EQ(*it3, 3);
	++it3;
	ASSERT_EQ(*it3, 4);
	++it3;
	ASSERT_EQ(*it3, 3);
	++it3;
	ASSERT_EQ(*it3, 9);

}

TEST(BinarySearch, Computer)
{
	Computer comp(4, 4, 4000, 78999, "Fail", "BIntel", "33-54-E8-15-D4-Y7");
	Computer comp2(1, 1, 80, 7899, "Bad", "AIntel", "4T-R4-EY-65-D7-E7");
	Computer comp3(2, 2, 1000, 12899, "Carry", "AMD", "22-R4-67-21-8N-0U");
	Computer comp4(1, 2, 1000, 4999, "Bad", "AMD", "Y2-T4-M7-2L-8L-DU");
	std::vector<Computer> store =
	{
		comp,
		comp2,
		comp3,
		comp4
	};
	auto it = store.begin();
	auto it2 = store.end();
	PredicatsFindBrand x;
	PredicatsFindBrand y;
	std::list<Computer> result;
	Computer t = BinarySearch<std::vector<Computer>::iterator, std::string, Computer, PredicatsFindBrand, PredicatsFindBrand>(it, it2,"Bad", x,y);
	ASSERT_EQ(t.GetCompBrand(), "Bad");
}

TEST(LinaryFind, Computer)
{
	Computer comp(4, 4, 4000, 78999, "Fail", "BIntel", "33-54-E8-15-D4-Y7");
	Computer comp2(1, 1, 80, 7899, "Bad", "AIntel", "4T-R4-EY-65-D7-E7");
	Computer comp3(2, 2, 1000, 12899, "Carry", "AMD", "22-R4-67-21-8N-0U");
	Computer comp4(1, 2, 1000, 4999, "Bad", "AMD", "Y2-T4-M7-2L-8L-DU");
	std::vector<Computer> store =
	{
		comp,
		comp2,
		comp3,
		comp4
	};
	auto it = store.begin();
	auto it2 = store.end();
	PredicatsFindBrand x;
	ASSERT_EQ((LinaryFind<std::vector<Computer>::iterator,Computer, std::string, PredicatsFindBrand>(it, it2, "Bad", x)), comp2);
}

TEST(QuantityFind, Computer)
{
	Computer comp(4, 4, 4000, 78999, "Fail", "BIntel", "33-54-E8-15-D4-Y7");
	Computer comp2(1, 1, 80, 7899, "Bad", "AIntel", "4T-R4-EY-65-D7-E7");
	Computer comp3(2, 2, 1000, 12899, "Bad", "AMD", "22-R4-67-21-8N-0U");
	Computer comp4(1, 2, 1000, 4999, "Bad", "AMD", "Y2-T4-M7-2L-8L-DU");
	std::vector<Computer> store =
	{
		comp,
		comp2,
		comp3,
		comp4
	};
	auto it = store.begin();
	auto it2 = store.end();
	PredicatsFindBrand x;
	std::list<Computer> result;
	result = QuantityFind<std::vector<Computer>::iterator, Computer, std::string, PredicatsFindBrand>(it, it2, x, "Bad", 2);
	auto it3 = result.begin();
	ASSERT_EQ(result.size(), 2);
	ASSERT_EQ(*it3, comp2);
	++it3;
	ASSERT_EQ(*it3, comp3);
}