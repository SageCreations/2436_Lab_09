#include<iostream>
#include <fstream>
#include <string>

#include "binarySearchTree.h"
#include "dvdBinaryTree.h"
#include "voteCountType.h"

using namespace std;

void createDVDList(ifstream& infile, dvdBinaryTree& dvdList);
void displayMenu();

int main() {
    dvdBinaryTree dvdList;
    int choice;
    string title;

    ifstream infile;

    infile.open("//home//mike//Documents//blinn//Fall2020//cosc2436//labs//lab09//states.txt");

    if (!infile) {
        cout << "The input file does not exist. "
             << "Program terminates!!" << endl;
        return 1;
    }

    createDVDList(infile, dvdList);
    infile.close();

    displayMenu();  // show the menu
    cout << "Enter your choice: ";
    cin >> choice;          // get the request
    cin.ignore(100, '\n');  // ignore the remaining
                            // characters in the line
    cout << endl;

    while (choice != 9) {
        switch (choice) {
            // case 1:
            //     cout << "Post new update to database: ";
            //     getline(cin, title);
            //     cout << endl;

            //     if (dvdList.dvdSearch(title))
            //         cout << "The store carries " << title << endl;
            //     else
            //         cout << "The store does not carry " << title << endl;
            //     break;

            case 1:
                cout << "Enter Message ( SSPXXXXX ): ";
                getline(cin, title);
                cout << endl;

                // if (dvdList.dvdSearch(title)) {
                //     if (dvdList.isDVDAvailable(title)) {
                //         dvdList.dvdCheckOut(title);
                //         cout << "Enjoy your movie: " << title << endl;
                //     } else
                //         cout << "Currently " << title << " is out of stock."
                //              << endl;
                // } else
                //     cout << "The store does not carry " << title << endl;
                break;

            case 3:
                //cout << "State ID: ";
                // getline(cin, title);
                // cout << endl;

                // if (dvdList.dvdSearch(title)) {
                //     dvdList.dvdCheckIn(title);
                //     cout << "Thanks for returning " << title << endl;
                // } else
                //     cout << "The store does not carry " << title << endl;
                break;

            case 4:
                cout << "Print who is winning the election: ";
                // getline(cin, title);
                // cout << endl;

                // if (dvdList.dvdSearch(title)) {
                //     if (dvdList.isDVDAvailable(title))
                //         cout << title << " is currently in "
                //              << "stock." << endl;
                //     else
                //         cout << title << " is currently out "
                //              << "of stock." << endl;
                // } else
                //     cout << "The store does not carry " << title << endl;
                break;

            // case 5:
            //     dvdList.dvdPrintTitle();
            //     break;

            // case 6:
            //     dvdList.inorderTraversal();
            //     break;

            default:
                cout << "Invalid selection." << endl;
        }

        displayMenu();  // display the menu
        cout << "Enter your choice: ";
        cin >> choice;          // get the next request
        cin.ignore(100, '\n');  // ignore the remaining characters in the line
        cout << endl;
    }

    return 0;
}

void createDVDList(ifstream& infile, dvdBinaryTree& dvdList) {
    string stateID;
    string stateName;
    int electorialVotes;

    voteCountType newDVD;

    getline(infile, stateID);

    while (infile) {
        getline(infile, stateName);
        infile >> electorialVotes;
        infile.ignore(100, '\n');
        newDVD.setDVDInfo(stateID, stateName, electorialVotes, 0, 0);
        dvdList.insert(newDVD);

        getline(infile, stateID);
    }
}

void displayMenu() {
    cout << "Select one of the following:" << endl;
    cout << "1: Post new update message to database" << endl;
    cout << "2: Print status of a state" << endl;
    cout << "3: Print all states and current status" << endl;
    cout << "4: Determine who is winning" << endl;
    cout << "9: To exit" << endl;
}
