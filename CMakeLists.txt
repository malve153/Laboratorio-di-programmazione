cmake_minimum_required(VERSION 2.9 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)

project (Book)

include_directories(include)

add_library(Isbn
    src/Isbn.cpp
)

add_library(Date
    src/Date.cpp
)

add_library(Book
    src/Book.cpp
)

add_executable(main
    src/main.cpp
)

target_link_libraries(main
    Date
    Isbn
    Book
)