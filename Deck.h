#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include "LinkedList.h"
#include "Card.h"

void random_swap(int cur, Card arr[]);

class Deck {
private:
    LinkedList<Card> ls;

public:
    Deck();
    void shuffle();
    Card get_card();
    void create_deck();
    void clear();
};


#endif //BLACKJACK_DECK_H
