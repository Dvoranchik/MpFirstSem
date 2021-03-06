
#include "stdafx.h"
#include "gtest\gtest.h"
#include "MyFun.h"

TEST(pz2, logar)
{
	EXPECT_EQ(3, nodnorec(-3, 9));
	EXPECT_EQ(3,nodrec(3,9));
	EXPECT_EQ(3, nodnorec(-3, 9));
	EXPECT_EQ(3, nodrec(-3,9));
	EXPECT_EQ(1, nodrec(-53, 55));
	EXPECT_EQ(1, nodnorec(-53, 55));
}

TEST(pz2, nod)
{
	EXPECT_EQ(5, logar(32));
	EXPECT_EQ(-1, logar(31));
	EXPECT_EQ(-1, logar(29));
	EXPECT_EQ(-2, logar(-32));
	EXPECT_EQ(-2, logar(-63));
	EXPECT_EQ(-2, logar(0));
}

TEST(pz2, Teilor)
{
	Teilor(1, 5,1, 0.000001);
	}


using namespace std;
int main(int argc, char*argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
