/*
 * Copyright (c) 2022, Brandon Pruitt <brapru@pm.me>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

namespace habit {

template<typename T>
static bool is_sorted(T& a)
{
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}

template<typename T>
static void swap(T& a, T& b)
{
    auto temp = a;
    a = b;
    b = temp;
}
}