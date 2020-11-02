
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
#include <sstream>
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
    string encodedMessage;
    int votes;
    string party;
    string popV;
    stringstream number();

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
            voteList.votePrintTitle();
            break;

        case 2:  
            voteList.getRepVotes();
            break;

        case 3: 
            voteList.getDemVotes();
            break;

        case 4: 
            voteList.getEVotes();
            break;

        case 5: 
            cout << "\nSSPXXXXXXXX where SS = State ID, P = Party,"
                    << " XX... is the popular vote count." << endl;
            getline(cin, encodedMessage);
            cout << endl;
            id = encodedMessage.substr(0, 2);
            party = encodedMessage.substr(2, 1);
            votes = stoi(encodedMessage.substr(3));
            
            if (voteList.voteSearch(id))
            {
                if (voteList.isVoteAvailable(id)) {
                    voteList.voteUpdateInStock(id, party, votes);
                } else {
                    cout << id << "This vote has already been updated" << endl;
                }
            }
            else {
                cout << "This id does not exist." << id
                     << endl;
            }
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
    int repVote = 0;
    int demVote= 0;
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
    
    /*cout << "1: To check whether the store carries a "
         << "particular DVD." << endl;
    cout << "2: To check out a DVD." << endl;
    cout << "3: To check in a DVD." << endl;
    cout << "4: To check whether a particular DVD is " 
         << "in stock." << endl;
    cout << "5: To print only the titles of all the DVDs."
         << endl;
    cout << "6: To print a list of all the DVDs." << endl;
    */

    cout << "1: Check what the state IDs' are" << endl;
    cout << "2: Check how many popular votes Republicans "
                    << "have nation wide." << endl;
    cout << "3: Check how many popular votes "
                    << "Democrats have nation wide." << endl;
    cout << "4: Check how many electoral votes "
                    << "a state has." << endl;
    cout << "5: Update the popular vote count." << endl;
    cout << "6: List all info on each state." << endl;
    cout << "9: To exit" << endl;
}

