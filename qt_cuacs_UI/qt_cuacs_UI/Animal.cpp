#include <iostream>
#include <iomanip>
#include <QString>
using namespace std;

#include "Animal.h"


Animal::Animal(QString type, QString breed, QString name, QString sex,
               QString age, QString social, QString condition, QString diet,
               QString train, QString nocturnal, QString emotion, QString petWorth,
               QString parental, QString allergies, QString stability, QString res)
{
    this->type      = type;
    this->breed     = breed;
    this->name      = name;
    this->sex       = sex;
    this->age       = age;
    this->social    = social;
    this->condition = condition;
    this->diet      = diet;
    this->train     = train;
    this->nocturnal = nocturnal;
    this->emotion   = emotion;
    this->petWorth  = petWorth;
    this->parental  = parental;
    this->allergies = allergies;
    this->stability = stability;
    this->res       = res;

}

Animal::~Animal(){}

void Animal::print(){

    qDebug().noquote() << "type:       " << type;
    qDebug().noquote() << "breed:      " << breed;
    qDebug().noquote() << "name:       " << name;
    qDebug().noquote() << "sex:        " << sex;
    qDebug().noquote() << "age:        " << age;
    qDebug().noquote() << "social:     " << social;
    qDebug().noquote() << "condition:  " << condition;
    qDebug().noquote() << "diet:       " << diet;
    qDebug().noquote() << "trained:    " << train;
    qDebug().noquote() << "nocturnal:  " << nocturnal;
    qDebug().noquote() << "emotion:    " << emotion;
    qDebug().noquote() << "petWorth:   " << petWorth;
    qDebug().noquote() << "parental:   " << parental;
    qDebug().noquote() << "allergies:  " << allergies;
    qDebug().noquote() << "stability:  " << stability;
    qDebug().noquote() << "housing:    " << res;
    qDebug().noquote() << "            ";

}

/*
 * getters for all attributes.
 */

QString Animal::getType(){
    return type;
}

QString Animal::getBreed(){
    return breed;
}

QString Animal::getName(){
    return name;
}

QString Animal::getSex(){
    return sex;
}

QString Animal::getSocial(){
    return social;
}

QString Animal::getCondition(){
    return condition;
}

QString Animal::getDiet(){
    return diet;
}

QString Animal::getNocturnal(){
    return nocturnal;
}

QString Animal::getEmotion(){
    return emotion;
}

QString Animal::getPetWorth(){
    return petWorth;
}

QString Animal::getParental(){
    return parental;
}

QString Animal::getAllergies(){
    return allergies;
}

QString Animal::getStability(){
    return stability;
}

QString Animal::getResidence(){
    return res;
}
