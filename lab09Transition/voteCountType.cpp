#include <iostream>
#include <string>
#include "voteCountType.h"

using namespace std;

void voteCountType::setDVDInfo(string stateID, string stateName,
                    int eVoteAvailable, int voteCountRepublican, int voteCountDemocrat) {
    this->stateID = stateID;
    this->stateName = stateName;
    this->electorialVotes = eVoteAvailable;
    this->popularVotesRepublican = voteCountRepublican;
    this->popularVotesDemocrat = voteCountDemocrat;
}

void voteCountType::checkOut()
{
    // if (getNoOfCopiesInStock() > 0)
    //     electorialVotes--;
    // else
    //     cout << "Currently out of stock." << endl;
}

void voteCountType::checkIn()
{
    electorialVotes++;
}

int voteCountType::getNoOfCopiesInStock() const
{
    return electorialVotes;
}

int voteCountType::getPopularVoteRepublican() const {
    return this->popularVotesRepublican;
}

int voteCountType::getPopularVoteDemocrat() const {
    return this->popularVotesDemocrat;
}

void voteCountType::printTitle() const
{
    cout << "DVD Title: " << stateID << endl;
}

void voteCountType::printInfo() const
{
    cout << "State ID: " << stateID << endl;
    cout << "Stars: " << stateName << endl;
    // cout << "Producer: " << movieProducer << endl;
    // cout << "Director: " << movieDirector << endl;
    // cout << "Production Company: " << movieProductionCo
    //      << endl;
    cout << "Electorial Votes Available: " << electorialVotes << endl;
    cout << "Popular vote count (Republican): " << popularVotesRepublican << endl;
    cout << "Popular vote count (Democrat): " << popularVotesDemocrat << endl;
}

bool voteCountType::checkTitle(string title)
{
    return(this->stateID == stateID);
}

void voteCountType::updateInStock(int num)
{
    // electorialVotes += num;
}

void voteCountType::setCopiesInStock(int num)
{
    electorialVotes = num;
}

string voteCountType::getTitle() const
{
    return stateID;
}

voteCountType::voteCountType(string stateID, string stateName, int eVotesAvailable, int voteCountRepublican, int voteCountDemocrat) {
    setDVDInfo(stateID, stateName, eVotesAvailable, voteCountRepublican, voteCountDemocrat);
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
    osObject << "Copies in stock: " << dvd.electorialVotes << endl;
    osObject << "Electorial Votes Available: " << dvd.electorialVotes << endl;
    osObject << "Popular vote count (Republican): " << dvd.popularVotesRepublican << endl;
    osObject << "Popular vote count (Democrat): " << dvd.popularVotesDemocrat << endl;
    osObject << "_____________________________________" << endl;

    return osObject;
}


