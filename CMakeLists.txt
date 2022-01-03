cmake_minimum_required(VERSION 3.20)
project(BlackJack)

set(CMAKE_CXX_STANDARD 14)
set(SOURCES main.cpp LinkedList.cpp)

add_executable(BlackJack ${SOURCES})
