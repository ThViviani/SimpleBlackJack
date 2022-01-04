#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

#include "CardType.h"
#include "Suit.h"
#include <iostream>
#include <string>

class Card {
private:
    Suit suit;
    CardType type;
    int value;
    std::string type_name;
    std::string suit_ch;

public:
    Card();
    Card(Suit s, CardType type, int val);
    int get_value() const;
    friend std::ostream& operator<< (std::ostream& out, const Card& card);
};


#endif //BLACKJACK_CARD_H
