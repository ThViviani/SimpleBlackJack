#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include "LinkedList.h"
#include "Card.h"

class Player {
private:
    int score;
    LinkedList<Card> hand;
    int hand_summ;

public:
    Player();
    void add_card(const Card& card);
    int get_hand_sum() const;
    void print_hand() const;
    Card get_last_card() const;
};


#endif //BLACKJACK_PLAYER_H
