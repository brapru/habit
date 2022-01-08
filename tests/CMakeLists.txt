set(CMAKE_BUILD_TYPE Debug)

add_executable(test-habit test-habit.cpp test-vector.cpp test-bubble.cpp)
target_link_libraries(test-habit PUBLIC libhabit)