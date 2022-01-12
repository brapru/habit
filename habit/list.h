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

    T at(int const index)
    {
        assert(index >= 0 && index < m_size);

        auto node = m_traverse_and_retrieve_node(index);
        return node->data;
    }

    void insert(int const index, T const value)
    {
        assert(index >= 0 && index < m_size);

        auto node = new Node<T>(value);
        auto prev = m_traverse_and_retrieve_node(index - 1);

        node->next = prev->next;
        prev->next = node;

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

    Node<T>* m_traverse_and_retrieve_node(int const index)
    {
        int i = 0;
        Node<T>* current = m_head;

        while (i < index && current != nullptr) {
            current = current->next;
            i++;
        }

        return current;
    }
};

};