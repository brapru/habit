target_compile_features(habit INTERFACE cxx_std_20)

target_include_directories(
    habit
    INTERFACE
)

add_executable(habit-test test-habit.cpp test-vector.cpp)
include_directories(habit-test PRIVATE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/tests)
