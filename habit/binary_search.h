/*
 * Copyright (c) 2022, Brandon Pruitt <brapru@pm.me>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <habit/utils.h>

namespace habit {

template<typename Collection, typename SearchFor>
constexpr bool binary_search(Collection& collection, SearchFor value)
{
    int left = 0;
    int right = collection.size() - 1;

    while (left <= right) {
        int middle = (right + left) / 2;

        if (collection[middle] == value)
            return true;
        else if (value <= collection[middle])
            right = middle - 1;
        else
            left = middle + 1;
    }

    return false;
}

}