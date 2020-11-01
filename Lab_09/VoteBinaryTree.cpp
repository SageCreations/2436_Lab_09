#include <iostream>
#include <string>
#include "VoteBinaryTree.h"

using namespace std;

bool VoteBinaryTree::isVoteAvailable(string title)
{
    bool found;
    nodeType<voteCountType> *location;

    searchVoteList(title, found, location);

    if (found)
        found = (location->info.getNoOfCopiesInStock() > 0);
    else
        found = false;

    return found;
}

void VoteBinaryTree::voteCheckIn(string title)
{
    bool found = false;
    nodeType<voteCountType> *location;

    searchVoteList(title, found, location);

    if (found)
        location->info.checkIn();
    else
        cout << "The store does not carry " << title
             << endl;
}

void VoteBinaryTree::voteCheckOut(string title)
{
    bool found = false;
    nodeType<voteCountType> *location;

    searchVoteList(title, found, location);

    if (found)
        location->info.checkOut();
    else
        cout << "The store does not carry " << title
             << endl;
}

bool VoteBinaryTree::voteCheckTitle(string title) const
{
    bool found = false;
    nodeType<voteCountType> *location;

    searchVoteList(title, found, location);

    return found;
}

void VoteBinaryTree::voteUpdateInStock(string title, int num)
{
    bool found = false;
    nodeType<voteCountType> *location;

    searchVoteList(title, found, location);

    if (found)
        location->info.updateDemVoteCount(num);
    else
        cout << "The store does not carry " << title
             << endl;
}

void VoteBinaryTree::voteSetCopiesInStock(string title,
                                        int num)
{
    bool found = false;
    nodeType<voteCountType> *location;

    searchVoteList(title, found, location);

    if (found)
        location->info.setElectoralVotesAvailable(num);
    else
        cout << "The store does not carry " << title
             << endl;
}

bool VoteBinaryTree::voteSearch(string title) {
    bool found = false;
    nodeType<voteCountType> *location;

    searchVoteList(title, found, location);

    return found;
}

void VoteBinaryTree::searchVoteList(string id, bool &found, nodeType<voteCountType> *&current) const
{
    found = false;

    voteCountType temp;

    temp.setVoterInfo(id, "", 0, 0, 0);

    if (root == nullptr) { //tree is empty 
        cout << "Cannot search an empty list. " << endl;
    } else {
        current = root; //set current point to the root node of the binary tree
        found = false;  //set found to false

        while (current != nullptr && !found) //search the tree
            if (current->info == temp)       //item is found
                found = true;
            else if (current->info > temp)
                current = current->lLink;
            else
                current = current->rLink;
    }
}

void VoteBinaryTree::votePrintTitle() const {
    inorderTitle(root);
}

void VoteBinaryTree::inorderTitle(nodeType<voteCountType> *p) const {
    if (p != nullptr)
    {
        inorderTitle(p->lLink);
        p->info.printID();
        inorderTitle(p->rLink);
    }
}
