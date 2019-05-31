#include <iostream>
#include <iomanip>
#include <QString>
#include <sstream>
#include <cstdlib>

#include "View.h"
using namespace std;

View::View(){}

void View::printShelter(Shelter& s){s.print();}
