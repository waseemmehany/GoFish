//
// Created by Waseem Mehany on 11/7/18.
//

#include "deck.h"


// pristine, sorted deck
Deck::Deck() {
    // ORDER: spades, hearts, diamonds, clubs
    for (int i = 0; i < 52; i++) {
        if (i < 13) {
            myCards[i] = Card(i+1, Card::spades);
        } else if (i >= 13 && i < 26) {
            myCards[i] = Card(i-12, Card::hearts);
        } else if (i >= 26 && i < 39) {
            myCards[i] = Card(i-25, Card::diamonds);
        } else if (i >= 39 && i < 52) {
            myCards[i] = Card(i-38, Card::clubs);
        }
    }

    // current card to deal
    myIndex = 51;
}


// shuffle the cards in the current deck
void Deck::shuffle() {
    for (int i = 0; i < 52; i++) {
        int random = rand() % 52;
        Card c = myCards[i];
        myCards[i] = myCards[random];
        myCards[random] = c;
    }
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
