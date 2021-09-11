/*
 * Copyright (c) 2021, Brandon Pruitt <brapru@pm.me>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <iostream>
#include <random>

#include "habit/utils.h"

#define RANDOM_INT(max) ({                          \
    int retval;                                     \
    std::random_device rd;                          \
    std::mt19937 rng(rd());                         \
    std::uniform_int_distribution<int> uni(0, max); \
    retval = uni(rng); })

#define EXPECT(x)                    \
    do {                             \
        if (x)                       \
            std::cout << "Passed\n"; \
        else                         \
            std::cout << "Failed\n"; \
    } while (0)

#define EXPECT_SORTED(x)             \
    do {                             \
        EXPECT(habit::is_sorted(x)); \
    } while (0)
