#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

#include "CardType.h"
#include "Suit.h"

class Card {
private:
    Suit suit;
    CardType type;
    int value;
public:
    Card(Suit s, CardType type, int val);
};


#endif //BLACKJACK_CARD_H
