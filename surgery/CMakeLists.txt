cmake_minimum_required(VERSION 3.17)
project(surgery CXX C)
add_definitions("-DSURGERY")
include(FetchContent)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES x-stubs-cpp.cpp stubs.cpp)

# add your C files in here after PRIVATE and uncomment the line if you do
# set(C_SOURCE_FILES PRIVATE )

# Surgery main
add_executable(main ${SOURCE_FILES})

# Surgery test - catch2
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.1)
FetchContent_MakeAvailable(Catch2)

# Surgery test - approvals
FetchContent_Declare(
  ApprovalTests
  GIT_REPOSITORY https://github.com/approvals/ApprovalTests.cpp
  GIT_TAG        v.10.5.1)
FetchContent_MakeAvailable(ApprovalTests)

# Surgery test executable
add_executable(tests ${SOURCE_FILES} unit_test.cpp)
target_link_libraries(tests Catch2::Catch2 ApprovalTests::ApprovalTests)
add_test(NAME tests COMMAND tests)

