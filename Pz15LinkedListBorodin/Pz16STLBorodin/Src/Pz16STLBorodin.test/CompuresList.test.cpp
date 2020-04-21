#include "stdafx.h"

TEST(CompList, Constuctor)
{
	Computer comp(4, 4, 4000, 78999, "Sony", "Intel", "33-54-E8-15-D4-Y7");
	Computer comp2(1, 1, 80, 7899, "Sony", "Intel", "4T-R4-EY-65-D7-E7");
	Computer comp3(2, 2, 1000, 12899, "Sumsung", "AMD", "22-R4-67-21-8N-0U");
	std::vector<Computer> store =
	{
		comp,
		comp2,
		comp3
	};

	ComputersList Euroset(store);
	ASSERT_FALSE(Euroset.Empty());
	ASSERT_EQ(Euroset[2], comp3);
	ASSERT_EQ(Euroset[0], comp);
	ASSERT_EQ(Euroset[1], comp2);
}

TEST(CompList, CopyConstuctor)
{
	Computer comp(4, 4, 4000, 78999, "Sony", "Intel", "33-54-E8-15-D4-Y7");
	Computer comp2(1, 1, 80, 7899, "Sony", "Intel", "4T-R4-EY-65-D7-E7");
	Computer comp3(2, 2, 1000, 12899, "Sumsung", "AMD", "22-R4-67-21-8N-0U");
	std::vector<Computer> store =
	{
		comp,
		comp2,
		comp3
	};
	ComputersList Euroset(store);
	ComputersList Eldorado(Euroset);
	
	ASSERT_FALSE(Eldorado.Empty());
	ASSERT_EQ(Eldorado[2], comp3);
	ASSERT_EQ(Eldorado[0], comp);
	ASSERT_EQ(Eldorado[1], comp2);
}

TEST(CompList, TransferConstuctor)
{
	Computer comp(4, 4, 4000, 78999, "Sony", "Intel", "33-54-E8-15-D4-Y7");
	Computer comp2(1, 1, 80, 7899, "Sony", "Intel", "4T-R4-EY-65-D7-E7");
	Computer comp3(2, 2, 1000, 12899, "Sumsung", "AMD", "22-R4-67-21-8N-0U");
	std::vector<Computer> store =
	{
		comp,
		comp2,
		comp3
	};
	ComputersList Euroset(store);
	ComputersList Eldorado(std::move(Euroset));

	ASSERT_FALSE(Eldorado.Empty());
	ASSERT_EQ(Eldorado[2], comp3);
	ASSERT_EQ(Eldorado[0], comp);
	ASSERT_EQ(Eldorado[1], comp2);
}

TEST(CompList, OperatorAssign)
{
	Computer comp(4, 4, 4000, 78999, "Sony", "Intel", "33-54-E8-15-D4-Y7");
	Computer comp2(1, 1, 80, 7899, "Sony", "Intel", "4T-R4-EY-65-D7-E7");
	Computer comp3(2, 2, 1000, 12899, "Sumsung", "AMD", "22-R4-67-21-8N-0U");
	std::vector<Computer> store =
	{
		comp,
		comp2,
		comp3
	};
	ComputersList Euroset(store);
	ComputersList Eldorado=Euroset;

	ASSERT_FALSE(Eldorado.Empty());
	ASSERT_EQ(Eldorado[2], comp3);
	ASSERT_EQ(Eldorado[0], comp);
	ASSERT_EQ(Eldorado[1], comp2);
}

TEST(CompList, OperatorCompare)
{
	Computer comp(4, 4, 4000, 78999, "Sony", "Intel", "33-54-E8-15-D4-Y7");
	Computer comp2(1, 1, 80, 7899, "Sony", "Intel", "4T-R4-EY-65-D7-E7");
	Computer comp3(2, 2, 1000, 12899, "Sumsung", "AMD", "22-R4-67-21-8N-0U");
	Computer comp4(1, 2, 1000, 4999, "Huawey", "AMD", "Y2-T4-M7-2L-8L-DU");
	std::vector<Computer> store =
	{
		comp,
		comp2,
		comp3
	};
	std::vector<Computer> storemax =
	{
		comp,
		comp2,
		comp3,
		comp4
	};
	ComputersList Euroset(store);
	ComputersList Eldorado (store);
	ComputersList AliExpress(storemax);
	ASSERT_TRUE(Euroset == Eldorado);
	ASSERT_FALSE(Euroset==AliExpress);
}

TEST(CompList, Delete)
{
	Computer comp(4, 4, 4000, 78999, "Sony", "Intel", "33-54-E8-15-D4-Y7");
	Computer comp2(1, 1, 80, 7899, "Sony", "Intel", "4T-R4-EY-65-D7-E7");
	Computer comp3(2, 2, 1000, 12899, "Sumsung", "AMD", "22-R4-67-21-8N-0U");
	std::vector<Computer> store =
	{
		comp,
		comp2,
		comp3
	};

	ComputersList Euroset(store);
	ASSERT_EQ(Euroset.Size(), 3);
	Euroset.Delete_back();
	ASSERT_EQ(Euroset.Size(), 2);
	ASSERT_EQ(Euroset.Back(), comp2);
}

TEST(CompList, Replace)
{
	Computer comp(4, 4, 4000, 78999, "Sony", "Intel", "33-54-E8-15-D4-Y7");
	Computer comp2(1, 1, 80, 7899, "Sony", "Intel", "4T-R4-EY-65-D7-E7");
	Computer comp3(2, 2, 1000, 12899, "Sumsung", "AMD", "22-R4-67-21-8N-0U");
	std::vector<Computer> store =
	{
		comp,
		comp2,
		comp3
	};

	ComputersList Euroset(store);
	ASSERT_EQ(Euroset[0], comp);
	Euroset.Replace(comp3, 0);
	ASSERT_EQ(Euroset[0], comp3);
}

TEST(CompList, SortBrand)
{
	Computer comp(4, 4, 4000, 78999, "Fail", "Intel", "33-54-E8-15-D4-Y7");
	Computer comp2(1, 1, 80, 7899, "Bad", "Intel", "4T-R4-EY-65-D7-E7");
	Computer comp3(2, 2, 1000, 12899, "Carry", "AMD", "22-R4-67-21-8N-0U");
	Computer comp4(1, 2, 1000, 4999, "Devil", "AMD", "Y2-T4-M7-2L-8L-DU");
	std::vector<Computer> store =
	{
		comp,
		comp2,
		comp3,
		comp4
	};
	ComputersList Euroset(store);
	Euroset.SortCompBrand();

	ASSERT_EQ(Euroset[0], comp2);
	ASSERT_EQ(Euroset[1], comp3);
	ASSERT_EQ(Euroset[2], comp4);
	ASSERT_EQ(Euroset[3], comp);
}

TEST(CompList, SortHardCapacity)
{
	Computer comp(4, 4, 4000, 78999, "Fail", "Intel", "33-54-E8-15-D4-Y7");
	Computer comp2(1, 1, 80, 7899, "Bad", "Intel", "4T-R4-EY-65-D7-E7");
	Computer comp3(2, 2, 1000, 12899, "Carry", "AMD", "22-R4-67-21-8N-0U");
	Computer comp4(1, 2, 1000, 4999, "Devil", "AMD", "Y2-T4-M7-2L-8L-DU");
	std::vector<Computer> store =
	{
		comp,
		comp2,
		comp3,
		comp4
	};
	ComputersList Euroset(store);
	Euroset.SortCompBrand();

	ASSERT_EQ(Euroset[0], comp2);
	ASSERT_EQ(Euroset[1], comp3);
	ASSERT_EQ(Euroset[2], comp4);
	ASSERT_EQ(Euroset[3], comp);
}

TEST(CompList, CpuBrand)
{
	Computer comp(4, 4, 4000, 78999, "Fail", "BIntel", "33-54-E8-15-D4-Y7");
	Computer comp2(1, 1, 80, 7899, "Bad", "AIntel", "4T-R4-EY-65-D7-E7");
	Computer comp3(2, 2, 1000, 12899, "Carry", "AMD", "22-R4-67-21-8N-0U");
	Computer comp4(1, 2, 1000, 4999, "Devil", "AMD", "Y2-T4-M7-2L-8L-DU");
	std::vector<Computer> store =
	{
		comp,
		comp2,
		comp3,
		comp4
	};
	ComputersList Euroset(store);
	Euroset.SortCPUBrand();

	ASSERT_EQ(Euroset[0], comp2);
	ASSERT_EQ(Euroset[1], comp3);
	ASSERT_EQ(Euroset[2], comp4);
	ASSERT_EQ(Euroset[3], comp);
}

TEST(CompList, SortCpuFrequency)
{
	Computer comp(4, 4, 4000, 78999, "Fail", "BIntel", "33-54-E8-15-D4-Y7");
	Computer comp2(1, 1, 80, 7899, "Bad", "AIntel", "4T-R4-EY-65-D7-E7");
	Computer comp3(2, 2, 1000, 12899, "Carry", "AMD", "22-R4-67-21-8N-0U");
	Computer comp4(1, 2, 1000, 4999, "Devil", "AMD", "Y2-T4-M7-2L-8L-DU");
	std::vector<Computer> store =
	{
		comp,
		comp2,
		comp3,
		comp4
	};
	ComputersList Euroset(store);
	Euroset.SortCpuFrequency();

	ASSERT_EQ(Euroset[0], comp2);
	ASSERT_EQ(Euroset[1], comp4);
	ASSERT_EQ(Euroset[2], comp3);
	ASSERT_EQ(Euroset[3], comp);
}

TEST(CompList, FindCompanyBrand)
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
	ComputersList Euroset(store);
	std::list<Computer> lst=Euroset.FindCompBrand("Bad");
	auto it = lst.begin();
	ASSERT_EQ(lst.size(), 2);
	ASSERT_EQ(*it, comp2);
	++it;
	ASSERT_EQ(*it, comp4);
}

TEST(CompList, FindCPUBrand)
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
	ComputersList Euroset(store);
	std::list<Computer> lst = Euroset.FindCPUBrand("AMD");
	auto it = lst.begin();
	ASSERT_EQ(lst.size(), 2);
	ASSERT_EQ(*it, comp3);
	++it;
	ASSERT_EQ(*it, comp4);
}

TEST(CompList, FindHardDiskCapacity)
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
	ComputersList Euroset(store);
	std::list<Computer> lst = Euroset.FindHardDiskCapasity(1000);
	auto it = lst.begin();
	ASSERT_EQ(lst.size(), 2);
	ASSERT_EQ(*it, comp3);
	++it;
	ASSERT_EQ(*it, comp4);
}

TEST(CompList, FindRamSize)
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
	ComputersList Euroset(store);
	std::list<Computer> lst = Euroset.FindRamSize(2);
	auto it = lst.begin();
	ASSERT_EQ(lst.size(), 2);
	ASSERT_EQ(*it, comp3);
	++it;
	ASSERT_EQ(*it, comp4);
}