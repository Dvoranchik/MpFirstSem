#include "stdafx.h"
int main(int argc, char* argv[])
{
	_wsetlocale(LC_ALL, L"ru-RU");
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

