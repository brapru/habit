/*
 * Copyright (c) 2021, Brandon Pruitt <brapru@pm.me>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

namespace habit {

template<typename Collection>
void bubble_sort(Collection& collection)
{
    for (int i = 0; i < collection.size() - 1; i++) {
        for (int j = 0; j < collection.size() - i - 1; j++) {
            if (collection[j] > collection[j + 1]) {
                swap(collection[j], collection[j + 1]);
            }
        }
    }
}

}