#include "gtest/gtest.h"
#include "auto.h"

TEST(auto, is_on)
{
	Automata c;
	std::string res = c.getState();
	EXPECT_EQ("Coffee and Co. is on", res);
}
TEST(auto, is_off)
{
	Automata c;
	c.off();
	std::string res = c.getState();
	EXPECT_EQ("Coffee and Co. is off", res);
}
TEST(auto, correct_n)
{
	Automata HSE("HSE", { Drink{"Americano", 50}, Drink{"Espresso", 60}, Drink{"Latte", 80}, Drink{"Hot chocolate", 60}, Drink{"Tea", 30}, Drink{"Water", 10} });
	std::string res = HSE.coin(100);
	res = HSE.choice(2);
	EXPECT_EQ("Espresso is cooking...\nEnjoy your drink!", res);
}
TEST(auto, incorrect_n)
{
	Automata HSE("HSE", { Drink{"Americano", 50}, Drink{"Espresso", 60}, Drink{"Latte", 80}, Drink{"Hot chocolate", 60}, Drink{"Tea", 30}, Drink{"Water", 10} });
	std::string res = HSE.coin(100);
	res = HSE.choice(10);
	EXPECT_EQ("Error!", res);
}
TEST(auto, menu)
{
	Automata c("CheckMachine", { Drink{"Coffee", 10} });
	std::string res = c.getMenu();
	EXPECT_EQ("CheckMachine:\n1. Coffee: 10", res);
}
