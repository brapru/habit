/*
 * Copyright (c) 2022, Brandon Pruitt <brapru@pm.me>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <cassert>

namespace habit {

template<typename T>
class vector {
public:
    vector() = default;
    ~vector() { delete[] m_data; }

    vector(unsigned capacity)
        : m_capacity(capacity)
    {
        m_data = new T[capacity];
    };

    vector(vector&& other) noexcept
        : m_data(std::move(other))
    {
    }

    T& operator[](int const& index)
    {
        assert(index >= 0 && index < size());
        return m_data[index];
    }

    const T& operator[](int const& index) const
    {
        assert(index >= 0 && index < size());
        return m_data[index];
    }

    unsigned size() const { return m_size; }
    unsigned capacity() const { return m_data ? m_capacity : 0; }
    bool is_empty() const { return size() == 0; }

    T at(int const& index) { return m_data[index]; }
    T front(void) { return m_data[0]; }
    T back(void) { return m_data[m_size - 1]; }

    void push_back(T value)
    {
        ensure_capacity(size() + 1);

        m_data[m_size] = std::move(value);
        m_size++;
    }

    void pop_back()
    {
        m_size--;
        m_data[m_size].~T();
    }

    void insert(int const& index, T value)
    {
        assert(index >= 0 && index < size());

        ensure_capacity(m_size + 1);

        for (unsigned i = m_size; i > index; i--) {
            m_data[i] = m_data[i - 1];
        }

        m_data[index] = std::move(value);
        m_size++;
    }

private:
    void ensure_capacity(size_t size)
    {
        if (capacity() >= size)
            return;

        unsigned new_capacity = get_padded_capacity();
        T* new_vector = new T[new_capacity];

        for (unsigned i = 0; i < m_size; ++i) {
            new_vector[i] = std::move(m_data[i]);
        }

        delete[] m_data;

        m_data = new_vector;
        m_capacity = new_capacity;
    }

    unsigned get_padded_capacity() const
    {
        return capacity() == 0 ? 1 : capacity() * 2;
    }

    T* m_data = nullptr;
    size_t m_size { 0 };
    size_t m_capacity;
};

};
