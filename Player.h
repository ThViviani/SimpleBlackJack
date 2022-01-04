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
    void add_card(Card& card);
};


#endif //BLACKJACK_PLAYER_H
