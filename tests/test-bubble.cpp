/*
 * Copyright (c) 2021, Brandon Pruitt <brapru@pm.me>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "test-habit.h"

#include "habit/bubble_sort.h"
#include "habit/vector.h"

void test_bubble_sort(void)
{
    habit::vector<int> test;
    for (int loop = 0; loop < 10; loop++) {
        test.push_back(RANDOM_INT(100));
    }

    bubble_sort(test);

    EXPECT_SORTED(test);
}