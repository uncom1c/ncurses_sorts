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

add_executable(sort_test sortingtest.cpp)

target_link_libraries(sort_test
 PRIVATE
  GTest::GTest
  sorts)

add_test(sort_gtests sort_test)

#### THIS CODE IS NOT MINE AND WAS TAKEN FROM A FORUM
