cmake_minimum_required(VERSION 3.20)
project(BlackJack)

set(CMAKE_CXX_STANDARD 14)
set(SOURCES main.cpp LinkedList.cpp CardType.h Suit.h Card.cpp Card.h Deck.cpp Deck.h Player.cpp Player.h LinkedList.h)

add_executable(BlackJack ${SOURCES})
