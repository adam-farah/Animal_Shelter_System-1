#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QDebug>


class Client
{
public:
  Client(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString);
  ~Client();
  QString getId();
  QString getName();
  QString getAddress();
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
  QString getRes();
  void print();

private:
  QString id;
  QString name;
  QString address;
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

#endif // CLIENT_H
