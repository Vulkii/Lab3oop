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

TEST(Constructor, LongConstr) // Checking setter by long and by char
{
	long dig = 555;
	char number[10] = {'5','5','5'};
	Number num1(dig);
	ASSERT_STREQ("000000000001000101011", num1.GetChar());
	dig = -52;
	Number num2(dig);
	ASSERT_STREQ("100000000000000110100", num2.GetChar());
	dig = 55555555555;
	ASSERT_ANY_THROW(Number num3(dig));
	dig = -1234344123;
	ASSERT_ANY_THROW(Number num4(dig));
}

TEST(Constructor, CharConst) // Checking char constructor
{
	char number[10] = { '5','5','5' };
	char negative_num[10] = { '-','5','2' };
	Number num1(number);
	ASSERT_STREQ("000000000001000101011", num1.GetChar());
	Number num2(negative_num);
	ASSERT_STREQ("100000000000000110100", num2.GetChar());
	char overflow[10] = { '1','1','1','1','1','1','1','1','1' };
	ASSERT_ANY_THROW(Number num3(overflow));
	char neg_overflow[10] = { '-','1','1','1','1','1','1','1','1','1'};
	ASSERT_ANY_THROW(Number num4(neg_overflow));
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




TEST(Method, Sum) // Checking sum of two digits
{
	Number num1;
	num1.SetByLong(12);
	ASSERT_EQ(24, num1.Addition(12));
	ASSERT_EQ(0, num1.Addition(-12));
	ASSERT_EQ(26, num1.Addition(14));
	ASSERT_EQ(134, num1.Addition(122));
	ASSERT_EQ(7, num1.Addition(-5));
}



TEST(Method, Multiply) // Checking multiplier
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


TEST(Constructor, OverLoadTest) // Checking overload
{
	Number num1,num2;
	num1.SetByLong(0);
	num2.SetByLong(15);
	Number res = num1 + num2;
	ASSERT_STREQ("000000000000000001111", res.GetChar());
	num1.SetByLong(-20);
	Number res2 = num1 + num2;
	ASSERT_STREQ("100000000000000000101", res2.GetChar());
	num1.SetByLong(15);
	Number res3 = num1 + num2;
	ASSERT_STREQ("000000000000000011110", res3.GetChar());
	num1.SetByLong(454);
	Number res4 = num1 + num2;
	ASSERT_STREQ("000000000000111010101", res4.GetChar());
}