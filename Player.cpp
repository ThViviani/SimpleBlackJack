#include "Player.h"

Player::Player() {
    this->hand_summ = 0;
    this->score = 0;
    this->hand = LinkedList<Card>();
}

void Player::add_card(Card &card) {
    this->hand.push_back(card);
    this->hand_summ += card.get_value();
}