// Rolodex.h
//
// Author: Chase Weyer
// Date: 3/26/2016
//
// The following header will contain class functions
// and variables for use with the container class, Rolodex.
// It will also set up a list container and iterator for use with
// the class functions and variables.

#pragma once

#ifndef _ROLODEX_H
#define _ROLODEX_H

#include "Card.h"
#include <list>
#include <iterator>

using std::list;
using std::iterator;

class Rolodex {

public:

    void add(const Card& card);                                     //prototype for adding a card
    void remove();                                                  //prototype for removing a card
    Card getCurrentCard();                                          //prototype for getting current card
    Card flip();                                                    //prototype for advancing to the next card
    bool search(const string& lastName, const string& firstName);   //prototype for name search
    void show(ostream& os);                                         //prototype for printing card information

private:
    std::list<Card> rolodex;                                        //list object
    std::list<Card>::iterator currentCard;                          //list iterator

}; //end of Rolodex class

#endif // !_ROLODEX_H

