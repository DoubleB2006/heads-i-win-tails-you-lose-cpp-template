cmake_minimum_required(VERSION 3.24)

project(heads_i_win_tails_you_lose)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(coinflip_test tests/coinflip_test.cpp src/coinflip.cpp)
add_executable(main main.cpp src/coinflip.cpp)

target_link_libraries(coinflip_test PRIVATE Catch2::Catch2WithMain)
