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
	ASSERT_ANY_THROW(num1.SetByChar("b11"));
	ASSERT_ANY_THROW(num1.SetByChar("11d"));
	ASSERT_ANY_THROW(num1.SetByChar("-1a1"));
	ASSERT_ANY_THROW(num1.SetByChar("-11a"));
	ASSERT_ANY_THROW(num1.SetByChar("-a11"));
}


TEST(Constructor, Getter) // Checking getter
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