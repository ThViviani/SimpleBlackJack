#include "Card.h"
#include <string>

Card::Card() {
    this->suit = clubs;
    this->type = NUMERIC;
    this->value = 0;
    this->suit_ch = "";
    this->type_name = "";
}

Card::Card(Suit suit, CardType type, int val) {

    this->suit  = suit;
    this->type  = type;
    this->value = val;

    switch (suit) {
        case hearts:
            this->suit_ch = "♥";
            break;
        case clubs:
            this->suit_ch = "♣";
            break;
        case diamonds:
            this->suit_ch = "♦";
            break;
        case spades:
            this->suit_ch = "♠";
            break;
    }

    switch(type) {
        case ACE:
            this->type_name = "ace";
            break;
        case KING:
            this->type_name = "king";
            break;
        case QUEEN:
            this->type_name = "queen";
            break;
        case JACK:
            this->type_name = "jack";
            break;
    }

}

int Card::get_value() const {
    return this->value;
}

std::ostream& operator<< (std::ostream& out, const Card& card) {

    if (card.type == NUMERIC) {
        out << "[" << card.value << card.suit_ch << "]";
    } else {
        out << "[" << card.type_name << card.suit_ch << "]";
    }
    return out;

}

