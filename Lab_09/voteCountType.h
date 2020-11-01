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
    void checkOut();
    void checkIn();
    int getNoOfCopiesInStock() const;
    void printID() const;
    void printInfo() const;
    bool checkID(string sID);
    void updateRepVoteCount(int num);
    void updateDemVoteCount(int num);
    void setElectoralVotesAvailable(int num);
    string getStateID() const;
    voteCountType();
    voteCountType(string stateID, string stateName, int eVoteAvailable,
                        int voteCountRpublican, int voteCountDemocrat);

        //Overload the relational operators
    bool operator==(const voteCountType& right) const;
    bool operator!=(const voteCountType& right) const;
    bool operator<(const voteCountType& right) const;
    bool operator<=(const voteCountType& right) const;
    bool operator>(const voteCountType& right) const;
    bool operator>=(const voteCountType& right) const;
    friend ostream& operator<<(ostream& osObject, const voteCountType& vote);
  
  private:
    string stateID;
    string stateName;
    int    eVotes;
    int    popVR;
    int    popVD;
};

#endif
