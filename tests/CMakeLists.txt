#### THIS CODE IS NOT MINE AND WAS TAKEN FROM A FORUM

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

enable_testing()

add_executable(sort_test sortingtest.cpp)

target_link_libraries(sort_test
 PRIVATE
  GTest::GTest
  sorts)

add_test(TestselectionSort sort_test)
add_test(TestinsertSort sort_test)
add_test(TestbubbleSort sort_test)
add_test(TestcocktailSort sort_test)
add_test(TestquickSort sort_test)
add_test(TestshellSort sort_test)
add_test(TestgnomeSort sort_test)
add_test(TeststoogeSort sort_test)
add_test(TestslowSort sort_test)
add_test(Test_odd_even_Sort sort_test)

#### THIS CODE IS NOT MINE AND WAS TAKEN FROM A FORUM
