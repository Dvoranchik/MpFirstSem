#include "stdafx.h"

TEST(AbstractFactory, Save)
{
		Time d;
		RegisterLoaders();
		IPair *objects[] = { new Money(50, 44), new Time(8, 30) };
		Save("AbstractFactory", objects, 2);
		std::ifstream fin;
		std::string a, b;
		fin.open("AbstractFactory");
		while (fin.is_open())
		{
			std::getline(fin, a);
			std::getline(fin, b);
			fin.close();   
		}
		ASSERT_EQ(a, "Money 50 44");
		ASSERT_EQ(b, "Time 8 30");
}

TEST(AbstractFactory, Load)
{

	std::vector<IPair *> loadedObjects = Load("AbstractFactory");

	size_t size = loadedObjects.size();
	ASSERT_EQ(2, size);

	ASSERT_EQ(((Money*)loadedObjects[0])->GetRubles(), 50);
	ASSERT_EQ(((Money*)loadedObjects[0])->GetPennies(), 44);

	ASSERT_EQ(((Time*)loadedObjects[1])->GetHours(), 8);
	ASSERT_EQ(((Time*)loadedObjects[1])->GetMinutes(), 30);
}

TEST(AbstractFactory, LoadMyFactory)
{
	RegisterLoaders();
	std::vector<IPair *> loadedObjects = Load("MyFactory");

	size_t size = loadedObjects.size();
	ASSERT_EQ(2, size);

	ASSERT_EQ(((Money*)loadedObjects[0])->GetRubles(), 33);
	ASSERT_EQ(((Money*)loadedObjects[0])->GetPennies(), 22);

	ASSERT_EQ(((Time*)loadedObjects[1])->GetHours(), 6);
	ASSERT_EQ(((Time*)loadedObjects[1])->GetMinutes(), 40);
}

TEST(AbstractFactory, Throws)
{
	RegisterLoaders();
	Money d(33, 66);
	ASSERT_THROW(std::vector<IPair *> loadedObjects = Load("Boney"), std::runtime_error);
}
