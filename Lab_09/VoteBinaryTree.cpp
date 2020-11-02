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

void VoteBinaryTree::voteUpdateInStock(string title, string party, int num)
{
    bool found = false;
    nodeType<voteCountType> *count;

    searchVoteList(title, found, count);

    if (found) {
        if (party == "D") {
            count->info.updateDemVoteCount(num);
        } else if (party == "R") {
            count->info.updateRepVoteCount(num);
        } else {
            cout << "This message doesnt correspond to either party." << endl;
        }
        
    } else {
        cout << "there was an error in the id." << endl;
    }
}

void VoteBinaryTree::voteSetCopiesInStock(string title, int num)
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

bool VoteBinaryTree::voteSearch(string id) {
    bool found = false;
    nodeType<voteCountType> *location;

    searchVoteList(id, found, location);

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

void VoteBinaryTree::getEVotes() const
{
    inorderEVotes(root);
}

void VoteBinaryTree::getRepVotes() const {
    int count = 0;
    countTotalRepVotes(root, count);
    cout << "Popular Republican Votes nation wide at: " << count << endl;
    cout << endl;
}

void VoteBinaryTree::getDemVotes() const {
    int count = 0;
    countTotalDemVotes(root, count);
    cout << "Popular Democrat Votes nation wide at: " << count << endl;
    cout << endl;
}

int VoteBinaryTree::countTotalRepVotes(nodeType<voteCountType> *p, int &count) const
{
    if (p != nullptr)
    {
        countTotalRepVotes(p->lLink, count);
        count += p->info.getPopularVoteRepublican();
        countTotalRepVotes(p->rLink, count);
    }
    return count;
}

int VoteBinaryTree::countTotalDemVotes(nodeType<voteCountType> *p, int &count) const
{
    if (p != nullptr)
    {
        countTotalDemVotes(p->lLink, count);
        count += p->info.getPopularVoteDemocrat();
        countTotalDemVotes(p->rLink, count);
    }
    return count;
}

void VoteBinaryTree::inorderEVotes(nodeType<voteCountType> *p) const {
    if (p != nullptr)
    {
        inorderEVotes(p->lLink);
        p->info.printEVotes();
        inorderEVotes(p->rLink);
    }
}

void VoteBinaryTree::inorderTitle(nodeType<voteCountType> *p) const {
    if (p != nullptr)
    {
        inorderTitle(p->lLink);
        p->info.printID();
        inorderTitle(p->rLink);
    }
}
