#include "LinkedList.cpp"
#include "Card.h"

void create_deck(LinkedList<Card>& ls);


int main() {
    LinkedList<Card> deck;
    create_deck(deck);
    return 0;
}

void create_deck(LinkedList<Card>& ls) {
    for (int val = 6; val <= 10; ++val) {
        ls.push_back(Card(hearts, NUMERIC, val));
        ls.push_back(Card(clubs, NUMERIC, val));
        ls.push_back(Card(diamonds, NUMERIC, val));
        ls.push_back(Card(spades, NUMERIC, val));
    }

    for (int type = ACE; type != NUMERIC; ++type) {
        CardType card_type = static_cast<CardType>(type);

        int value = 10;
        value = card_type == ACE ? 11 : 10;

        ls.push_back(Card(hearts, card_type, value));
        ls.push_back(Card(clubs, card_type, value));
        ls.push_back(Card(diamonds, card_type, value));
        ls.push_back(Card(spades, card_type, value));
    }
}