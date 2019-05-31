#include <iostream>
#include <iomanip>
#include <QString>
using namespace std;

#include "Client.h"

Client::Client(QString id, QString name, QString address, QString age,
               QString social, QString condition, QString diet, QString train,
               QString nocturnal, QString emotion, QString petWorth, QString parental,
               QString allergies, QString stability, QString res)
{
    this->id = id;
    this->name = name;
    this->address = address;
    this->age = age;
    this->social = social;
    this->condition = condition;
    this->diet = diet;
    this->train = train;
    this->nocturnal = nocturnal;
    this->emotion = emotion;
    this->petWorth = petWorth;
    this->parental = parental;
    this->allergies = allergies;
    this->stability = stability;
    this->res = res;

}

Client::~Client(){}

void Client::print(){
    qDebug().noquote() << "id:         " << id;
    qDebug().noquote() << "name:       " << name;
    qDebug().noquote() << "address:    " << address;
    qDebug().noquote() << "age:        " << age;
    qDebug().noquote() << "social:     " << social;
    qDebug().noquote() << "condition:  " << condition;
    qDebug().noquote() << "diet:       " << diet;
    qDebug().noquote() << "train:      " << train;
    qDebug().noquote() << "nocturnal:  " << nocturnal;
    qDebug().noquote() << "emotion:    " << emotion;
    qDebug().noquote() << "petWorth:   " << petWorth;
    qDebug().noquote() << "parental:   " << parental;
    qDebug().noquote() << "allergies:  " << allergies;
    qDebug().noquote() << "stability:  " << stability;
    qDebug().noquote() << "res:        " << res;
    qDebug().noquote() << "            ";
}

QString Client::getId(){
    return id;
}

QString Client::getName(){
    return name;
}

QString Client::getAddress(){
    return address;
}

QString Client::getAge(){
    return age;
}

QString Client::getSocial(){
    return social;
}

QString Client::getCondition(){
    return condition;
}

QString Client::getDiet(){
    return diet;
}

QString Client::getTrain(){
    return train;
}

QString Client::getNocturnal(){
    return nocturnal;
}

QString Client::getEmotion(){
    return emotion;
}

QString Client::getPetWorth(){
    return petWorth;
}

QString Client::getParental(){
    return parental;
}

QString Client::getAllergies(){
    return allergies;
}

QString Client::getStability(){
    return stability;
}

QString Client::getRes(){
    return res;
}
