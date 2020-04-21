#include "stdafx.h"

TEST(Task,textNorm)
{
	setlocale(LC_ALL,"ru");
	MaxSubStr res("text1.txt", "text2.txt");
	std::cout<<res.FindSubStr()<<std::endl;
	std::string resul =" нормально ";
	ASSERT_EQ(res.FindSubStr(), resul);
}
//
//TEST(schb, sdi)
//{
//	setlocale(LC_ALL, "ru");
//	MaxSubStr res("Task18_1.txt", "Task18_2.txt");
//	std::cout << res.FindSubStr() << std::endl;
//}

TEST(Test, Text)
{
	setlocale(LC_ALL, "ru");
	MaxSubStr res("Text3.txt", "Text4.txt");
	std::cout << res.FindSubStr() << std::endl;
	std::string resul = "—орићен€";
	ASSERT_EQ(res.FindSubStr(), resul);
}


TEST(Test, textThird)
{
	setlocale(LC_ALL, "ru");
	MaxSubStr res("1.txt", "2.txt");
	std::cout << res.FindSubStr() << std::endl;
	std::string resul = "у ошибки если их 2 ";;
	ASSERT_EQ(res.FindSubStr(), resul);
}

TEST(Test, PartOfBig)
{
	setlocale(LC_ALL, "ru");
	MaxSubStr res("Test1.txt", "Test2.txt");
	std::cout << res.FindSubStr() << std::endl;
	std::string resul = "nnection is in the established state and has      not received a control message for 60 seconds, it SHOULD send a      Echo-Request message. If an Echo-Reply is not received 60 seconds      after the Echo-Request message transmission, the control      connection SHOULD be closed.Hamzeh, et al.               Informational                     [Page 40]RFC";;
	ASSERT_EQ(res.FindSubStr(), resul);
}

