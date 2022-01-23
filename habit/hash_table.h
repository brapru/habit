/*
 * Copyright (c) 2022, Brandon Pruitt <brapru@pm.me>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <habit/list.h>
#include <memory>

namespace habit {

template<typename T>
class hash_table {
public:
    struct Bucket {
        habit::list<T> chain;
    };

    hash_table()
        : m_capacity(10)
        , m_size(0)
    {
        m_buckets = new Bucket[m_capacity];
    }

    hash_table(unsigned bucket_size)
        : m_capacity(bucket_size)
        , m_size(0)
    {
        m_buckets = new Bucket[m_capacity];
    }

    ~hash_table() { delete[] m_buckets; }

    unsigned size() const { return m_size; }
    unsigned capacity() const { return m_capacity; }

    bool is_empty() const { return m_size == 0; }

    bool contains(T const& value)
    {
        auto index = hash_to_get_index(value);
        auto& bucket = m_buckets[index].chain;

        return bucket.contains(value);
    }

    void set(T const& value)
    {
        auto index = hash_to_get_index(value);

        auto& bucket = m_buckets[index].chain;

        if (bucket.contains(value)) {
            return;
        } else {
            bucket.push_front(value);
            m_size++;
        }
    }

    void remove(T const& value)
    {
        auto index = hash_to_get_index(value);

        auto& bucket = m_buckets[index].chain;

        if (!bucket.contains(value)) {
            return;
        } else {
            bucket.remove(value);
            m_size--;
        }
    }

private:
    Bucket* m_buckets;
    size_t m_size;
    size_t m_capacity;

    // TODO: Using std::hash until we can come up with our own implementation
    unsigned hash_to_get_index(T const& key)
    {
        return std::hash<T> {}(key) % m_capacity;
    }
};

};