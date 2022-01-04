#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include "LinkedList.cpp"
#include "Card.h"

void random_swap(int cur, Card arr[]);

class Deck {
private:
    LinkedList<Card> ls;
    void create_deck();

public:
    Deck();
    void shuffle();
};


#endif //BLACKJACK_DECK_H
