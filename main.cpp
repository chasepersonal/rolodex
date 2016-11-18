// main.cpp
//
// Author: Chase Weyer
// Date: 3/26/2016
//
// The following main program will execute functions
// in conjuction with the Card and Rolodex classes.
// It will handle stream input for addition of a contact
// and removal of a contact as well as listing all contacts
// within the list, showing the next
// contact, and termination of the program.

#include "Rolodex.h"
#include <iostream>

using namespace std;

//function to show list of all contacts

void listRolo(Rolodex &info) {

    //header for contact list

    cout << "\nThe following are all of the contacts currently in the Rolodex: \n" << endl;
    cout << "First Name" << " | " << "Last Name" << " | " << "Occupation" << " | " <<
        "Address" << " | " << "Phone Number \n" << endl;

    //object call to display all contacts

    info.Rolodex::show(cout);

}

//function to show current contact

void view(Rolodex &info) {

    //current iterator will be returned with contact information

    cout << "\nThe current contact being viewed is: " << endl;
    info.Rolodex::getCurrentCard().Card::show(cout);

}

//function to show next contact

void flip(Rolodex &info) {

    //after flip, contact information for next contact will be shown

    cout << "\nThe next contact is being viewed: " << endl;
    info.Rolodex::flip().Card::show(cout);

}

//function to add contact to list with stream input

void add(Rolodex &info) {

    //stream variable declaration

    string lastName;
    string firstName;
    string occupation;
    string address;
    string phonenumber;

    //input message

    cout << "\nA new contact will be added!" << endl;
    cout << "Please enter the following information: \n" << endl;

    //each input will have a header to indicate
    //what information needs to be added

    cout << "First Name: " << endl;
    cin >> firstName;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //will ignore newline to clear buffer

    cout << "Last Name: " << endl;
    cin >> lastName;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Occupation: " << endl;
    getline(cin, occupation);

    cout << "Address: " << endl;
    getline(cin, address);

    cout << "Phone Number: " << endl;
    getline(cin, phonenumber);

    //object declaration

    Card newCard;

    //setters will be called to store stream input values

    newCard.setFirstName(firstName);
    newCard.setLastName(lastName);
    newCard.setOccupation(occupation);
    newCard.setAddress(address);
    newCard.setPhoneNumber(phonenumber);

    //new contact will be added to the list

    info.Rolodex::add(newCard);

}

//function to remove a contact

void remove(Rolodex &info) {

    //variable for stream input

    string answer;
    
    //warning message will display to ask user if they
    //would like to remove the contact

    //current contact will also be shown

    cout << "\nDo you wish to remove the following contact?" << endl;
    info.Rolodex::getCurrentCard().Card::show(cout);
    cin >> answer;

    //contact will be removed depending on the stream input

    if (answer == "yes" || answer == "y") {

        info.Rolodex::remove();

    }

}

//function for searching for a contact

void searchCard(Rolodex &info) {

    //stream input variables

    string lastName;
    string firstName;

    cout << "\nEnter the First and Last Name of the contact you wish to search for" << endl;

    //stream input for first and last name of contact to be searched

    cout << "First Name: " << endl;
    cin >> firstName;

    cout << "Last Name: " << endl;
    cin >> lastName;

    //will return inforamtion as long as a first and last name was inputted

    if (info.Rolodex::search(lastName, firstName)) {

        //will return information depeding on criteria set by Rolodex::search

        cout << "\nThe following search has returned this contact: " << endl;
        info.Rolodex::getCurrentCard().Card::show(cout);

    }

}

//function to exit the program

int quit() {

    //messages will display indicating the program is terminating

    cout << "\nThank you for using the Rolodex!" << endl;
    cout << "Now exiting the program." << endl;
    return 0;
}

//main function

void main() {

    //object variable

    Rolodex test;

    //preset contacts for testing purposes

    test.add(Card("Tony", "Hansen", "Writer", "12 E. St. NY, NY 33333", "555-9999"));
    test.add(Card("Jon", "Smyth", "Computer Hardware", "CMU Computer Services Pittsburgh, PA", "555-1324"));
    test.add(Card("Alonza", "Heard", "Mechanic", "123 Anyplace Ave Malden, MA", "555-5678"));
    test.add(Card("Jen", "Reyes", "Graphic artist", "325 Oak Rd Wilmington, MA", "555-4950"));
    test.add(Card("Alan", "Lupine", "Vet", "1 Bigelow Ave. Lawrence, MA", "555-7654"));
    test.add(Card("Jewel", "Proverb", "Landscaper", "34 Washington St. Waltham, MA", "555-3333"));
    test.add(Card("Paul", "Revere", "Radical Revolutionary", "45 Commonwealth Ave. Boston, MA", "555-1776"));
    test.add(Card("Adolf", "Coors", "Beer Manufacturer", "Boston MA", "555-2337"));
    test.add(Card("Seymour", "Papert", "Lego Professor", "MIT", "555-1111"));
    test.add(Card("Fred", "Milton", "Sales", "12 Freedom Way Nashua, NH", "555-9981"));

    //function calls for testing purposes

    listRolo(test);
    searchCard(test);
    view(test);
    flip(test);
    searchCard(test);
    view(test);
    remove(test);
    view(test);
    add(test);
    view(test);
    flip(test);
    remove(test);
    view(test);
    add(test);
    view(test);
    searchCard(test);
    view(test);
    remove(test);
    view(test);
    add(test);
    add(test);
    listRolo(test);

    quit();

}//end main
