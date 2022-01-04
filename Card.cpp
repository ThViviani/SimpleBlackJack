//
// Created by Nikita Denisyuk on 04.01.2022.
//

#include "Card.h"

Card::Card(Suit suit, CardType type, int val) {
    this->suit  = suit;
    this->type  = type;
    this->value = val;
}
