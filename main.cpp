// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( ) {
    int numCards = 5;
    Player p1("Joe");
    Player p2("Jane");

    // Set up game
    Deck d;
    d.shuffle();
    dealHand(d, p1, numCards);
    cout << p1.getName() <<" has: " << p1.showHand() << endl;
    dealHand(d, p2, numCards);
    cout << p2.getName() <<" has: " << p2.showHand() << endl;


    int playerCounter = 0;
    while ((p1.getBookSize() + p2.getBookSize()) / 2 != 26) {
        // Player 1
        if (playerCounter == 0) {
            // already existing pairs
            Card* card1 = new Card();
            Card* card2 = new Card();
            bool successful = p1.checkHandForBook(*card1, *card2);
            if (successful){
                p1.bookCards(*card1, *card2);
//                cout << p1.getName() <<"'s new book: " << p1.showBooks() << endl;
//                cout << p1.getName() <<"'s new hand: " << p1.showHand() << endl;
//                cout << endl;
            }


            if (d.size() != 0 && p1.getHandSize()) {
                Card c;
                c = p1.chooseCardFromHand();
                cout << p1.getName() <<"'s hand: " << p1.showHand() << endl;
                cout << p1.getName() <<" asks: do you have a " << c.getRank() << "?" << endl;

                if (p2.getHandSize() != 0 && p2.rankInHand(c)) {
                    Card c2;
                    c2 = p2.findMatchingCard(c.getRank());
                    p2.removeCardFromHand(c2);
                    p1.bookCards(c, c2);
                    cout << p2.getName() <<": yes" << endl;
                    cout << p1.getName() <<"'s hand: " << p1.showHand() << endl;
                    cout << p1.getName() <<"'s book: " << p1.showBooks() << endl;
                    cout << endl;
                } else {
                    cout << p2.getName() <<" says: Go fish" << endl;
                    Card goFish = d.dealCard();
                    p1.addCard(goFish);
                    cout << p1.getName() <<" drew " << goFish.toString() << endl;
                    cout << endl;
                }
            }

            playerCounter = 1;
        }
        // Player 2
        if (playerCounter == 1) {
            // already existing pairs
            Card* card1 = new Card();
            Card* card2 = new Card();
            bool successful = p2.checkHandForBook(*card1, *card2);
            if (successful){
                p2.bookCards(*card1, *card2);
//                cout << p2.getName() <<"'s new book: " << p2.showBooks() << endl;
//                cout << p2.getName() <<"'s new hand: " << p2.showHand() << endl;
//                cout << endl;
            }


            if (d.size() != 0 && p2.getHandSize()) {
                Card c;
                c = p2.chooseCardFromHand();
                cout << p2.getName() <<"'s hand: " << p2.showHand() << endl;
                cout << p2.getName() <<" asks: do you have a " << c.getRank() << "?" << endl;


                if (p1.getHandSize() != 0 && p1.rankInHand(c)) {
                    Card c2;
                    c2 = p1.findMatchingCard(c.getRank());
                    p1.removeCardFromHand(c2);
                    p2.bookCards(c, c2);
                    cout << p1.getName() <<": yes" << endl;
                    cout << p2.getName() <<"'s hand: " << p2.showHand() << endl;
                    cout << p2.getName() <<"'s book: " << p2.showBooks() << endl;
                    cout << endl;
                } else {
                    cout << p1.getName() <<" says: Go fish" << endl;
                    Card goFish = d.dealCard();
                    p2.addCard(goFish);
                    cout << p2.getName() <<" drew " << goFish.toString() << endl;
                    cout << endl;
                }
            }



            playerCounter = 0;
        }
    }




    cout << p1.getName() <<"'s hand: " << p1.showHand() << endl;
    cout << p1.getName() <<"'s book: " << p1.showBooks() << endl;

    cout << p2.getName() <<"'s hand: " << p2.showHand() << endl;
    cout << p2.getName() <<"'s book: " << p2.showBooks() << endl;

    if (p1.getBookSize() > p2.getBookSize()) {
        cout << p1.getName() << " WON!" << endl;
    } else if (p1.getBookSize() < p2.getBookSize()) {
        cout << p2.getName() << " WON!" << endl;
    } else {
        cout << "DRAW!" << endl;
    }



//    while (p1.getHandSize() != 0 && p2.getHandSize() != 0 &&  d.size() > 0) {
//
//    }


//    cout << p1.getName() <<" has : " << p1.showHand() << endl;
//    cout << p2.getName() <<" has : " << p2.showHand() << endl;
//
//    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
