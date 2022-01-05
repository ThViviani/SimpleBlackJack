#include "Deck.h"
#include <stdlib.h>
#include <time.h>

void random_swap(int cur, Card arr[]) {

    Card tmp = arr[cur];
    int new_index = rand() % 52;
    arr[cur] = arr[new_index];
    arr[new_index] = tmp;

}

void Deck::create_deck() {

    for (int val = 2; val <= 10; ++val) {
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

Deck::Deck() {
    create_deck();
}

void Deck::shuffle() {

    Card arr[ls.size()];

    int arr_size = 0;
    while(!ls.empty()) {
        arr[arr_size++] = ls.front();
        ls.pop_front();
    }

    srand(time(0));
    for (int i = 0; i < arr_size; ++i) {
        random_swap(i, arr);
    }

    for (int i = 0; i < arr_size; ++i) {
        ls.push_back(arr[i]);
    }

}

Card Deck::get_card() {

    Card tmp = this->ls.front();
    this->ls.pop_front();
    return tmp;

}