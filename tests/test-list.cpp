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

TEST(TestList, TestPushStrings)
{
    habit::list<std::string> test;

    test.push_front("habit");
    test.push_front("test");
    test.push_back("strings");

    EXPECT_EQ(test.size(), 3);
    EXPECT_EQ(test.front(), "test");
    EXPECT_EQ(test.contains("habit"), true);
    EXPECT_EQ(test.back(), "strings");
}

TEST(TestList, TestAt)
{
    habit::list<int> test;

    test.push_back(1);
    test.push_back(2);
    test.push_back(3);

    EXPECT_EQ(test.at(0), 1);
    EXPECT_EQ(test.at(1), 2);
    EXPECT_EQ(test.at(2), 3);
}

TEST(TestList, TestAtInvalidIndex)
{
    habit::list<int> test;

    test.push_back(1);
    test.push_back(2);
    test.push_back(3);

    EXPECT_DEATH({ test.at(-1); }, "failed");
    EXPECT_DEATH({ test.at(4); }, "failed");
}

TEST(TestList, TestInsert)
{
    habit::list<int> test;

    test.push_back(1);
    test.push_back(4);
    test.insert(1, 3);
    test.insert(1, 2);

    EXPECT_EQ(test.at(0), 1);
    EXPECT_EQ(test.at(1), 2);
    EXPECT_EQ(test.at(2), 3);
    EXPECT_EQ(test.at(3), 4);
}

TEST(TestList, TestErase)
{
    habit::list<int> test;

    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);
    test.erase(1);
    test.erase(1);
    test.erase(1);

    EXPECT_EQ(test.size(), 2);
    EXPECT_EQ(test.at(0), 1);
    EXPECT_EQ(test.at(1), 5);
}

TEST(TestList, TestEraseAtZero)
{
    habit::list<int> test;

    test.push_back(1);
    test.push_back(2);
    test.push_back(3);

    test.erase(0);

    EXPECT_EQ(test.size(), 2);
    EXPECT_EQ(test.at(0), 2);
}

TEST(TestList, TestReverse)
{
    habit::list<int> test;

    test.push_back(1);
    test.push_back(2);
    test.push_back(3);

    test.reverse();

    EXPECT_EQ(test.front(), 3);
    EXPECT_EQ(test.at(1), 2);
    EXPECT_EQ(test.back(), 1);
}

TEST(TestList, TestContains)
{
    habit::list<int> test;

    test.push_back(1);
    test.push_back(2);
    test.push_back(3);

    EXPECT_EQ(test.contains(1), true);
    EXPECT_EQ(test.contains(2), true);
    EXPECT_EQ(test.contains(3), true);

    test.erase(0);
    EXPECT_EQ(test.contains(1), false);
    EXPECT_EQ(test.contains(2), true);
    EXPECT_EQ(test.contains(3), true);

    test.erase(0);
    EXPECT_EQ(test.contains(1), false);
    EXPECT_EQ(test.contains(2), false);
    EXPECT_EQ(test.contains(3), true);

    test.erase(0);
    EXPECT_EQ(test.contains(1), false);
    EXPECT_EQ(test.contains(2), false);
    EXPECT_EQ(test.contains(3), false);
    EXPECT_EQ(test.size(), 0);
}

TEST(TestList, TestRemove)
{
    habit::list<int> test;

    test.push_back(1);
    test.push_back(2);
    test.push_back(2);
    test.push_back(2);
    test.push_back(3);

    EXPECT_EQ(test.size(), 5);
    EXPECT_EQ(test.contains(2), true);

    test.remove(2);

    EXPECT_EQ(test.size(), 2);
    EXPECT_EQ(test.contains(2), false);
}

TEST(TestList, TestRemoveHead)
{
    habit::list<int> head;

    head.push_front(2);
    head.push_front(1);

    EXPECT_EQ(head.size(), 2);
    EXPECT_EQ(head.contains(1), true);

    head.remove(1);

    EXPECT_EQ(head.size(), 1);
    EXPECT_EQ(head.contains(1), false);
    EXPECT_EQ(head.back(), 2);
    EXPECT_EQ(head.front(), 2);

    head.remove(2);

    EXPECT_EQ(head.size(), 0);
    EXPECT_EQ(head.contains(2), false);
}

TEST(TestList, TestRemoveTail)
{
    habit::list<int> tail;

    tail.push_back(1);
    tail.push_back(2);

    EXPECT_EQ(tail.size(), 2);
    EXPECT_EQ(tail.contains(2), true);

    tail.remove(2);

    EXPECT_EQ(tail.size(), 1);
    EXPECT_EQ(tail.contains(2), false);
    EXPECT_EQ(tail.back(), 1);

    tail.remove(1);

    EXPECT_EQ(tail.size(), 0);
}