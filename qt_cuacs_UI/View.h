#ifndef VIEW_H
#define VIEW_H
using namespace std;

#include "Shelter.h"

class View
{
  public:
    View();
    //Simply moving code from the main into the following member functions
    void mainMenu(int&);
    void staffMenu(int&);
    void clientMenu(int&);
    //void readInfo(QString&, QString&, QString&, QString&, QString&, QString&, QString&, QString&, QString&, QString&);
    void printShelter(Shelter&);

  private:


};


#endif
