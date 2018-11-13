//
// Created by Waseem Mehany on 11/7/18.
//

#include "player.h"

Player::Player() {
    myName = "";
}

//adds a card to the hand
void Player::addCard(Card c) {
    myHand.push_back(c);
}


void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);

    for (int i = 0; i < myBook.size(); i++) {
        for (int j = 0; j < myHand.size(); j++) {
            if (myBook.at(i) == myHand.at(j)) {
                myHand.erase(myHand.begin() + j);
            }
        }
    }
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
bool Player::checkHandForBook(Card &c1, Card &c2) {

    for (int i = 0; i < myHand.size(); i++) {
        for (int j = i+1; j < myHand.size(); j++) {
            if (myHand.at(i) == myHand.at(j)) {
                return true;
            }
        }
    }
    return false;
}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const {
    for (int i = 0; i < myHand.size(); i++) {
        if (myBook.at(i).getRank() == c.getRank()) {
            return true;
        }
    }
    return false;
}

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
// Chooses the first one
Card Player::chooseCardFromHand() const {
    Card c = myHand.at(0);
    return c;
}

//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const {
    for (int i = 0; i < myHand.size(); i++) {
        if (myBook.at(i) == c) {
            return true;
        }
    }
    return false;
}

//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c) {
    for (int i = 0; i < myHand.size(); i++) {
        if (myHand.at(i) == c) {
            Card removedCard = myHand.at(i);
            myHand.erase(myHand.begin() + i);
            return removedCard;
        }
    }

    return c;
}

string Player::showHand() const {
    string result;
    for(int i = 0; i < myHand.size(); i++) {
        if (i > 0) {
            result+= ", ";
        }
        result+= myHand.at(i).toString();
    }
    return result;
}
string Player::showBooks() const {
    string result;
    for(int i = 0; i < myBook.size(); i++) {
        if (i > 0) {
            result+= ", ";
        }
        result+= myBook.at(i).toString();
    }
    return result;
}

int Player::getHandSize() const {
    return (int)myHand.size();
}
int Player::getBookSize() const {
    return (int)myBook.size();
}
