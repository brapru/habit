/*
 * Copyright (c) 2022, Brandon Pruitt <brapru@pm.me>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <gtest/gtest.h>

#include <habit/bubble_sort.h>
#include <habit/vector.h>

TEST(TestBubble, TestSorted)
{
    habit::vector<int> test;
    for (int loop = 10; loop >= 0; loop--) {
        test.push_back(loop);
    }

    bubble_sort(test);

    for (int i = 0; i < test.size() - 1; i++) {
        EXPECT_EQ((test[i] <= test[i + 1]), true);
    }
}