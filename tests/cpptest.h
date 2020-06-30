#ifndef CPPTEST_H
#define CPPTEST_H

#include <sstream>
#include <vector>
#include <iostream>
#include <cstring>

namespace cpptest
{
    int numFailed;
    std::vector<void (*)()> allTests;

    void failed(const std::string &error)
    {
        std::cout << error << std::endl;
        ++numFailed;
    }

    template <typename T1, typename T2>
    std::string makeError(T1 actual, T2 expected, const std::string &line)
    {
        std::stringstream ss;
        ss << "\tError in line " << line
            << "\n\t\tExpected: " << expected
            << "\n\t\tActual: " << actual;
        return ss.str();
    }

    void init(const std::vector<void (*)()> tests)
    {
        allTests = tests;
        numFailed = 0;
    }

    int runAllTests()
    {
        for(void (*func)() : allTests)
            func();

        return numFailed == 0 ? 0 : 1;
    }
}

#define EXPECT_TRUE(x) \
    { if ( !(x) ) cpptest::failed(cpptest::makeError("true", "false", std::to_string(__LINE__))); }

#define EXPECT_FALSE(x) \
    { if ( (x) ) cpptest::failed(cpptest::makeError("false", "true", std::to_string(__LINE__))); }

#define EXPECT_EQ(x, y) \
    { if ( (x) != (y) ) cpptest::failed(cpptest::makeError((x), (y), std::to_string(__LINE__))); }

#define EXPECT_NE(x, y) \
    { if ( (x) == (y) ) cpptest::failed(cpptest::makeError((x), (y), std::to_string(__LINE__))); }

#define EXPECT_STREQ(x, y) \
    { if ( strcmp((x),(y)) ) cpptest::failed(cpptest::makeError((x), (y), std::to_string(__LINE__))); }

#define EXPECT_STRNE(x, y) \
    { if ( !strcmp((x),(y)) ) cpptest::failed(cpptest::makeError((x), (y), std::to_string(__LINE__))); }


#endif

