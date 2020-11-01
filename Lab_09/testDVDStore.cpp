
//*************************************************************
// Author: D.S. Malik
// 
// This program uses the classes dvdType and dvdBinaryTree 
// to create a list of DVDs for a DVD store. It performs 
// basic operations such as check in and check out DVDs.
//*************************************************************
 
#include <iostream>
#include <fstream>
#include <string>
#include "binarySearchTree.h"
#include "voteCountType.h"
#include "VoteBinaryTree.h" 

using namespace std; 

void createDVDList(ifstream& infile, 
                   VoteBinaryTree& voteList);
void displayMenu();
 
int main()
{
    VoteBinaryTree  voteList;
    int choice;
    string id;

    ifstream infile;

    infile.open("states.txt");
    //infile.open("C:\\Users\\Mike\\Documents\\Blinn\\fall2020\\cosc2436\\examples\\ch19\\dvdDat.txt");

    if (!infile) {
        cout << "The input file does not exist. " 
             << "Program terminates!!"<< endl;
        return 1;
    }

    createDVDList(infile, voteList);
    infile.close();

    displayMenu();              //show the menu
    cout << "Enter your choice: ";		
    cin >> choice;              //get the request
    cin.ignore(100, '\n');      //ignore the remaining 
	                            //characters in the line
    cout << endl;

    while (choice != 9)
    {
        switch (choice)
        {
        case 1: 
            cout << "Enter the title: ";
            getline(cin, id);
            cout << endl;

            if (voteList.voteSearch(id))
                cout << "The store carries " << id << endl;
            else
                cout << "The store does not carry " << id
                     << endl;
            break;

        case 2: 
            cout << "Enter the title: ";
            getline(cin, id);
            cout << endl;

            if (voteList.voteSearch(id))
            {
                if (voteList.isVoteAvailable(id))
                {
                    voteList.voteCheckOut(id);
                    cout << "Enjoy your movie: " << id
                         << endl;
                }
                else
                    cout << "Currently " << id
                         << " is out of stock." << endl;
            }
            else
                cout << "The store does not carry " << id
                     << endl;
            break;

        case 3: 
            cout << "Enter the title: ";
            getline(cin, id);
            cout << endl;

            if (voteList.voteSearch(id))
            {
                voteList.voteCheckIn(id);
                cout << "Thanks for returning " << id
                     << endl;
            }
            else
                cout << "The store does not carry " << id
                     << endl;
            break;

        case 4: 
            cout << "Enter the title: ";
            getline(cin, id);
            cout << endl;

            if (voteList.voteSearch(id))
            {
                if (voteList.isVoteAvailable(id))
                    cout << id << " is currently in "
                         << "stock." << endl;
                else
                    cout << id << " is currently out "
                         << "of stock." << endl;
            }
            else
                cout << "The store does not carry " << id
                     << endl;
            break;

        case 5: 
            voteList.votePrintTitle();
            break;

        case 6: 
            voteList.inorderTraversal();
            break;

        default: cout << "Invalid selection." << endl;
        }//end switch

        displayMenu();          //display the menu
        cout << "Enter your choice: ";
        cin >> choice;          //get the next request
        cin.ignore(100, '\n');  //ignore the remaining 
                                //characters in the line
        cout << endl;
    }//end while

    return 0;
}

void createDVDList(ifstream& infile, VoteBinaryTree& voteList)
{
    string id;
    string state;
    int repVote;
    int demVote;
    int electoralVote; 

    voteCountType newVote;

    //getline(infile, id);

    while (infile) {
        getline(infile, id);
        getline(infile, state);
        infile >> electoralVote;
        infile.ignore(100, '\n');
        newVote.setVoterInfo(id, state, electoralVote, repVote, demVote);
        voteList.insert(newVote);

        //getline(infile, id);
    }
}

void displayMenu()
{
    cout << "Select one of the following:" << endl;
    cout << "1: To check whether the store carries a "
         << "particular DVD." << endl;
    cout << "2: To check out a DVD." << endl;
    cout << "3: To check in a DVD." << endl;
    cout << "4: To check whether a particular DVD is " 
         << "in stock." << endl;
    cout << "5: To print only the titles of all the DVDs."
         << endl;
    cout << "6: To print a list of all the DVDs." << endl;
    cout << "9: To exit" << endl;
}

