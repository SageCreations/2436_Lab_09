#ifndef H_voteCountType
#define H_voteCountType

#include <iostream>
#include <string>

using namespace std;

class voteCountType {
    friend ostream& operator<<(ostream&, const voteCountType&);

   public:
    // void setDVDInfo(string stateID, string stateName,
    //                 string star2, string producer,
    //                 string director, string productionCo,
    //                 int setInStock);

    void setDVDInfo(string stateID, string stateName, int eVoteAvailable,
                    int voteCountRepublican, int voteCountDemocrat);

    int getNoOfCopiesInStock() const;
    int getPopularVoteRepublican() const;
    int getPopularVoteDemocrat() const;

    void checkOut();
    void checkIn();
    void printTitle() const;
    void printInfo() const;
    bool checkTitle(string title);
    void updateInStock(int num);
    void setCopiesInStock(int num);
    string getTitle() const;

    voteCountType(string stateID = "", string stateName = "", int setInStock = 0,
            int voteCountRepublican = 0, int voteCountDemocrat = 0);

    // Overload relational operators
    bool operator==(const voteCountType&) const;
    bool operator!=(const voteCountType&) const;
    bool operator<(const voteCountType&) const;
    bool operator<=(const voteCountType&) const;
    bool operator>(const voteCountType&) const;
    bool operator>=(const voteCountType&) const;

   private:
    string stateID;
    string stateName;
    int electorialVotes;         // todo : unsigned
    int popularVotesRepublican;  // todo : unsigned
    int popularVotesDemocrat;    // todo : unsigned
};

#endif