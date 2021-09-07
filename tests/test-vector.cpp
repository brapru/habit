#include "test-habit.h"
#include "vector.h"

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
    EXPECT(test.at(0) == 1);
}

void test_vector(void)
{
    test_construct();
    test_push_back();
}
