#include <iostream>
#include <string>
using namespace std;

#include "Shelter.h"

Shelter::Shelter(){}

void Shelter::add(Animal *a){
  animalList.add(a);
}

void Shelter::addClient(Client *c){
  clientList.add(c);
}

void Shelter::print(){
  animalList.print();
}
