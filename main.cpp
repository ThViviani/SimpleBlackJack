#include "Deck.h"
#include "Player.h"
#include <iostream>

#define STAND 's'
#define HIT 'h'
#define END 'q'

void print_game_state(const Player& pl, const Player& dil, bool print_dealer_hand = false);

void dealer_move(Player& dealer, Player& player, Deck& deck);

void define_winner(Player& player, Player& dealer);

int main() {

    Deck deck;
    deck.shuffle();
    Player player, dealer;

    player.add_card(deck.get_card());
    player.add_card(deck.get_card());

    dealer.add_card(deck.get_card());
    dealer.add_card(deck.get_card());

    char answer = 0;
    while(answer != END) {
        print_game_state(player, dealer);

        std::cout << "Stand(s) or Hit(h)? For quit enter type (q)." << std::endl;
        std::cin >> answer;

        switch (answer) {
            case HIT:
                player.add_card(deck.get_card());
                break;
            case STAND:
                dealer_move(dealer, player, deck);
                define_winner(player, dealer);

                answer = END;
                break;
        }

        if (player.get_hand_sum() == 21) {
            print_game_state(player, dealer);
            std::cout << "You WIN!" << std::endl;
            break;
        } else if (player.get_hand_sum() > 21) {
            print_game_state(player, dealer);
            std::cout << "You LOSE!" << std::endl;
            break;
        }
    }

    return 0;

}

void print_game_state(const Player& pl, const Player& dil, bool print_dealer_hand) {

    printf("\e[1;1H\e[2J"); // clear console/terminal

    std::cout << "******************************************" << std::endl;
    std::cout << "Your sum:   " << pl.get_hand_sum()     << std::endl;
    pl.print_hand(); std::cout << std::endl;
    std::cout << "******************************************" << std::endl;
    std::cout << std::endl;

    if (!print_dealer_hand){
        std::cout << "Diller sum: " << dil.get_last_card().get_value() << std::endl;
        std::cout << dil.get_last_card() << std::endl;
        std::cout << "******************************************" << std::endl;
    } else {
        std::cout << "Diller sum: " << dil.get_hand_sum() << std::endl;
        dil.print_hand(); std::cout << std::endl;
        std::cout << "******************************************" << std::endl;
    }
}

void dealer_move(Player& dealer, Player& player, Deck& deck) {

    print_game_state(player, dealer, true);
    while (dealer.get_hand_sum() < 17) {
        dealer.add_card(deck.get_card());
        print_game_state(player, dealer, true);
    }

}

void define_winner(Player& player, Player& dealer) {

    if (dealer.get_hand_sum() > 21) {
        std::cout << "You WIN!" << std::endl;
        return;
    }

    if (player.get_hand_sum() > dealer.get_hand_sum()) {
        std::cout << "You WIN!" << std::endl;
    } else if (player.get_hand_sum() < dealer.get_hand_sum()) {
        std::cout << "You LOSE!" << std::endl;
    } else {
        std::cout << "Draw!" << std::endl;
    }

}