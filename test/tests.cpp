#include "gtest/gtest.h"
#include "Automata.h"


// task1
TEST(lab4,task1_1)
{
	Automata* automat= New Automata();
	automat->coin(50);

    EXPECT_EQ(1, automat->check(25));
}
