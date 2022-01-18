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

    void erase(int const index)
    {
        assert(index >= 0 && index < m_size);

        auto current = m_traverse_and_retrieve_node(index);

        if (current->next == nullptr) {
            delete current;
            m_size--;
            return;
        }

        auto node = current->next;
        current->next = node->next;
        current->data = node->data;

        delete node;
        m_size--;
    }

    void reverse()
    {
        Node<T>* prev = nullptr;
        Node<T>* current = m_head;
        Node<T>* following = m_head;

        while (current != nullptr) {
            if (prev == nullptr)
                m_tail = current;

            following = following->next;
            current->next = prev;

            prev = current;
            current = following;
        }

        m_head = prev;
    }

    bool contains(T const value)
    {
        Node<T>* current = m_head;

        while (current != nullptr) {
            if (current->data == value)
                return true;

            current = current->next;
        }

        return false;
    }

private:
    Node<T>* m_head;
    Node<T>* m_tail;
    size_t m_size;

    void m_destroy(Node<T>* node)
    {
        if (node == nullptr || node->next == nullptr)
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