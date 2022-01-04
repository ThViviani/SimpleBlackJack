#include "LinkedList.cpp"
#include "Card.h"


void create_deck(LinkedList<Card>& ls);

void random_swap(int cur, Card& arr);

void shuffle_deck(LinkedList<Card>& deck);


int main() {

    LinkedList<Card> deck;
    create_deck(deck);
    shuffle_deck(deck);
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

void random_swap(int cur, Card arr[]) {

    Card tmp = arr[cur];
    int new_index = rand() % 36;
    arr[cur] = arr[new_index];
    arr[new_index] = tmp;

}

void shuffle_deck(LinkedList<Card>& deck) {

    Card arr[deck.size()];

    int arr_size = 0;
    while(!deck.empty()) {
        arr[arr_size++] = deck.front();
        deck.pop_front();
    }

    for (int i = 0; i < arr_size; ++i) {
        random_swap(i, arr);
    }

    for (int i = 0; i < arr_size; ++i) {
        deck.push_back(arr[i]);
    }

}