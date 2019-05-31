#ifndef ANIMALLIST_H
#define ANIMALLIST_H

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Animal.h"
#include "Client.h"

template<class T>
class AnimalList
{
    template<class U>
    class Node
    {
        friend class AnimalList;
        private:
            T data;
            Node<T>* next;
    };

public:
    AnimalList();
    ~AnimalList();
    void add(T);
    void print();

private:
    Node<T>* head;
};

template<class T>
AnimalList<T>::AnimalList(): head(0){}

template<class T>
AnimalList<T>::~AnimalList(){
    Node<T>* currNode;
    Node<T>* nextNode;
    currNode = head;

    while(currNode != NULL){
        nextNode = currNode->next;
        delete currNode->data;
        delete currNode;
        currNode = nextNode;

    }
}
/*
 * Add function for linked list
 * Adds to the back
 */
template<class T>
void AnimalList<T>::add(T a){
  Node<T>*currNode;
  Node<T>*prevNode;

  Node<T>* tmpNode = new Node<T>;

  tmpNode->data = a;
  tmpNode->next = NULL;

  currNode = head;
  prevNode = 0;

  while(currNode != NULL){
    //if(currNode->data->getId() > tmpNode->data->getId()){
      //break;
    //}
    prevNode = currNode;
    currNode = currNode->next;
  }
  if(prevNode == NULL ){
    head = tmpNode;
  }else{
    prevNode->next = tmpNode;
  }
  tmpNode->next = currNode;

}

template<class T>
void AnimalList<T>::print(){
    Node<T>* currNode;
    Node<T>* nextNode;
    currNode = head;

    while(currNode != NULL){
      nextNode = currNode->next;
      currNode->data->print();
      currNode = nextNode;
    }

}

#endif // ANIMALLIST_H
