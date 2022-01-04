#include "Deck.h"


int main() {

    Deck deck;
    deck.shuffle();
    Card current_card = deck.get_card();
    return 0;

}