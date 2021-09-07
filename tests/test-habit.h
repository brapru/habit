#pragma once

#include <iostream>

#define EXPECT(x)                    \
    do {                             \
        if (x)                       \
            std::cout << "Passed\n"; \
        else                         \
            std::cout << "Failed\n"; \
    } while (0)
