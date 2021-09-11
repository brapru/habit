#include "test-habit.h"

#include "habit/vector.h"

static void test_construct(void)
{
    habit::vector<int> test;

    EXPECT(test.is_empty());
    EXPECT(test.size() == 0);
}

static void test_push_back(void)
{
    habit::vector<int> test;

    test.push_back(1);

    EXPECT(!test.is_empty());
    EXPECT(test.size() == 1);
}

static void test_large_push_back(void)
{
    habit::vector<int> test;

    for (int i = 0; i < 1000; i++)
        test.push_back(1);

    EXPECT(test.size() == 1000);
}

static void test_at(void)
{
    habit::vector<int> test;

    test.push_back(0);
    test.push_back(1);
    test.push_back(2);

    EXPECT(test.at(0) == 0);
    EXPECT(test.at(1) == 1);
    EXPECT(test.at(2) == 2);
}

static void test_pop_back(void)
{
    habit::vector<int> test;

    test.push_back(0);
    test.push_back(1);
    test.pop_back();

    EXPECT(test.size() == 1);
}

static void test_front(void)
{
    habit::vector<int> test;

    test.push_back(0);

    EXPECT(test.front() == 0);
}

static void test_back(void)
{
    habit::vector<int> test;

    test.push_back(0);
    test.push_back(1);

    EXPECT(test.back() == 1);
}

void test_vector(void)
{
    test_construct();
    test_push_back();
    test_large_push_back();
    test_pop_back();
    test_at();
    test_front();
    test_back();
}
