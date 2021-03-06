
#include "stdafx.h"
#include"gtest\gtest.h"
#include"Fun.h"


TEST(Task4Tests, CountOfWordsInString2)
{
	char str2[] = "fff oodosd Adfffsd, dsd dd FA";
	char* result = Filter_words(str2, 'f', 3);
	ASSERT_STREQ("fff Adfffsd ", Filter_words(str2, 'f', 3));
	delete[] result;
}
TEST(Task4Tests, CountOfWordsInString4)
{
	char str2[] = "ff oodosd Adffsd, dsd dd FA";
	char* result = Filter_words(str2, 'f', 3);
	ASSERT_STREQ("", Filter_words(str2, 'f', 3));
	delete[] result;
}
TEST(Task4Tests, CountOfWordsInString1)
{
	char str1[] = "0d11n 2 3.1hgsdf% 1sdjsd 4  ";
	int *is = String_inst(str1);
	for (int i = 0; i<7; ++i)
		std::cout << is[i] << std::endl;
}
TEST(Task4Tests, CountOfWordsInString3)
{
	char str3[]= "fff oodosd Adsd, dsd dd FA";
	char* result = Uppercase(str3);
	ASSERT_STREQ("Fff Oodosd Adsd, Dsd Dd FA", Uppercase(str3));
	delete[] result;
}

using namespace std;
int main(int argc, char*argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


