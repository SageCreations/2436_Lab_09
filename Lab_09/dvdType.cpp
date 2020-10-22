#include <iostream>
#include <string>
#include "voteCountType.h"

using namespace std;

void voteCountType::setVoterInfo(string ID, string sN, int eVoteAvailable,
                        int voteCountRpublican, int voteCountDemocrat)
{
    stateID = ID;
    stateName = sN;
    eVotes = eVoteAvailable;
    popVR = voteCountRpublican;
    popVD = voteCountDemocrat;
}
// TODO: this is where i left off.
void dvdType::checkOut()
{
    if (getNoOfCopiesInStock() > 0)
        copiesInStock--;
    else
        cout << "Currently out of stock." << endl;
}

void dvdType::checkIn()
{
    copiesInStock++;
}

int dvdType::getNoOfCopiesInStock() const
{
    return copiesInStock;
}

void dvdType::printTitle() const
{
    cout << "DVD Title: " << dvdTitle << endl;
}

void dvdType::printInfo() const
{
    cout << "DVD Title: " << dvdTitle << endl;
    cout << "Stars: " << movieStar1 << " and " 
         << movieStar2 << endl;
    cout << "Producer: " << movieProducer << endl;
    cout << "Director: " << movieDirector << endl;
    cout << "Production Company: " << movieProductionCo
         << endl;
    cout << "Copies in stock: " << copiesInStock
         << endl;
}

bool dvdType::checkTitle(string title)
{
    return(dvdTitle == title);
}

void dvdType::updateInStock(int num)
{
    copiesInStock += num;
}

void dvdType::setCopiesInStock(int num)
{
    copiesInStock = num;
}

string dvdType::getTitle() const
{
    return dvdTitle;
}

dvdType::dvdType()
{
    setDVDInfo("", "", "", "", "", "", 0);
}

dvdType::dvdType(string title, string star1, 
                     string star2, string producer, 
                     string director,
                     string productionCo, int setInStock)
{
    setDVDInfo(title, star1, star2, producer, director,
                 productionCo, setInStock);
}

    //Overload the relational operators
bool dvdType::operator==(const dvdType& right) const
{
    return (dvdTitle == right.dvdTitle);
}

bool dvdType::operator!=(const dvdType& right) const
{
    return (dvdTitle != right.dvdTitle);
}

bool dvdType::operator<(const dvdType& right) const
{
    return (dvdTitle < right.dvdTitle);
}

bool dvdType::operator<=(const dvdType& right) const
{
    return (dvdTitle <= right.dvdTitle);
}

bool dvdType::operator>(const dvdType& right) const
{
    return (dvdTitle > right.dvdTitle);
}

bool dvdType::operator>=(const dvdType& right) const
{
    return (dvdTitle >= right.dvdTitle);
}

ostream& operator<< (ostream& osObject, const dvdType& dvd)
{
    osObject << endl;
    osObject << "DVD Title: " << dvd.dvdTitle << endl;
    osObject << "Stars: " << dvd.movieStar1 << " and "
         << dvd.movieStar2 << endl;
    osObject << "Producer: " << dvd.movieProducer << endl;
    osObject << "Director: " << dvd.movieDirector << endl;
    osObject << "Production Company: "
             << dvd.movieProductionCo << endl;
    osObject << "Copies in stock: " << dvd.copiesInStock 
             << endl;
    osObject << "_____________________________________" 
             << endl;

    return osObject;
}


