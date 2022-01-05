#include "Deck.h"
#include "Player.h"
#include <iostream>
#include <fstream>

#define STAND 's'
#define HIT 'h'
#define END 'q'
#define YES 'y'

bool NEED_LOG = false;

std::ofstream log;

void print_game_state(const Player& pl, const Player& dil, bool print_dealer_hand = false);

void dealer_move(Player& dealer, Player& player, Deck& deck);

void define_winner(Player& player, Player& dealer);

std::streambuf* rederict_stream();

int main() {

    Deck deck;
    deck.shuffle();
    Player player, dealer;

    player.add_card(deck.get_card());
    player.add_card(deck.get_card());

    dealer.add_card(deck.get_card());
    dealer.add_card(deck.get_card());

    char answer = 0;
    std::cout << "Do you need log of game?(y/n): ";
    std::cin >> answer;
    if (answer == YES){
        NEED_LOG = true;
        log.open("log.txt");
    }

    answer = 0;
    while(answer != END) {
        print_game_state(player, dealer);

        std::cout << "Stand(s) or Hit(h)? For quit enter type (q)." << std::endl;
        std::cin >> answer;

        switch (answer) {
            case HIT:
                player.add_card(deck.get_card());
                log << "\nplayer turn hit" << std::endl;
                break;
            case STAND:
                log << "\nplayer turn stand" << std::endl;

                dealer_move(dealer, player, deck);
                define_winner(player, dealer);

                answer = END;
                break;
        }

        if (player.get_hand_sum() == 21) {
            print_game_state(player, dealer);
            std::streambuf* cout_buf = rederict_stream();
            std::cout << "You WIN!" << std::endl;
            std::cout.rdbuf(cout_buf);

            std::cout << "You WIN!" << std::endl;
            break;
        } else if (player.get_hand_sum() > 21) {
            print_game_state(player, dealer);

            std::streambuf* cout_buf = rederict_stream();
            std::cout << "You LOSE!" << std::endl;
            std::cout.rdbuf(cout_buf);

            std::cout << "You LOSE!" << std::endl;
            break;
        }
    }

    log.close();
    return 0;

}

void print_game_state(const Player& pl, const Player& dil, bool print_dealer_hand) {

    printf("\e[1;1H\e[2J"); // clear console/terminal

    std::streambuf* cout_buf = rederict_stream();
    std::cout << "\n******************************************" << std::endl;
    std::cout.rdbuf(cout_buf);
    std::cout << "\n******************************************" << std::endl;

    cout_buf = rederict_stream();
    std::cout << "Your sum:   " << pl.get_hand_sum()     << std::endl;
    std::cout.rdbuf(cout_buf);
    std::cout << "Your sum:   " << pl.get_hand_sum()     << std::endl;

    cout_buf = rederict_stream();
    pl.print_hand(); std::cout << std::endl;
    std::cout.rdbuf(cout_buf);
    pl.print_hand(); std::cout << std::endl;

    cout_buf = rederict_stream();
    std::cout << "******************************************\n" << std::endl;
    std::cout.rdbuf(cout_buf);
    std::cout << "******************************************\n" << std::endl;

    if (!print_dealer_hand){
        cout_buf = rederict_stream();
        std::cout << "Diller sum: " << dil.get_last_card().get_value() << std::endl;
        std::cout.rdbuf(cout_buf);
        std::cout << "Diller sum: " << dil.get_last_card().get_value() << std::endl;

        cout_buf = rederict_stream();
        std::cout << dil.get_last_card() << std::endl;
        std::cout.rdbuf(cout_buf);
        std::cout << dil.get_last_card() << std::endl;

        cout_buf = rederict_stream();
        std::cout << "******************************************\n" << std::endl;
        std::cout.rdbuf(cout_buf);
        std::cout << "******************************************\n" << std::endl;
    } else {
        cout_buf = rederict_stream();
        std::cout << "Diller sum: " << dil.get_hand_sum() << std::endl;
        std::cout.rdbuf(cout_buf);
        std::cout << "Diller sum: " << dil.get_hand_sum() << std::endl;

        cout_buf = rederict_stream();
        dil.print_hand(); std::cout << std::endl;
        std::cout.rdbuf(cout_buf);
        dil.print_hand(); std::cout << std::endl;

        cout_buf = rederict_stream();
        std::cout << "******************************************\n" << std::endl;
        std::cout.rdbuf(cout_buf);
        std::cout << "******************************************\n" << std::endl;
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
        std::streambuf* cout_buf = rederict_stream();
        std::cout << "You WIN!" << std::endl;
        std::cout.rdbuf(cout_buf);
        std::cout << "You WIN!" << std::endl;
        return;
    }

    if (player.get_hand_sum() > dealer.get_hand_sum()) {
        std::streambuf* cout_buf = rederict_stream();
        std::cout << "You WIN!" << std::endl;
        std::cout.rdbuf(cout_buf);
        std::cout << "You WIN!" << std::endl;
    } else if (player.get_hand_sum() < dealer.get_hand_sum()) {
        std::streambuf* cout_buf = rederict_stream();
        std::cout << "You LOSE!" << std::endl;
        std::cout.rdbuf(cout_buf);
        std::cout << "You LOSE!" << std::endl;
    } else {
        std::streambuf* cout_buf = rederict_stream();
        std::cout << "DRAW!" << std::endl;
        std::cout.rdbuf(cout_buf);
        std::cout << "DRAW!" << std::endl;
    }

}

std::streambuf* rederict_stream() {

    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(log.rdbuf());
    return coutbuf;

}