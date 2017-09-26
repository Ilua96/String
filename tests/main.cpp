#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <gtest/gtest.h>
#include <conio.h>
#include "stringlib.h"

using namespace std;

class TestString : public ::testing::Test {};

TEST_F(TestString, constructors)
{
	String a("sfhkjfhak");
	ASSERT_STREQ(a.getString(), "sfhkjfhak");
	String b(a);
	ASSERT_STREQ(b.getString(), "sfhkjfhak");
}

TEST_F(TestString, equality)
{
	String a("sample");
	String b;
	b = a;
	ASSERT_STREQ(b.getString(), a.getString());
}

TEST_F(TestString, concatenation)
{
	String a("left");
	String b(" right");
	ASSERT_STREQ((a + b).getString(), "left right");
	ASSERT_STREQ((a + 'd').getString(), "leftd");
	ASSERT_STREQ((a + "d").getString(), "leftd");
}

TEST_F(TestString, insert)
{
	String a("1245");
	String b("3");
	a.insert(2, b);
	ASSERT_STREQ(a.getString(), "12345");
	a = "1245";
	a.insert(2, "333");
	ASSERT_STREQ(a.getString(), "1233345");
}

TEST_F(TestString, comparasion)
{
	String a("Sample");
	String b("Sample");
	ASSERT_TRUE(a == b);
	ASSERT_FALSE(a != b);

	ASSERT_TRUE(a == "Sample");
	ASSERT_FALSE(a != "Sample");

	b = String("other");
	ASSERT_FALSE(a == b);
	ASSERT_TRUE(a != b);

	ASSERT_FALSE(a == "other");
	ASSERT_TRUE(a != "other");
}

TEST_F(TestString, find)
{
	String a("Sample text");
	String b("text");
	int i = a.find(b);
	ASSERT_EQ(i, 7);

	i = a.find("text");
	ASSERT_EQ(i, 7);

	b = String("new");
	i = a.find(b);
	ASSERT_EQ(i, -1);

}

TEST_F(TestString, substr)
{
	String s("ababaca");
	ASSERT_TRUE(s.substr(2, 5) == "baba");
}

TEST_F(TestString, out)
{
	String s("");
	cout << s;
	ASSERT_TRUE(true);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	_getch();
	return 0;
}
