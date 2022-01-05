#include "Player.h"

Player::Player() {
    this->hand_summ = 0;
    this->score = 0;
    this->hand = LinkedList<Card>();
}

void Player::add_card(const Card& card) {
    this->hand.push_back(card);
    this->hand_summ += card.get_value();
}

int Player::get_hand_sum() const {
    return this->hand_summ;
}

void Player::print_hand() const {
    this->hand.print_list();
}

Card Player::get_last_card() const{
    return this->hand.front();
}

void Player::new_game() {

    this->hand_summ = 0;
    this->score = 0;
    this->hand.clear();

}
