//
// Created by Waseem Mehany on 11/7/18.
//

#include "deck.h"


// pristine, sorted deck
Deck::Deck() {
    // ORDER: spades, hearts, diamonds, clubs
    for (int i = 0; i < 13; i++) {
        myCards[i] = Card(i+1, Card::spades);
    }
    for (int i = 0; i < 13; i++) {
        myCards[i] = Card(i+1, Card::hearts);
    }
    for (int i = 0; i < 13; i++) {
        myCards[i] = Card(i+1, Card::diamonds);
    }
    for (int i = 0; i < 13; i++) {
        myCards[i] = Card(i+1, Card::clubs);
    }

    // current card to deal
    myIndex = 51;
}


// shuffle the cards in the current deck
void Deck::shuffle() {

}


// get a card, after 52 are dealt, fail
Card Deck::dealCard() {
    Card deal = myCards[myIndex];
    myIndex--;
    return deal;
}



// # cards left in the deck
int  Deck::size() const {
    return (myIndex + 1);
}
