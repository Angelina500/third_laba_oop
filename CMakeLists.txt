cmake_minimum_required(VERSION 3.14)
project(Projectlaba3C++)

set(CMAKE_CXX_STANDARD 14)

# Настройка Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# Основная программа
add_executable(mainttr 
    src/main.cpp 
    src/Figure.cpp
    src/Triangle.cpp 
    src/Square.cpp 
    src/Rectangle.cpp
)

# Тесты
add_executable(tests 
    tests/tests.cpp 
    src/Figure.cpp
    src/Triangle.cpp 
    src/Square.cpp 
    src/Rectangle.cpp
)
target_link_libraries(tests gtest_main)

# Добавляем include директорию для заголовков
target_include_directories(mainttr PRIVATE src)
target_include_directories(tests PRIVATE src)