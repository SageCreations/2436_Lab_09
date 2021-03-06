#include <iostream>
#include <string>
#include "voteCountType.h"

using namespace std;

void voteCountType::setVoterInfo(string ID, string sN, int eVoteAvailable,
                        int voteCountRpublican, int voteCountDemocrat)
{
    this->stateID = ID;
    this->stateName = sN;
    this->eVotes = eVoteAvailable;
    this->popVR = voteCountRpublican;
    this->popVD = voteCountDemocrat;
}

void voteCountType::checkOut()
{
    /*
    if (getNoOfCopiesInStock() > 0)
        copiesInStock--;
    else
        cout << "Currently out of stock." << endl;
    */
}

void voteCountType::checkIn()
{
    eVotes++;
}

int voteCountType::getNoOfCopiesInStock() const
{
    return eVotes;
}

void voteCountType::printID() const
{
    cout << "State ID: " << stateID << endl;
}

void voteCountType::printEVotes() const
{
    cout << "State Name: " << stateName << endl;
    cout << "Electoral Votes Available: " << eVotes << endl;
    cout << endl;
}

void voteCountType::printInfo() const
{
    cout << "State ID: " << stateID << endl;
    cout << "State Name: " << stateName << endl; 
    cout << "Electoral Votes Available: " << eVotes << endl;
    cout << "Popular vote count (Republican): " << popVR << endl;
    cout << "Popular vote count (Democrat): " << popVD << endl;
    cout << endl;
}

bool voteCountType::checkID(string sID)
{
    return(this->stateID == sID);
}

int voteCountType::getPopularVoteDemocrat() const
{
    return this->popVD;
}

int voteCountType::getPopularVoteRepublican() const
{
    return this->popVR;
}

void voteCountType::updateRepVoteCount(int num)
{
    popVR += num;
}
   
void voteCountType::updateDemVoteCount(int num)
{
    popVD += num;
}

void voteCountType::setElectoralVotesAvailable(int num)
{
    eVotes = num;
}

string voteCountType::getStateID() const
{
    return stateID;
}

voteCountType::voteCountType()
{
    stateID = "";
    stateName = "";
    eVotes = 0;
    popVR = 0;
    popVD = 0;
    setVoterInfo(stateID, stateName, eVotes, popVR, popVD);
}

voteCountType::voteCountType(string stateID, string stateName, int eVoteAvailable,
                        int voteCountRpublican, int voteCountDemocrat)
{
    setVoterInfo(stateID, stateName, eVoteAvailable, 
                    voteCountRpublican, voteCountDemocrat);
}

    //Overload the relational operators
bool voteCountType::operator==(const voteCountType& right) const
{
    return (this->stateID == right.stateID);
}

bool voteCountType::operator!=(const voteCountType& right) const
{
    return (this->stateID != right.stateID);
}

bool voteCountType::operator<(const voteCountType& right) const
{
    return (this->stateID < right.stateID);
}

bool voteCountType::operator<=(const voteCountType& right) const
{
    return (this->stateID <= right.stateID);
}

bool voteCountType::operator>(const voteCountType& right) const
{
    return (this->stateID > right.stateID);
}

bool voteCountType::operator>=(const voteCountType& right) const
{
    return (this->stateID >= right.stateID);
}

ostream& operator<< (ostream& osObject, const voteCountType& vote)
{
    osObject << endl;
    osObject << "  State ID: " << vote.stateID << endl;
    osObject << "State Name: " << vote.stateName << endl;
    osObject << "Electorial Votes Available: " << vote.eVotes << endl;
    osObject << "Popular vote count (Republican): " << vote.popVR << endl;
    osObject << "Popular vote count (Democrat): " << vote.popVD << endl;
    osObject << "_____________________________________" << endl;

    return osObject; 
}

// finished backend info----- move on to the next lvl up