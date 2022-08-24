//
// Created by ByLCY on 8/24/22.
//
#include <gtest/gtest.h>

#include "cpp_template/hello.h"

TEST(HelloTest, Hello) {
    start::Hello hello("ByLCY");

    EXPECT_EQ(hello.hello(), "Hello ByLCY");
    EXPECT_EQ(start::Hello::factorial(5), 120);
}