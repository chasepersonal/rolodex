// Card.cpp
//
// Author: Chase Weyer
// Date: 3/26/2016
//
// The following program will execute functions for
// the Card class, which involves getting, setting,
// and displaying information for a single contact.

#include "Card.h"

using namespace std;

//default ctor

Card::Card() {

    //will set variables to null

    mfName = "";
    mlName = "";
    mOccupation = "";
    mAddress = "";
    mPhoneNumber = "";

}

//copy ctor

Card::Card (const string& firstName, const string& lastName, const string& occupation, const string& address, const string& phonenumber) {

    //will set appropriate variables

    mfName = firstName;
    mlName = lastName;
    mOccupation = occupation;
    mAddress = address;
    mPhoneNumber = phonenumber;
}

//setter for firstName stream input

void Card::setFirstName(const string& firstName) {

    mfName = firstName;

}

//setter for lastName stream input

void Card::setLastName(const string& lastName) {

    mlName = lastName;

}

//setter for occupation stream input

void Card::setOccupation(const string& occupation) {

    mOccupation = occupation;
}

//setter for address stream input

void Card::setAddress(const string& address) {

    mAddress = address;

}

//setter for phonenumber stream input

void Card::setPhoneNumber(const string& phonenumber) {

    mPhoneNumber = phonenumber;

}

//getter for first name

string Card::getFirstName() const {

    return mfName;

}

//getter for last name

string Card::getLastName() const {

    return mlName;

}

//getter for occupation

string Card::getOccupation() const {

    return mOccupation;

}

//getter for address

string Card::getAddress() const {

    return mAddress;

}

//getter for phonenumber

string Card::getPhoneNumber() const {

    return mPhoneNumber;

}

//will print out stream of appropriate getters

void Card::show(ostream& os) {

    os << getFirstName() << " " << getLastName() << " " << getOccupation() << " " <<
        getAddress() << " " << getPhoneNumber() << " " << "\n";

}