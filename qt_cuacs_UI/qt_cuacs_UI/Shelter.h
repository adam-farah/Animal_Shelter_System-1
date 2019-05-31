#ifndef SHELTER_H
#define SHELTER_H
using namespace std;

#include "AnimalList.h"

class Shelter
{
  public:
    Shelter();
    void add(Animal*);
    void addClient(Client*);
    void print();


  private:
    AnimalList<Animal*> animalList;
    AnimalList<Client*> clientList;

};

#endif
