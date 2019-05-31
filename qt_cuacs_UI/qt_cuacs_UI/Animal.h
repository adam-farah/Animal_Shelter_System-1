#ifndef ANIMAL_H
#define ANIMAL_H
#include <QString>
#include <QDebug>


class Animal
{
public:
    Animal(QString, QString, QString, QString,
           QString, QString, QString, QString,
           QString, QString, QString, QString,
           QString, QString, QString, QString);
    ~Animal();
    QString getType();
    QString getBreed();
    QString getName();
    QString getSex();
    QString getAge();
    QString getSocial();
    QString getCondition();
    QString getDiet();
    QString getTrain();
    QString getNocturnal();
    QString getEmotion();
    QString getPetWorth();
    QString getParental();
    QString getAllergies();
    QString getStability();
    QString getResidence();
    void print();

private: 
    QString type;
    QString breed;
    QString name;
    QString sex;
    QString age;
    QString social;
    QString condition;
    QString diet;
    QString train;
    QString nocturnal;
    QString emotion;
    QString petWorth;
    QString parental;
    QString allergies;
    QString stability;
    QString res;

};

#endif // ANIMAL_H
