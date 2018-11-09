//
// Created by Waseem Mehany on 11/7/18.
//

#include "card.h"


Card::Card() {
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s) {
    myRank = rank;
    mySuit = s;
};


// return string version e.g. Ac 4h Js
string Card::toString() const {
    string result = "";

    // RANK: A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K. (1-13)
    switch (myRank) {
        case 1:
            result+= "A";
            break;
        case 2:
            result+= "2";
            break;
        case 3:
            result+= "3";
            break;
        case 4:
            result+= "4";
            break;
        case 5:
            result+= "5";
            break;
        case 6:
            result+= "6";
            break;
        case 7:
            result+= "7";
            break;
        case 8:
            result+= "8";
            break;
        case 9:
            result+= "9";
            break;
        case 10:
            result+= "10";
            break;
        case 11:
            result+= "J";
            break;
        case 12:
            result+= "Q";
            break;
        case 13:
            result+= "K";
            break;
        default:
            break;
    }

    // SUITS: spades, hearts, diamonds, clubs
    switch (mySuit) {
        case spades:
            result+= "s";
            break;
        case hearts:
            result+= "h";
            break;
        case diamonds:
            result+= "d";
            break;
        case clubs:
            result+= "c";
            break;
        default:
            break;
    }


    return result;
}

// true if suit same as c
bool Card::sameSuitAs(const Card& c) const {
    cout << "mySuit: " << mySuit << endl;
    cout << "c.mySuit: " << c.mySuit << endl;
    if (mySuit == c.mySuit) {
        return true;
    } else {
        return false;
    }
}


// return rank, 1..13
int  Card::getRank() const {
    return myRank;
}

// return "s", "h",...
string Card::suitString(Suit s) const {
    string result = "";
    switch (s) {
        case spades:
            result+= "s";
            break;
        case hearts:
            result+= "h";
            break;
        case diamonds:
            result+= "d";
            break;
        case clubs:
            result+= "c";
            break;
        default:
            break;
    }
    return result;
}

// return "A", "2", ..."Q"
string Card::rankString(int r) const {
    string result = "";

    // RANK: A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K. (1-13)
    switch (r) {
        case 1:
            result+= "A";
            break;
        case 2:
            result+= "2";
            break;
        case 3:
            result+= "3";
            break;
        case 4:
            result+= "4";
            break;
        case 5:
            result+= "5";
            break;
        case 6:
            result+= "6";
            break;
        case 7:
            result+= "7";
            break;
        case 8:
            result+= "8";
            break;
        case 9:
            result+= "9";
            break;
        case 10:
            result+= "10";
            break;
        case 11:
            result+= "J";
            break;
        case 12:
            result+= "Q";
            break;
        case 13:
            result+= "K";
            break;
        default:
            break;
    }
    return result;
}


bool Card::operator == (const Card& rhs) const {
    return mySuit == rhs.mySuit && myRank == rhs.myRank ? true : false;
}

bool Card::operator != (const Card& rhs) const {
    return mySuit != rhs.mySuit || myRank != rhs.myRank ? true : false;
}