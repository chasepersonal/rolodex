// Card.h
//
// Author: Chase Weyer
// Date: 3/26/2016
//
// The following header will contain class functions
// and variables for use with the Card class, which
// will set and display information for a single
// contact within the container class, Rolodex.

#pragma once

#ifndef _CARD_H
#define _CARD_H

#include <string>
#include <ostream>
using std::string;
using std::ostream;

class Card {

private:

    //variable declarations

    std::string mfName;
    std::string mlName;
    std::string mOccupation;
    std::string mAddress;
    std::string mPhoneNumber;

public:

    //default ctor

    Card();

    //copy ctor

    Card(const std::string& firstName, const std::string& lastName, const std::string& occupation, const std::string& address, const std::string& phonenumber);
   
    void setFirstName(const string& firstName);         //prototype for setter of firstName variable
    void setLastName(const string& lastName);           //prototype for setter of lastName variable
    void setOccupation(const string& occupation);       //prototype for setter of occupation variable
    void setAddress(const string& address);             //prototype for setter of address variable
    void setPhoneNumber(const string& phonenumber);     //prototype for setter of phonenumber variable
    std::string getFirstName() const;                   //prototype for getter of first name
    std::string getLastName() const;                    //prototype for getter of last name
    std::string getOccupation() const;                  //prototype for getter of occupation 
    std::string getAddress() const;                     //prototype for getter of address 
    std::string getPhoneNumber() const;                 //prototype for getter of phonenumber
    void show(std::ostream& os);                        //prototype for printing out stream of appropriate getters


}; //end of Card class

#endif // !_CARD_H
