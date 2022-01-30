/*
 * Copyright (c) 2022, Brandon Pruitt <brapru@pm.me>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#include <gtest/gtest.h>

#include <habit/binary_search.h>
#include <habit/vector.h>

TEST(TestBinarySearch, TestIntegers)
{
    habit::vector<int> test;

    // Load the test vector with only odd numbers
    for (int i = 0; i < 100; i++) {
        if (i % 2 == 0)
            continue;
        test.push_back(i);
    }

    EXPECT_EQ(binary_search(test, 1), true);
    EXPECT_EQ(binary_search(test, 2), false);
    EXPECT_EQ(binary_search(test, 100), false);
}

TEST(TestBinarySearch, TestDoubles)
{
    habit::vector<double> test;

    test.push_back(0.1);
    test.push_back(1.4);
    test.push_back(4.2);
    test.push_back(5.0);

    EXPECT_EQ(binary_search(test, 1.5), false);
    EXPECT_EQ(binary_search(test, 4.2), true);
}

TEST(TestBinarySearch, TestSingleElement)
{
    habit::vector<int> test;

    test.push_back(1);

    EXPECT_EQ(binary_search(test, 1), true);
}

TEST(TestBinarySearch, TestNotFound)
{
    habit::vector<int> test;

    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);

    EXPECT_EQ(binary_search(test, -1), false);
    EXPECT_EQ(binary_search(test, 0), false);
    EXPECT_EQ(binary_search(test, 10), false);
}