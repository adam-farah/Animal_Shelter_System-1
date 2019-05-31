#include <iostream>
#include <iomanip>
#include <QString>
using namespace std;

#include "ACM.h"

ACM::ACM(int weight, int scoring, QString type, QString breed, QString name, QString sex,
         QString age, QString social, QString condition, QString diet,
         QString train, QString nocturnal, QString emotion,
         QString petWorth, QString parental, QString allergies,
         QString stability, QString res,QString id, QString name2, QString address2, QString age2,
         QString social2, QString condition2, QString diet2, QString train2,
         QString nocturnal2, QString emotion2, QString petWorth2, QString parental2,
         QString allergies2, QString stability2, QString res2) : Animal(type, breed, name,
                                                  sex, age, social, condition,
                                                  diet, train, nocturnal, emotion,
                                                  petWorth, parental, allergies, stability,
                                                  res), Client(id, name2, address2, age2,
                                                               social2, condition2, diet2, train2,
                                                               nocturnal2, emotion2, petWorth2, parental2,
                                                               allergies2, stability2, res2){
    this->weight = weight;
    this->scoring = scoring;
}

ACM::~ACM(){}

int ACM::getWeight(){
    return weight;
}

int ACM::getScoring(){
    return scoring;
}

int ACM::weightingSystem(){
    login l;
    l.dbOpen();

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

        float weightAge = 0.05;
        float weightSocial = 0.05;
        float weightDiet = 0.02;
        float weightTrained = 0.15;
        float weightPetWorth = 0.05;
        float weightAllergy = 0.08;
        float weightHealth = 0.15;
        float weightRes = 0.125;
        float weightNocturnal = 0.05;
        float weightEmotion = 0.05;
        float weightParental = 0.10;
        float weightStability = 0.125;

        int p = weightAge + weightSocial + weightDiet + weightTrained + weightPetWorth + weightAllergy + weightHealth + weightRes + weightNocturnal + weightEmotion + weightParental + weightStability;

        int n = p/12;

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

        float weightAge = 0.05;
        float weightSocial = 0.05;
        float weightDiet = 0.02;
        float weightTrained = 0.15;
        float weightPetWorth = 0.05;
        float weightAllergy = 0.08;
        float weightHealth = 0.15;
        float weightRes = 0.125;
        float weightNocturnal = 0.05;
        float weightEmotion = 0.05;
        float weightParental = 0.10;
        float weightStability = 0.125;

        int p = weightAge + weightSocial + weightDiet + weightTrained + weightPetWorth + weightAllergy + weightHealth + weightRes + weightNocturnal + weightEmotion + weightParental + weightStability;

        int n = p/12;

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



// QSqlQuery client_query;
// client_query.exec("SELECT id”);


////add all client objects to a list from SQL
//while (client_query.next()) {

//       	 QString name = query.value(0).toString();
//      	  int salary = query.value(1).toInt();
//	}

//	list<client> client_object_list;

//	client item;
//	client_object_list.push_back(item);

//}
//“same thing for animals ”
//animal_object_list

//for all client_object_list [ i ] {

//	//filterstage1 for age
//	for all animal_object_list [ j ] {
//		if ( client_object_list[i].age == x ) &&
//	((animal_object_list[ j ].age == x+1) || (animal_object_list[ j ].age == x-1 ) ||  (animal_object_list[ j ].age == x )

//	valid_animals_objects += animal_object_list[ j ]

////filterstage2 for social
//	for all valid_animals_objects [ j ] {
//		if ( client_object_list[i].social == x ) &&
//	((animal_object_list[ j ].social == x+1) || (valid_animals_objects[ j ].social == x-1 ) ||  (valid_animals_objects[ j ].social == x )

//	valid_animals_objects_filter2 += valid_animals_objects[ j ];
}
