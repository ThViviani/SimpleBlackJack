#include "Card.h"

Card::Card() {
    this->suit = clubs;
    this->type = NUMERIC;
    this->value = 0;
}

Card::Card(Suit suit, CardType type, int val) {
    this->suit  = suit;
    this->type  = type;
    this->value = val;
}

