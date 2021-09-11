target_compile_features(habit INTERFACE cxx_std_20)

target_include_directories(
    habit
    INTERFACE
)

set(CMAKE_BUILD_TYPE Debug)

add_executable(habit-test test-habit.cpp test-vector.cpp test-bubble.cpp)
include_directories(habit-test PRIVATE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/tests)
