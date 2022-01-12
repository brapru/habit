/*
 * Copyright (c) 2022, Brandon Pruitt <brapru@pm.me>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

namespace habit {

template<typename T>
struct Node {
    Node(T value)
        : next(nullptr)
        , data(value)
    {
    }

    T data;
    Node<T>* next;
};

template<typename T>
class list {
public:
    list()
        : m_head(nullptr)
        , m_tail(nullptr)
        , m_size(0)
    {
    }

    ~list()
    {
        m_destroy(m_head);
    };

    int size() const { return m_size; }
    bool empty() const { return m_size == 0; }

    T front() { return m_head->data; }
    T back() { return m_tail->data; }

    void push_front(T const value)
    {
        auto node = new Node<T>(value);
        node->next = m_head;
        m_head = node;

        if (m_size == 0)
            m_tail = m_head;

        m_size++;
    }

    void push_back(T const value)
    {
        auto node = new Node<T>(value);

        if (m_tail != nullptr)
            m_tail->next = node;

        m_tail = node;

        if (m_size == 0)
            m_head = m_tail;

        m_size++;
    }

private:
    Node<T>* m_head;
    Node<T>* m_tail;
    size_t m_size;

    void m_destroy(Node<T>* node)
    {
        if (node == nullptr)
            return;

        m_destroy(node->next);
        delete node;
    }
};

};