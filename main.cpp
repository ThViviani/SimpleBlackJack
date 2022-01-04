#include "Deck.h"
#include "Player.h"

int main() {

    Deck deck;
    deck.shuffle();
    Player player, diller;
    Card top_deck = deck.get_card();
    player.add_card(top_deck);
    return 0;

}