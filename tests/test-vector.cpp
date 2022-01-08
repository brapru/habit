/*
 * Copyright (c) 2022, Brandon Pruitt <brapru@pm.me>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <gtest/gtest.h>

#include <habit/vector.h>

TEST(TestVector, TestConstruct)
{
    habit::vector<int> test;

    EXPECT_EQ(test.is_empty(), true);
    EXPECT_EQ(test.size(), 0);
}

TEST(TestVector, TestPushBack)
{
    habit::vector<int> test;

    test.push_back(1);

    EXPECT_EQ(!test.is_empty(), true);
    EXPECT_EQ(test.size(), 1);
}

TEST(TestVector, TestLargePushBack)
{
    habit::vector<int> test;

    for (int i = 0; i < 1000; i++)
        test.push_back(1);

    EXPECT_EQ(test.size(), 1000);
}

TEST(TestVector, TestAt)
{
    habit::vector<int> test;

    test.push_back(0);
    test.push_back(1);
    test.push_back(2);

    EXPECT_EQ(test.at(0), 0);
    EXPECT_EQ(test.at(1), 1);
    EXPECT_EQ(test.at(2), 2);
}

TEST(TestVector, TestPopBack)
{
    habit::vector<int> test;

    test.push_back(0);
    test.push_back(1);
    test.pop_back();

    EXPECT_EQ(test.size(), 1);
}

TEST(TestVector, TestFront)
{
    habit::vector<int> test;

    test.push_back(0);

    EXPECT_EQ(test.front(), 0);
}

TEST(TestVector, TestBack)
{
    habit::vector<int> test;

    test.push_back(0);
    test.push_back(1);

    EXPECT_EQ(test.back(), 1);
}