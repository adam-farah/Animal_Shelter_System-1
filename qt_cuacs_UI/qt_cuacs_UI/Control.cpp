#include <iostream>
#include <iomanip>
#include <sstream>
#include <QString>
#include <QCoreApplication>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
using namespace std;

#include "Control.h"

Control::Control(){}

/*
 * Class used to first
 * generate the database.
 */
void Control::dbLaunch(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/student/COMP3004/D2/Animal_Shelter_System/qt_cuacs_UI/database/database.db");

    if(db.open()){
        qDebug() << "DB CONNECTED";
    }else{
        qDebug() << "DB NOT CONNECTED" << db.lastError();
    }

    QSqlQuery query("CREATE TABLE ANIMAL(type TEXT, breed TEXT, name TEXT, sex TEXT, age TEXT, social TEXT, condition TEXT, diet TEXT, train TEXT, nocturnal TEXT, emotion TEXT, petWorth TEXT, parental TEXT, allergies TEXT, stability TEXT, res TEXT)");
    QSqlQuery insertToAnimal;
    insertToAnimal.exec("insert into ANIMAL(type, breed, name, sex, age, social, condition, diet, train, nocturnal, emotion, petWorth, parental, allergies, stability, res)"
                     "values('Dog', 'Pitbull', 'Rex', 'Male', '2', 'Extremely Social', 'Healthy', 'None', 'Yes', 'No', 'Energetic', '$$', 'No', 'None', '5', 'Anywhere')");

    QSqlQuery query2("CREATE TABLE STAFF(id TEXT PRIMARY KEY, name TEXT)");
    QSqlQuery insertToStaff;
    insertToStaff.exec("insert into STAFF(id, name)"
                     "values('1', 'Kaleb Tesfay')");
    insertToStaff.exec("insert into STAFF(id, name)"
                     "values('2', 'Adam Farah')");
    insertToStaff.exec("insert into STAFF(id, name)"
                     "values('3', 'Japi Sandhu')");
    insertToStaff.exec("insert into STAFF(id, name)"
                     "values('4', 'Samson Teklay')");
    insertToStaff.exec("insert into STAFF(id, name)"
                     "values('5', 'Lauryn Esparza)");

    QSqlQuery query3("CREATE TABLE CLIENT(id TEXT PRIMARY KEY, name TEXT, address TEXT)");
    QSqlQuery insertToClient;
    insertToClient.exec("insert into CLIENT(id, name, address)"
                      "values('1', 'Wilfred James', '3670 Glory Road')");
    insertToClient.exec("insert into CLIENT(id, name, address)"
                      "values('2', 'Mona Lane', '2257 Berry Street')");
    insertToClient.exec("insert into CLIENT(id, name, address)"
                      "values('3', 'Steve Blake', '3441 Cemetery Street')");
    insertToClient.exec("insert into CLIENT(id, name, address)"
                      "values('4', 'Josh Rich', '2795 Green Hill Road')");
    insertToClient.exec("insert into CLIENT(id, name, address)"
                      "values('5', 'Marlee Sparks', '4162 Adams Drive')");

    QSqlQuery q;
    q.exec("SELECT * FROM ANIMAL");

    while(q.next()){
        QString type = q.value(0).toString();
        QString breed = q.value(1).toString();
        QString name = q.value(2).toString();
        QString sex = q.value(3).toString();
        QString age = q.value(4).toString();
        QString social = q.value(5).toString();
        QString condition = q.value(6).toString();
        QString diet = q.value(7).toString();
        QString train = q.value(8).toString();
        QString nocturnal = q.value(9).toString();
        QString emotion = q.value(10).toString();
        QString petWorth = q.value(11).toString();
        QString parental = q.value(12).toString();
        QString allergies = q.value(13).toString();
        QString stability = q.value(14).toString();
        QString res = q.value(15).toString();

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

}
