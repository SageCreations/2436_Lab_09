#ifndef H_dvdType
#define H_dvdType

#include <iostream>
#include <string>

using namespace std;

class dvdType {
  public:
    void setDVDInfo(string title, string star1,
                            string star2, string producer,  
                            string director,
                            string productionCo,
                            int setInStock);

    void checkOut();
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
                      string productionCo, int setInStock);

        //Overload the relational operators
    bool operator==(const dvdType& right) const;
    bool operator!=(const dvdType& right) const;
    bool operator<(const dvdType& right) const;
    bool operator<=(const dvdType& right) const;
    bool operator>(const dvdType& right) const;
    bool operator>=(const dvdType& right) const;
    friend ostream& operator<<(ostream& osObject, const dvdType& dvd);
  
  private:
    string dvdTitle;
    string movieStar1;
    string movieStar2;
    string movieProducer;
    string movieDirector;
    string movieProductionCo;
    int    copiesInStock;
};

#endif
