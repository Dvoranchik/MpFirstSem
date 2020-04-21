#include "stdafx.h"

TEST(Computer,Constuctor)
{
	Computer comp(4,4,4000,78999,"Sony","Intel","33-54-E8-15-D4-Y7");
	ASSERT_EQ(comp.GetCode(), "33-54-E8-15-D4-Y7");
	ASSERT_EQ(comp.GetCompBrand(), "Sony");
	ASSERT_EQ(comp.GetCompCost(), 78999);
	ASSERT_EQ(comp.GetCpuFrequency(), 4);
	ASSERT_EQ(comp.GetCpuType(), "Intel");
	ASSERT_EQ(comp.GetRamSize(), 4);
	ASSERT_EQ(comp.GetHardDiskCapasity(), 4000);
}

TEST(Computer, CopyConstuctor)
{
	Computer comp(4, 4, 4000, 78999, "Sony", "Intel", "33-54-E8-15-D4-Y7");
	Computer comp2(comp);
	ASSERT_EQ(comp2.GetCode(), "33-54-E8-15-D4-Y7");
	ASSERT_EQ(comp2.GetCompBrand(), "Sony");
	ASSERT_EQ(comp2.GetCompCost(), 78999);
	ASSERT_EQ(comp2.GetCpuFrequency(), 4);
	ASSERT_EQ(comp2.GetCpuType(), "Intel");
	ASSERT_EQ(comp2.GetRamSize(), 4);
	ASSERT_EQ(comp2.GetHardDiskCapasity(), 4000);
}

TEST(Computer, TransferConstuctor)
{
	Computer comp(4, 4, 4000, 78999, "Sony", "Intel", "33-54-E8-15-D4-Y7");
	Computer comp2(std::move(comp));
	ASSERT_EQ(comp2.GetCode(), "33-54-E8-15-D4-Y7");
	ASSERT_EQ(comp2.GetCompBrand(), "Sony");
	ASSERT_EQ(comp2.GetCompCost(), 78999);
	ASSERT_EQ(comp2.GetCpuFrequency(), 4);
	ASSERT_EQ(comp2.GetCpuType(), "Intel");
	ASSERT_EQ(comp2.GetRamSize(), 4);
	ASSERT_EQ(comp2.GetHardDiskCapasity(), 4000);
}

TEST(Computer, OperatorAssign)
{
	Computer comp(4, 4, 4000, 78999, "Sony", "Intel", "33-54-E8-15-D4-Y7");
	Computer comp2=comp;
	ASSERT_EQ(comp2.GetCode(), "33-54-E8-15-D4-Y7");
	ASSERT_EQ(comp2.GetCompBrand(), "Sony");
	ASSERT_EQ(comp2.GetCompCost(), 78999);
	ASSERT_EQ(comp2.GetCpuFrequency(), 4);
	ASSERT_EQ(comp2.GetCpuType(), "Intel");
	ASSERT_EQ(comp2.GetRamSize(), 4);
	ASSERT_EQ(comp2.GetHardDiskCapasity(), 4000);
}

TEST(Computer, OperatorCompare)
{
	Computer comp(4, 4, 4000, 78999, "Sony", "Intel", "33-54-E8-15-D4-Y7");
	Computer comp2(4, 4, 4000, 78999, "Sony", "Intel", "33-54-E8-15-D4-Y7");
	Computer comp3(2, 2, 1000, 12899, "Sumsung", "AMD", "22-R4-67-21-8N-0U");
	ASSERT_TRUE(comp == comp2);
	ASSERT_FALSE(comp == comp3);
}