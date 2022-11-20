cmake_minimum_required(VERSION 3.14)
project(algorithms)

set(CMAKE_CXX_STANDARD 20)

set(SORT_LIBRARY_NAME SORTLIB)

add_library(${SORT_LIBRARY_NAME} src/InsertionSort.cpp)

target_include_directories(${SORT_LIBRARY_NAME} PRIVATE
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${SORT_LIBRARY_NAME}>
$<INSTALL_INTERFACE:include/${SORT_LIBRARY_NAME}
)

target_include_directories(${SORT_LIBRARY_NAME} PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
$<INSTALL_INTERFACE:include>
)


###### TESTING #########

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(SortTest tests/TestSorting.cpp)
target_link_libraries(
  SortTest
  ${SORT_LIBRARY_NAME}
  GTest::gtest_main
)

include(GoogleTest)

if (NOT (TARGET gtest AND TARGET gtest_main))
    message(FATAL_ERROR "gtest and gtest_main targets NOT found")
endif()

gtest_discover_tests(SortTest)