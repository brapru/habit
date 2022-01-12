/*
 * Copyright (c) 2022, Brandon Pruitt <brapru@pm.me>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <gtest/gtest.h>

#include <habit/list.h>

TEST(TestList, TestConstructEmpty)
{
    habit::list<int> test;

    EXPECT_EQ(test.empty(), true);
}

TEST(TestList, TestPushFront)
{
    habit::list<int> test;

    test.push_front(1);
    test.push_front(2);
    test.push_front(3);
    test.push_front(4);
    test.push_front(5);

    EXPECT_EQ(test.size(), 5);
    EXPECT_EQ(test.front(), 5);
}

TEST(TestList, TestPushBack)
{
    habit::list<int> test;

    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);

    EXPECT_EQ(test.size(), 5);
    EXPECT_EQ(test.back(), 5);
}