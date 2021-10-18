#include "pch.h"


#include "pch.h"
#include "C:\Users\Vulki\Desktop\Lab3oop\Libfor3lab\Number.h"

using namespace Prog3;

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


TEST(Constructor, EmptyConstr) // Checking setter by long and by char
{
	Number num1;
	ASSERT_STRNE("0", num1.GetChar());
}

TEST(Constructor, Setters) // Checking setter by long and by char
{
	Number num1;
	ASSERT_ANY_THROW(num1.SetByLong(1234567890));
	ASSERT_ANY_THROW(num1.SetByLong(-123456789));
	ASSERT_ANY_THROW(num1.SetByChar("asd"));
	ASSERT_ANY_THROW(num1.SetByChar("-asd"));
	ASSERT_ANY_THROW(num1.SetByChar("1112a11"));
	ASSERT_ANY_THROW(num1.SetByChar("1112a11111asdasa"));
	ASSERT_ANY_THROW(num1.SetByChar("b11"));
	ASSERT_ANY_THROW(num1.SetByChar("11d"));
	ASSERT_ANY_THROW(num1.SetByChar("-1a1"));
	ASSERT_ANY_THROW(num1.SetByChar("-11a"));
	ASSERT_ANY_THROW(num1.SetByChar("-a11"));
}


TEST(Constructor, Getter) // Checking getter and good setters
{
	Number num1;
	num1.SetByLong(12345);
	ASSERT_STREQ("000000011000000111001", num1.GetChar());
	num1.SetByChar("12345");
	ASSERT_STREQ("000000011000000111001", num1.GetChar());
	num1.SetByLong(-12345);
	ASSERT_STREQ("100000011000000111001", num1.GetChar());
	num1.SetByChar("-12345");
	ASSERT_STREQ("100000011000000111001", num1.GetChar());
}




TEST(Constructor, Sum) // Checking sum of two digits
{
	Number num1;
	num1.SetByLong(12);
	ASSERT_EQ(24, num1.Addition(12));
	ASSERT_EQ(0, num1.Addition(-12));
	ASSERT_EQ(26, num1.Addition(14));
	ASSERT_EQ(134, num1.Addition(122));
	ASSERT_EQ(7, num1.Addition(-5));
}



TEST(Constructor, Multiply) // Checking multiplier
{
	Number num1;
	num1.SetByLong(12);
	ASSERT_EQ(120, num1.Multiplication());
	num1.SetByLong(0);
	ASSERT_EQ(0, num1.Multiplication());
	num1.SetByLong(20);
	ASSERT_EQ(200, num1.Multiplication());
	num1.SetByLong(-20);
	ASSERT_EQ(-200, num1.Multiplication());
}


TEST(Constructor, OverLoadTest) // Checking overload +
{
	Number num1,num2;
	int res;
	num1.SetByLong(0);
	num2.SetByLong(15);
	res = num1 + num2;
	ASSERT_EQ(15, res);
	num1.SetByLong(-20);
	res = num1 + num2;
	ASSERT_EQ(-5, res);
	num1.SetByLong(15);
	res = num1 + num2;
	ASSERT_EQ(30, res);
	num1.SetByLong(454);
	res = num1 + num2;
	ASSERT_EQ(454+15, res);
}