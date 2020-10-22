#ifndef H_voteCountType
#define H_voteCountType

#include <iostream>
#include <string>

using namespace std;

class voteCountType {
  public:
    void setVoterInfo(string stateID, string stateName, int eVoteAvailable,
                        int voteCountRpublican, int voteCountDemocrat);

    int getPopularVoteRepublican() const;
    int getPopularVoteDemocrat() const;

    // all the functions from the dvd store database
    /*void checkOut();
    void checkIn();
    int getNoOfCopiesInStock() const;
    void printTitle() const;
    void printInfo() const;
    bool checkTitle(string title);
    void updateInStock(int num);
    void setCopiesInStock(int num);
    string getTitle() const;
    dvdType();
    dvdType(string title, string star1, 
                      string star2, string producer, 
                      string director,
                      string productionCo, int setInStock);*/

        //Overload the relational operators
    bool operator==(const voteCountType& right) const;
    bool operator!=(const voteCountType& right) const;
    bool operator<(const voteCountType& right) const;
    bool operator<=(const voteCountType& right) const;
    bool operator>(const voteCountType& right) const;
    bool operator>=(const voteCountType& right) const;
    friend ostream& operator<<(ostream& osObject, const voteCountType& dvd);
  
  private:
    string stateID;
    string stateName;
    int    eVotes;
    int    popVR;
    int    popVD;
};

#endif
