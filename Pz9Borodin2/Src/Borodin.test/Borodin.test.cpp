
#include "stdafx.h"
#include "gtest\gtest.h"
#include "Address.hpp"
using namespace std;
TEST(Address1, setter_getter)
{
	Address adres;
	adres.setCountry("Russia");
	adres.setName("Daniil");
	adres.setTown("MSK");
	adres.setStreet("Michura");

	EXPECT_STREQ(adres.getCountry(), "Russia");
	EXPECT_STREQ(adres.getName(), "Daniil");
	EXPECT_STREQ(adres.getNumber(), "");
	EXPECT_STREQ(adres.getTown(), "MSK");
	EXPECT_STREQ(adres.getStreet(), "Michura");

}

TEST(Address, getAddress)
{
	Address adres;
	adres.setCountry("Russia");
	adres.setName("Daniil");
	adres.setNumber("15");
	adres.setTown("MSK");
	adres.setStreet("Michura");
	adres.setAddress();

	EXPECT_STREQ(adres.getAddress(), "Russia MSK Michura 15 Daniil");
	adres.setTown("Saratov");
	adres.setAddress();
	EXPECT_STREQ(adres.getAddress(), "Russia Saratov Michura 15 Daniil");

}

TEST(Address, Copy)
{
	Address adres;
	adres.setCountry("Russia");
	adres.setName("Daniil");
	adres.setNumber("15");
	adres.setTown("MSK");
	adres.setStreet("Michura");
	adres.setAddress();

	Address copyAdres(adres);

	EXPECT_STREQ(adres.getAddress(), copyAdres.getAddress());
}

TEST(Address, reoladOperator_1)
{
	Address adres;
	adres.setCountry("Russia");
	adres.setName("Daniil");
	adres.setNumber("15");
	adres.setTown("MSK");
	adres.setStreet("Michura");
	adres.setAddress();

	Address copyAdres;

	copyAdres = adres;

	EXPECT_STREQ(adres.getAddress(), copyAdres.getAddress());
}

TEST(Address, reoladOperator_2)
{
	Address adres;
	adres.setCountry("Russia");
	adres.setName("Daniil");
	adres.setNumber("15");
	adres.setTown("MSK");
	adres.setStreet("Michura");
	adres.setAddress();

	Address copyAdres;
	copyAdres.setCountry("Russia");
	copyAdres.setName("Euroset");
	copyAdres.setNumber("15");
	copyAdres.setTown("MSK");
	copyAdres.setStreet("Jubileinaya");
	copyAdres.setAddress();

	Address adresNew;
	adresNew.setCountry("DogLand");
	adresNew.setName("Schpitz");
	adresNew.setNumber("45a");
	adresNew.setTown("HotDog");
	adresNew.setStreet("Meastreet");
	adresNew.setAddress();


	EXPECT_TRUE(copyAdres == adres);
	EXPECT_FALSE(copyAdres == adresNew);
}

TEST(Address, poisk)
{
	Address adres;

	adres.setCountry("Russia");
	adres.setName("Daniil");
	adres.setNumber("15");
	adres.setTown("MSK");
	adres.setStreet("Michura");
	adres.setAddress();

	Address copyAdres;
	copyAdres.setCountry("Russia");
	copyAdres.setName("Euroset");
	copyAdres.setNumber("15");
	copyAdres.setTown("MSK");
	copyAdres.setStreet("Jubileinaya");
	copyAdres.setAddress();

	Address adresNew;
	adresNew.setCountry("DogLand");
	adresNew.setName("Schpitz");
	adresNew.setNumber("45a");
	adresNew.setTown("HotDog");
	adresNew.setStreet("Meastreet");
	adresNew.setAddress();


	Address mas[3] = { adres,adresNew,copyAdres };
	Address Find;
	Address* result = nullptr;
	int n = 3; 
	result = Find.Find("Country", "Russia", mas, 3,n,CompCountry);


	EXPECT_STREQ(result[0].getAddress(), copyAdres.getAddress());
	EXPECT_STREQ(result[1].getAddress(), adres.getAddress());
	EXPECT_EQ(2, n);
}
int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}