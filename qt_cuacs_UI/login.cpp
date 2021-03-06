#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QSql>
#include <QString>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QMainWindow>
#include "login.h"


login::login()
{

}

void login::dbClose(){
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
}

bool login::dbOpen(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QT_CUACS_UI_ROOT_DIR"/database/database.db");
    if(!db.open()){
        qDebug() << ("FAILS TO CONNECT");
        return false;
    }else{
        qDebug() << ("DATABASE CONNECTED");
        return true;
    }

}

void login::dbLaunch(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QT_CUACS_UI_ROOT_DIR"/database/database.db");
    if(db.open()){
        qDebug() << "DB CONNECTED";
    }else{
        qDebug() << "DB NOT CONNECTED";
    }

    QSqlQuery qu;
    qu.exec("SELECT * FROM ANIMAL");

    while(qu.next()){
        QString type = qu.value(0).toString();
        QString breed = qu.value(1).toString();
        QString name = qu.value(2).toString();
        QString sex = qu.value(3).toString();
        QString age = qu.value(4).toString();
        QString social = qu.value(5).toString();
        QString condition = qu.value(6).toString();
        QString diet = qu.value(7).toString();
        QString train = qu.value(8).toString();
        QString nocturnal = qu.value(9).toString();
        QString emotion = qu.value(10).toString();
        QString petWorth = qu.value(11).toString();
        QString parental = qu.value(12).toString();
        QString allergies = qu.value(13).toString();
        QString stability = qu.value(14).toString();
        QString res = qu.value(15).toString();



        /*
         * Dynamically Allocates the Database first
         *          Entries into Memory
         *            (Linked List)
         */
        Animal *newAnimal;
        newAnimal = new Animal(type, breed, name, sex, age, social, condition, diet, train, nocturnal, emotion, petWorth, parental, allergies, stability, res);
        s.add(newAnimal);

        qDebug().noquote() << "type:      " << type;
        qDebug().noquote() << "breed:     " << breed;
        qDebug().noquote() << "name:      " << name;
        qDebug().noquote() << "sex:       " << sex;
        qDebug().noquote() << "age:       " << age;
        qDebug().noquote() << "social:    " << social;
        qDebug().noquote() << "condition: " << condition;
        qDebug().noquote() << "diet:      " << diet;
        qDebug().noquote() << "trained:   " << train;
        qDebug().noquote() << "nocturnal: " << nocturnal;
        qDebug().noquote() << "emotion:   " << emotion;
        qDebug().noquote() << "petWorth:  " << petWorth;
        qDebug().noquote() << "parental:  " << parental;
        qDebug().noquote() << "allergies: " << allergies;
        qDebug().noquote() << "stability: " << stability;
        qDebug().noquote() << "housing:   " << res;
        qDebug().noquote() << "";
    }

    QSqlQuery que;
    que.exec("SELECT * FROM CLIENT");

    while(que.next()){
        QString id = que.value(0).toString();
        QString name = que.value(1).toString();
        QString address = que.value(2).toString();
        QString age = que.value(3).toString();;
        QString social = que.value(4).toString();;
        QString condition = que.value(5).toString();;
        QString diet = que.value(6).toString();
        QString train = que.value(7).toString();
        QString nocturnal = que.value(8).toString();
        QString emotion = que.value(9).toString();
        QString petWorth = que.value(10).toString();
        QString parental = que.value(11).toString();
        QString allergies = que.value(12).toString();
        QString stability = que.value(13).toString();
        QString res = que.value(14).toString();

        /*
         * Dynamically Allocates the Database first
         *          Entries into Memory
         *            (Linked List)
         */
        Client *newClient;
        newClient = new Client(id, name, address, age, social, condition, diet, train, nocturnal, emotion, petWorth, parental, allergies, stability, res);
        s.addClient(newClient);

        qDebug().noquote() << "id:        " << id;
        qDebug().noquote() << "name:      " << name;
        qDebug().noquote() << "address:   " << address;
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
        qDebug().noquote() << "";
    }
}

