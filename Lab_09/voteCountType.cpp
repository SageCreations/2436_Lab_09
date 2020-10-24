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
    setVoterInfo("", "", 0, 0, 0);
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

ostream& operator<< (ostream& osObject, const voteCountType& dvd)
{
    osObject << endl;
    osObject << "  State ID: " << dvd.stateID << endl;
    osObject << "State Name: " << dvd.stateName << endl;
    osObject << "Electorial Votes Available: " << dvd.eVotes << endl;
    osObject << "Popular vote count (Republican): " << dvd.popVR << endl;
    osObject << "Popular vote count (Democrat): " << dvd.popVD << endl;
    osObject << "_____________________________________" << endl;

    return osObject;
}

// finished backend info----- move on to the next lvl up