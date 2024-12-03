cmake_minimum_required(VERSION 3.14)
project(loop)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/src)

# Add main source files
add_executable(loop
  src/cpp_for_loop.cpp
  src/main.cpp # If you have a main.cpp or other source files
)

# Add test source files
add_executable(
  main_test
  tests/main_test.cpp
  src/cpp_for_loop.cpp  # Add the source file containing the function definition
  src/utils.cpp
)

# Link GoogleTest libraries to test executable
target_link_libraries(
  main_test  
  GTest::gtest_main
)

# Discover and run tests
include(GoogleTest)
gtest_discover_tests(main_test)
