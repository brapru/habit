/*
 * Copyright (c) 2022, Brandon Pruitt <brapru@pm.me>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <gtest/gtest.h>

#include <habit/hash_table.h>

TEST(TestHashTable, TestConstructEmpty)
{
    habit::hash_table<int> test;

    EXPECT_EQ(test.capacity(), 10);
    EXPECT_EQ(test.size(), 0);
    EXPECT_EQ(test.is_empty(), true);
}

TEST(TestHashTable, TestConstructWithCapacity)
{
    habit::hash_table<int> test(100);

    EXPECT_EQ(test.capacity(), 100);
    EXPECT_EQ(test.size(), 0);
}

TEST(TestHashTable, TestSet)
{
    habit::hash_table<int> test;

    test.set(54321);
    test.set(12345);
    test.set(12345);

    EXPECT_EQ(test.size(), 2);
    EXPECT_EQ(test.is_empty(), false);
}

TEST(TestHashTable, TestSetStrings)
{
    habit::hash_table<std::string> test;

    test.set("habit");
    test.set("test");
    test.set("test");

    EXPECT_EQ(test.size(), 2);
}

TEST(TestHashTable, TestContains)
{
    habit::hash_table<int> test;

    test.set(12345);

    EXPECT_EQ(test.contains(12345), true);
    EXPECT_EQ(test.contains(123456), false);

    habit::hash_table<std::string> test_string;
    test_string.set("habit");

    EXPECT_EQ(test_string.contains("habit"), true);
    EXPECT_EQ(test_string.contains("test"), false);
}

TEST(TestHashTable, TestRemove)
{
    habit::hash_table<int> test;

    test.set(54321);
    test.set(12345);

    EXPECT_EQ(test.size(), 2);
    EXPECT_EQ(test.contains(54321), true);

    test.remove(54321);

    EXPECT_EQ(test.size(), 1);
    EXPECT_EQ(test.contains(54321), false);
}