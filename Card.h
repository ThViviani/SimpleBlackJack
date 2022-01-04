#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

#include "CardType.h"
#include "Suit.h"
#include <iostream>

class Card {
private:
    Suit suit;
    CardType type;
    int value;
public:
    Card();
    Card(Suit s, CardType type, int val);
    int get_value();
};


#endif //BLACKJACK_CARD_H
