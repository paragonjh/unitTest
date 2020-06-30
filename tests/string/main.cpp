#include "cpptest.h"

#include "mystring.h"

#include <iostream>

void testStringBasic()
{
    String str1;
    EXPECT_TRUE(str1.get() == nullptr);

    String str2("hello");
    EXPECT_STREQ(str2.get(), "hello");
}

void testStringCopy()
{
    String str1("hello");
    EXPECT_STREQ(str1.get(), "hello");

    String str2 = str1;
    EXPECT_STREQ(str2.get(), "hello");

    String str3;
    str3 = str1;
    EXPECT_STREQ(str3.get(), "hello");

    str1 = str1;
    EXPECT_STREQ(str1.get(), "hello");
}

void testStringCompare()
{
    String str1("hello");
    String str2("world");
    String str3("hello");

    EXPECT_NE(str1, str2);
    EXPECT_EQ(str1, str3);
}

int main()
{
    cpptest::init({
        testStringBasic,
        testStringCopy,
        testStringCompare
    });

    return cpptest::runAllTests();
}

