
#include "stdafx.h"
#include "gtest\gtest.h"
#include "MyF.h"
TEST(WriteText, ex1)
{
	Author Karamazov{"The_Brothers_Karamazov",1912,"Lev_Tolstoy" };
	EXPECT_TRUE(WriteTextAuthor("Struct.txt", Karamazov));
}
TEST(ReadText, ex1)
{
	Author Karamazov{ "The_Brothers_Karamazov",1912,"Lev_Tolstoy" };
	EXPECT_TRUE(WriteTextAuthor("Struct.txt", Karamazov));
	Author Karamazov2{ };
	EXPECT_TRUE(ReadTextAuthor("Struct.txt", Karamazov2));
	EXPECT_STREQ(Karamazov.Title, Karamazov2.Title);
	EXPECT_EQ(Karamazov.Publishyear, Karamazov2.Publishyear);
	EXPECT_STREQ(Karamazov.Autor, Karamazov2.Autor);
}
TEST(WriteBinaryText, ex1)
{
	Author Karamazov{"The_Brothers_Karamazov",1912,"Lev_Tolstoy" };
	EXPECT_TRUE(WriteBinaryAuthor("Struct.bin", Karamazov));
}
TEST(ReadTextBinary, ex1)
{
	Author Karamazov{ "The_Brothers_Karamazov",1912,"Lev_Tolstoy" };
	EXPECT_TRUE(WriteBinaryAuthor("Struct.bin", Karamazov));
	Author Karamazov2{};
	EXPECT_TRUE(ReadBinaryAuthor("Struct.bin", Karamazov2));
	EXPECT_STREQ(Karamazov.Title, Karamazov2.Title);
	EXPECT_EQ(Karamazov.Publishyear, Karamazov2.Publishyear);
	EXPECT_STREQ(Karamazov.Autor, Karamazov2.Autor);
}
int main(int argc, char* argv[])

{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}

