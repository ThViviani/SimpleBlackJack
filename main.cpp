#include "Deck.h"
#include "Player.h"
#include <iostream>

#define STAND 's'

void print_game_state(const Player& pl, const Player& dil, bool print_empty_lines);

int main() {

    Deck deck;
    deck.shuffle();
    Player player, diller;

    char answer = 0;
    while(answer != STAND) {
        player.add_card(deck.get_card());
        player.add_card(deck.get_card());

        diller.add_card(deck.get_card());
        diller.add_card(deck.get_card());

        print_game_state(player, diller, answer);

        std::cout << "Stand(s) or Hit(h)?" << std::endl;
        std::cin >> answer;
    }
    return 0;

}

void print_game_state(const Player& pl, const Player& dil, bool print_empty_lines) {

    if (print_empty_lines){
        for (int i = 1; i < 5; ++i) {
            std::cout << std::endl;
        }
    }

    std::cout << "******************************************" << std::endl;
    std::cout << "Your hand sum:   " << pl.get_hand_sum()     << std::endl;
    pl.print_hand(); std::cout << std::endl;
    std::cout << "******************************************" << std::endl;
    std::cout << std::endl;

    std::cout << "Diller hand sum: " << dil.get_hand_sum()    << std::endl;
    dil.print_hand(); std::cout << std::endl;
    std::cout << "******************************************" << std::endl;

}