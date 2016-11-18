// Rolodex.cpp
//
// Author: Chase Weyer
// Date: 3/26/2016
//
// The following program will execute functions for
// the container class, Rolodex. It will involve
// establishing conditions for addition of a
// contact, removal of a contact, viewing the
// next contact, searching for a contact, and
// viewing contact information.

#include "Rolodex.h"
#include <algorithm>
#include <iostream>

using namespace std;

//inline function for sorting contact names

bool sortName(const Card& lhs, const Card& rhs) {

    //will sort by appropriate last name


    if (lhs.getLastName() != rhs.getLastName()) {

        return lhs.getLastName() < rhs.getLastName();
    }

    //if last names are the same, search will then be
    //sorted by the frist name

    else {

        if (lhs.getFirstName() != rhs.getFirstName()) {

            return lhs.getFirstName() < rhs.getFirstName();

        }

        //if the first names are the same, search will then
        //be sorted by the occupation

        else {

            return lhs.getOccupation() < rhs.getOccupation();
        }

    }
}

//overriden equality operator for find function

bool operator== (const Card &lhs, const Card &rhs) {

    //operator will return equals for find function
    //as long as all the following values are equal

    return lhs.getLastName() == rhs.getLastName();
    return lhs.getFirstName() == rhs.getFirstName();
    return lhs.getAddress() == rhs.getAddress();
    return lhs.getOccupation() == rhs.getOccupation();
    return lhs.getPhoneNumber() == rhs.getPhoneNumber();

}

//function will add a contact card to the Rolodex

void Rolodex::add(const Card& card) {

    //if rolodex is emtpy, card will just be added

    if (rolodex.empty()) {

        currentCard = rolodex.begin();
        rolodex.push_back(card);

    }

    //if rolodex is not empty, card will be added,
    //then the contacts will be sorted, and 
    //the iterator will be set to the card just added

    else {

        currentCard = rolodex.begin();
        rolodex.push_back(card);
        rolodex.sort(sortName);
        currentCard = find(rolodex.begin(), rolodex.end(), card);
    }
}

//function to remove a card from the rolodex

void Rolodex::remove() {

    //current iterator will be erased
    //iterator will then be moved to the next contact

    rolodex.erase(currentCard++);

    //if the end of the rolodex has been reached,
    //the iterator will be set to the first contact

    if (currentCard == rolodex.end()) {

        currentCard = rolodex.begin();
    }

}

//function to return the current card

Card Rolodex::getCurrentCard() {

    //pointer to iterator will return
    //current contact information

    return *currentCard;

}

Card Rolodex::flip() {

    //iterator will be moved to the next contact

    currentCard++;

    //if the iterator is at the last contact,
    //the first contact will be showed

    if (currentCard == rolodex.end()) {

        currentCard = rolodex.begin();
    }

    //pointer to iterator will return
    //current contact information

    return *currentCard;

}

//function to search for a contact using first and last name

bool Rolodex::search(const string& lastName, const string& firstName) {

    //temp iterator will be created

    list<Card>::iterator tempCard = currentCard;

    //iterator will be set to the first contact

    currentCard = rolodex.begin();

    //iterator will cycle through contacts to find the appropriate
    //last name. If none are found, the next best match will be
    //presented. If the iterator is at the last contact, search
    //will come back false and return the current iterator

    while (currentCard != rolodex.end()) {

        //first and last name stream inputs will be compared with contacts currently in the list
        //if an appropriate match is found, the search will return the contact in question.

        if (!currentCard->getLastName().compare(lastName) && !currentCard->getFirstName().compare(firstName)) {

            return true;
        }

        //if contact is not found, the next best match will be presented
        //Next best match will be the next closest alphabetically

        else {

            //loop will go through each element of the list to find next best match

            for (int i = 0; i < rolodex.size(); i++) {

                //variables will be set to find character positions within the strings
                
                //depending on the characters within the list and input, next best match will be displayed

                char list = currentCard->getLastName().at(i);
                char input = lastName.at(i);

                //if the character location of the iterator card is greater than
                //the character location of the stream input, then the search will return 
                //a true value

                if (list > input) {

                    return true;
                }

                //if the character location of the iterator card is less then the
                //character location of the stream input, then the loop will break

                else if (list < input) {

                    break;
                }
            }

            //current iterator will be moved to the next card

            currentCard++;

        }

    }

    //current iterator will be set to temp value

    currentCard = tempCard;

    //message will print for no match found, then a false value will be returned

    cout << "\nUnable to find matching name. Will display current contact: " << endl;
    return false;

}

//function to display contact information

void Rolodex::show(ostream& os) {

    //iterator will loop through current list

    for (currentCard = rolodex.begin(); currentCard != rolodex.end(); currentCard++) {

        //iterator will point to the Card::show function
        //and display the current contacts information

        currentCard->Card::show(os);

    }

}





