#include "Deck.h"
#include "Player.h"
#include <iostream>

#define STAND 's'
#define HIT 'h'
#define END 'q'

void print_game_state(const Player& pl, const Player& dil, bool print_empty_lines);

int main() {

    Deck deck;
    deck.shuffle();
    Player player, diller;

    player.add_card(deck.get_card());
    player.add_card(deck.get_card());

    diller.add_card(deck.get_card());
    diller.add_card(deck.get_card());

    char answer = 0;
    while(answer != END) {
        print_game_state(player, diller, answer);

        std::cout << "Stand(s) or Hit(h)? For quit enter type (q)." << std::endl;
        std::cin >> answer;

        switch (answer) {
            case HIT:
                player.add_card(deck.get_card());
                break;
            case STAND:
                // to do: AI for diller
                answer = END;
                break;
        }

        if (player.get_hand_sum() == 21) {
            print_game_state(player, diller, true);
            std::cout << "WIN!" << std::endl;
            break;
        } else if (player.get_hand_sum() > 21) {
            print_game_state(player, diller, true);
            std::cout << "LOSE!" << std::endl;
            break;
        }
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
    std::cout << "Your sum:   " << pl.get_hand_sum()     << std::endl;
    pl.print_hand(); std::cout << std::endl;
    std::cout << "******************************************" << std::endl;
    std::cout << std::endl;

    std::cout << "Diller sum: " << dil.get_last_card().get_value() << std::endl;
    std::cout << dil.get_last_card() << std::endl;
    std::cout << "******************************************" << std::endl;

}