#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setStyleSheet("background-color: #EAEAEA;");
    //this->setStyleSheet("* {color: qlineargradient(spread:pad, x1:0 y1:0, x2:1 y2:0, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));"
      //                  "background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 cyan, stop:1 Purple);}");
    this->setStyleSheet("* {color: qlineargradient(stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"
                        "background: qlineargradient(stop:0 cyan, stop:1 Purple);}");

    for(int i = 1; i <= 5; i++){
        ui->comboBox_6->addItem(QString::number(i));
        ui->comboBox_17->addItem(QString::number(i));
        ui->comboBox_18->addItem(QString::number(i));
        ui->comboBox_19->addItem(QString::number(i));
        ui->comboBox_20->addItem(QString::number(i));
        ui->comboBox_25->addItem(QString::number(i));
    }
    QString arr[5] = {"Student", "Morning Shift", "Afternoon Shift", "Evening Shift", "Overnight Shift"};
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        ui->comboBox_26->addItem(arr[i]);

    }
    QString arr2[5] = {"Apartment", "Town House", "House", "Condo", "Mansion"};
    for(int j = 0; j < sizeof(arr2)/sizeof(arr2[0]); j++){
        ui->comboBox_27->addItem(arr2[j]);

    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
 * View Animals Button for
 *        Staff
 */
void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->label_3->setText("Database");
    ui->label_3->setStyleSheet("color: rgb(128,0,0)");
    login c;
    QSqlQueryModel *model = new QSqlQueryModel();
    c.dbOpen();
    QSqlQuery *q = new QSqlQuery(c.db);
    q->prepare("SELECT * from ANIMAL");
    q->exec();
    model->setQuery(*q);
    ui->tableView->setModel(model);
    c.dbClose();
    qDebug() << (model->rowCount());

    login l;
    QSqlQueryModel *m = new QSqlQueryModel();
    l.dbOpen();
    QSqlQuery* qry = new QSqlQuery(l.db);
    qry->prepare("SELECT name from ANIMAL");
    qry->exec();
    m->setQuery(*qry);
    ui->listView_4->setModel(m);
    ui->comboBox_3->setModel(m);
    l.dbClose();
    qDebug() <<(m->rowCount());

    on_pushButton_24_clicked();
}
/*
 * Add Animals Button for
 *        Staff
 */
void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->label_4->setText("Type");
    ui->label_5->setText("Breed");
    ui->label_6->setText("Name");
    ui->label_7->setText("Sex");
    ui->label_8->setText("Age");
    ui->label_9->setText("Social");
    ui->label_10->setText("Health");
    ui->label_11->setText("Diet");
    ui->label_12->setText("Trained");
    ui->label_13->setText("Nocturnal");
    ui->label_20->setText("Emotion");
    ui->label_21->setText("Pet's Worth");
    ui->label_26->setText("Has Kids");
    ui->label_27->setText("Allergies");
    ui->label_28->setText("Stability");
    ui->label_29->setText("Housing");

    login c;
    QSqlQueryModel *model = new QSqlQueryModel();
    c.dbOpen();
    QSqlQuery *q = new QSqlQuery(c.db);
    q->prepare("SELECT * from ANIMAL");
    q->exec();
    model->setQuery(*q);
    ui->tableView_2->setModel(model);
    c.dbClose();
    qDebug() << (model->rowCount());

    login l;
    QSqlQueryModel *m = new QSqlQueryModel();
    l.dbOpen();
    QSqlQuery* qry = new QSqlQuery(l.db);
    qry->prepare("SELECT name from ANIMAL");
    qry->exec();
    m->setQuery(*qry);
    ui->listView_2->setModel(m);
    ui->comboBox->setModel(m);
    l.dbClose();
    qDebug() <<(m->rowCount());

    on_pushButton_24_clicked();


}
/*
 * Staff Page
 */
void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->label_2->setText("Welcome Staff!");
    ui->label_2->setStyleSheet("color: rgb(128,0,0)");
}
/*
 * Client Page
 */
void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->label->setText("Welcome Client!");
    ui->label->setStyleSheet("color: rgb(128,0,0)");
}
/*
 * Back Button for
 *  View Animals
 */
void MainWindow::on_pushButton_5_clicked()
{
    on_pushButton_26_clicked();
    ui->stackedWidget->setCurrentIndex(2);
}
/*
 * Homepage Button for
 *    View Animals
 */
void MainWindow::on_pushButton_6_clicked()
{
    on_pushButton_26_clicked();
    ui->stackedWidget->setCurrentIndex(0);
}
/*
 * Back Button for
 *     Client
 */
void MainWindow::on_pushButton_7_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}
/*
 * Save Button in Staff (Add Animal)
 * Stores an Animal in Memory and
 *          Database.
 */
void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    login l;
    QString type, breed, name, sex, age, social, condition, diet, train;
    QString nocturnal, emotion, petWorth, parental, allergies, stability, res;

    type         = ui->lineEdit_25->text();
    breed        = ui->lineEdit_24->text();
    name         = ui->lineEdit_23->text();
    sex          = ui->lineEdit_22->text();
    age          = ui->lineEdit_21->text();
    social       = ui->lineEdit_20->text();
    condition    = ui->lineEdit_19->text();
    diet         = ui->lineEdit_18->text();
    train        = ui->lineEdit_17->text();
    nocturnal    = ui->lineEdit_16->text();
    emotion      = ui->lineEdit_26->text();
    petWorth     = ui->lineEdit_27->text();
    parental     = ui->lineEdit_28->text();
    allergies    = ui->lineEdit_29->text();
    stability    = ui->lineEdit_30->text();
    res          = ui->lineEdit_31->text();



    if(!l.dbOpen()){
        qDebug()<<"FAILED TO OPEN DATABASE";
        return;
    }
    /*
     * Create an Animal Object for User Input
     *     and stores it in Memory
     *         (Linked List).
     */
    Animal *newAnimal;
    newAnimal = new Animal(type, breed, name, sex, age, social, condition, diet, train, nocturnal, emotion, petWorth, parental, allergies, stability, res);
    shelter.add(newAnimal);
    /*
     * Store the User Input in the
     *        Database.
     */
    l.dbOpen();
    QSqlQuery q;
    q.prepare("INSERT INTO ANIMAL(type, breed, name, sex, age, social, condition, diet, train, nocturnal, emotion, petWorth, parental, allergies, stability, res) values('"+type+"','"+breed+"','"+
              name+"','"+sex+"','"+age+"','"+social+"','"+condition+"','"+diet+"','"+train+"','"+nocturnal+"','"+emotion+"','"+petWorth+"', '"+parental+"', '"+allergies+"','"+stability+"','"+res+"')");

    if(q.exec()){
        //Message for User if Animal is added.
        QMessageBox::critical(this, tr("Save"), tr("Inserted!"));
        l.dbClose();
    }else{
        QMessageBox::critical(this, tr("ERROR"), q.lastError().text());
    }
    /*
     * Print Updated
     *   Database.
     */
    QSqlQueryModel *model = new QSqlQueryModel();
    l.dbOpen();
    QSqlQuery *que = new QSqlQuery(l.db);
    que->prepare("SELECT * from ANIMAL");
    que->exec();
    model->setQuery(*que);
    ui->tableView_2->setModel(model);
    l.dbClose();
    qDebug() << "There is:" << (model->rowCount()) << "Animals in the database now.";

    //login l;
    QSqlQueryModel *m = new QSqlQueryModel();
    l.dbOpen();
    QSqlQuery* qry = new QSqlQuery(l.db);
    qry->prepare("SELECT name from ANIMAL");
    qry->exec();
    m->setQuery(*qry);
    ui->listView_2->setModel(m);
    ui->comboBox->setModel(m);
    l.dbClose();
    qDebug() <<(m->rowCount());

    l.dbLaunch();
    on_pushButton_24_clicked();

}
/*
 * Back Button for
 *  Add Animals
 */
void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
/*
 * Homepage Button for
 *    Add Animals
 */
void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

/*
 * Back Button for
 *  staff login
 *
 */
void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
/*
 * View Clients
 *  for Staff
 */
void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->label_23->setText("Database");
    ui->label_23->setStyleSheet("color: rgb(128,0,0)");
    login c;
    QSqlQueryModel *model = new QSqlQueryModel();
    c.dbOpen();
    QSqlQuery *q = new QSqlQuery(c.db);
    q->prepare("SELECT * from CLIENT");
    q->exec();
    model->setQuery(*q);
    ui->tableView_3->setModel(model);
    c.dbClose();
    qDebug() << (model->rowCount());

    login l;
    QSqlQueryModel *m = new QSqlQueryModel();
    l.dbOpen();
    QSqlQuery* qry = new QSqlQuery(l.db);
    qry->prepare("SELECT id from CLIENT");
    qry->exec();
    m->setQuery(*qry);
    ui->listView_8->setModel(m);
    ui->comboBox_7->setModel(m);
    l.dbClose();
    qDebug() <<(m->rowCount());

    on_pushButton_25_clicked();
}
/*
 * View Animals
 *  for Clients
 */
void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->label_25->setText("Database");
    ui->label_25->setStyleSheet("color: rgb(128,0,0)");
    login c;
    QSqlQueryModel *model = new QSqlQueryModel();
    c.dbOpen();
    QSqlQuery *q = new QSqlQuery(c.db);
    q->prepare("SELECT * from ANIMAL");
    q->exec();
    model->setQuery(*q);
    ui->tableView_4->setModel(model);
    c.dbClose();
    qDebug() << (model->rowCount());

    login l;
    QSqlQueryModel *m = new QSqlQueryModel();
    l.dbOpen();
    QSqlQuery* qry = new QSqlQuery(l.db);
    qry->prepare("SELECT name from ANIMAL");
    qry->exec();
    m->setQuery(*qry);
    ui->listView_9->setModel(m);
    ui->comboBox_8->setModel(m);
    l.dbClose();
    qDebug() <<(m->rowCount());

    on_pushButton_25_clicked();


}
/*
 * Back Button for
 * Client View Animals
 */
void MainWindow::on_pushButton_14_clicked()
{
    on_pushButton_54_clicked();
    ui->stackedWidget->setCurrentIndex(1);
}
/*
 * Homepage Button
 * for Client View Animals
 */
void MainWindow::on_pushButton_15_clicked()
{
    on_pushButton_54_clicked();
    ui->stackedWidget->setCurrentIndex(0);
}
/*
 * Back Button for
 * Staff View Client
*/
void MainWindow::on_pushButton_16_clicked()
{
    on_pushButton_53_clicked();
    ui->stackedWidget->setCurrentIndex(2);
}
/*
 * Homepage Button for
 * Staff View Client
*/
void MainWindow::on_pushButton_17_clicked()
{
    on_pushButton_53_clicked();
    ui->stackedWidget->setCurrentIndex(0);
}
/*
 * Add Client Button
 *    for Staff
*/
void MainWindow::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    ui->label_32->setText("id");
    ui->label_33->setText("Name");
    ui->label_34->setText("Address");
    ui->label_44->setText("Age");
    ui->label_46->setText("Social");
    ui->label_36->setText("Health");
    ui->label_45->setText("Diet");
    ui->label_39->setText("Train");
    ui->label_35->setText("Nocturnal");
    ui->label_37->setText("Emotion");
    ui->label_40->setText("Pet Worth");
    ui->label_43->setText("Has Kids");
    ui->label_42->setText("Allergies");
    ui->label_41->setText("Stability");
    ui->label_38->setText("Housing");

    login c;
    QSqlQueryModel *model = new QSqlQueryModel();
    c.dbOpen();
    QSqlQuery *q = new QSqlQuery(c.db);
    q->prepare("SELECT * from CLIENT");
    q->exec();
    model->setQuery(*q);
    ui->tableView_5->setModel(model);
    c.dbClose();
    qDebug() << (model->rowCount());

    login l;
    QSqlQueryModel *m = new QSqlQueryModel();
    l.dbOpen();
    QSqlQuery* qry = new QSqlQuery(l.db);
    qry->prepare("SELECT id from CLIENT");
    qry->exec();
    m->setQuery(*qry);
    ui->listView_3->setModel(m);
    ui->comboBox_2->setModel(m);
    l.dbClose();
    qDebug() <<(m->rowCount());

    on_pushButton_25_clicked();
}
/*
 * Save Button for
 * Add Client
 * in Staff
*/
void MainWindow::on_pushButton_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    login l;
    QString id, name, address, age, social, condition, diet, train, nocturnal, emotion, petWorth, parental, allergies, stability, res;

    id          = ui->lineEdit_32->text();
    name        = ui->lineEdit_33->text();
    address     = ui->lineEdit_34->text();
    age         = ui->lineEdit_36->text();
    social      = ui->lineEdit_35->text();
    condition   = ui->lineEdit_46->text();
    diet        = ui->lineEdit_39->text();
    train       = ui->lineEdit_40->text();
    nocturnal   = ui->lineEdit_43->text();
    emotion     = ui->lineEdit_44->text();
    petWorth    = ui->lineEdit_37->text();
    parental    = ui->lineEdit_42->text();
    allergies   = ui->lineEdit_41->text();
    stability   = ui->lineEdit_38->text();
    res         = ui->lineEdit_45->text();

    if(!l.dbOpen()){
        qDebug()<<"FAILED TO OPEN DATABASE";
        return;
    }
    /*
     * Create an Client Object for User Input
     *     and stores it in Memory
     *         (Linked List).
     */
    Client *newClient;
    newClient = new Client(id, name, address, age, social, condition, diet, train, nocturnal, emotion, petWorth, parental, allergies, stability, res);
    shelter.addClient(newClient);
    /*
     * Store the User Input in the
     *        Database.
     */
    l.dbOpen();
    QSqlQuery q;
    q.prepare("INSERT INTO CLIENT(id, name, address, age, social, condition, diet, train, nocturnal, emotion, petWorth, parental, allergies, stability, res) values('"+id+"','"+name+"','"+address+"','"+age+"','"+social+"','"+condition+"','"+diet+"','"+train+"','"+nocturnal+"','"+emotion+"','"+petWorth+"','"+parental+"','"+allergies+"','"+stability+"','"+res+"')");

    if(q.exec()){
        //Message for User if Client is added.
        QMessageBox::critical(this, tr("Save"), tr("Inserted!"));
        l.dbClose();
    }else{
        QMessageBox::critical(this, tr("ERROR"), q.lastError().text());
    }
    /*
     * Print Updated
     *   Database.
     */
    QSqlQueryModel *model = new QSqlQueryModel();
    l.dbOpen();
    QSqlQuery *que = new QSqlQuery(l.db);
    que->prepare("SELECT * from CLIENT");
    que->exec();
    model->setQuery(*que);
    ui->tableView_5->setModel(model);
    l.dbClose();
    qDebug() << "There is:" << (model->rowCount()) << "Clients in the database now.";

    //login l;
    QSqlQueryModel *m = new QSqlQueryModel();
    l.dbOpen();
    QSqlQuery* qry = new QSqlQuery(l.db);
    qry->prepare("SELECT id from CLIENT");
    qry->exec();
    m->setQuery(*qry);
    ui->listView_3->setModel(m);
    ui->comboBox_2->setModel(m);
    l.dbClose();
    qDebug() <<(m->rowCount());

    l.dbLaunch();
    on_pushButton_25_clicked();

}
/*
 * Back Button for
 * Add Client
 * in Staff
*/
void MainWindow::on_pushButton_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
/*
 * Homepage Button for
 * Add Client
 * in Staff
*/
void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

/*
 * Load Button for
 * Add Animal in Staff
*/
/*
void MainWindow::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    login l;
    QSqlQueryModel *m = new QSqlQueryModel();
    l.dbOpen();
    QSqlQuery* qry = new QSqlQuery(l.db);
    qry->prepare("SELECT name from ANIMAL");
    qry->exec();
    m->setQuery(*qry);
    ui->listView_2->setModel(m);
    ui->comboBox->setModel(m);
    l.dbClose();
    qDebug() <<(m->rowCount());

}
*/
/*
 * Combo Click
 * in Add Animal
*/
void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->stackedWidget->setCurrentIndex(4);
    QString name = ui->comboBox->currentText();
    login l;


    if(!l.dbOpen()){
        qDebug()<<"FAILED TO OPEN DATABASE";
        return;
    }
    /*
     * Store the User Input in the
     *        Database.
     */
    l.dbOpen();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM ANIMAL where name ='"+name+"'");

    if(qry.exec()){
        while(qry.next()){
            ui->lineEdit_25->setText(qry.value(0).toString());
            ui->lineEdit_24->setText(qry.value(1).toString());
            ui->lineEdit_23->setText(qry.value(2).toString());
            ui->lineEdit_22->setText(qry.value(3).toString());
            ui->lineEdit_21->setText(qry.value(4).toString());
            ui->lineEdit_20->setText(qry.value(5).toString());
            ui->lineEdit_19->setText(qry.value(6).toString());
            ui->lineEdit_18->setText(qry.value(7).toString());
            ui->lineEdit_17->setText(qry.value(8).toString());
            ui->lineEdit_16->setText(qry.value(9).toString());
            ui->lineEdit_26->setText(qry.value(10).toString());
            ui->lineEdit_27->setText(qry.value(11).toString());
            ui->lineEdit_28->setText(qry.value(12).toString());
            ui->lineEdit_29->setText(qry.value(13).toString());
            ui->lineEdit_30->setText(qry.value(14).toString());
            ui->lineEdit_31->setText(qry.value(15).toString());

        }
        l.dbClose();
    }else{
        QMessageBox::critical(this, tr("ERROR"), qry.lastError().text());
    }
}
/*
 * Table Click in
 * Add Animals
*/
void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{
    ui->stackedWidget->setCurrentIndex(4);
    QString val = ui->tableView_2->model()->data(index).toString();
    login l;


    if(!l.dbOpen()){
        qDebug()<<"FAILED TO OPEN DATABASE";
        return;
    }
    /*
     * Store the User Input in the
     *        Database.
     */
    l.dbOpen();
    QSqlQuery qry;
    //(type, breed, name, sex, age, social, condition, diet, train, nocturnal, emotion, petWorth, parental, allergies, stability, res)
    qry.prepare("SELECT * FROM ANIMAL where type ='"+val+"' or breed='"+val+"' or name='"+
                val+"' or sex='"+val+"' or age='"+val+"' or social='"+val+"' or condition='"+
                val+"' or diet='"+val+"' or train='"+val+"' or nocturnal='"+val+"' or emotion='"+
                val+"' or petWorth='"+val+"' or parental='"+val+"' or allergies='"+val+"' or stability='"+
                val+"' or res='"+val+"'");

    if(qry.exec()){
        while(qry.next()){
            ui->lineEdit_25->setText(qry.value(0).toString());
            ui->lineEdit_24->setText(qry.value(1).toString());
            ui->lineEdit_23->setText(qry.value(2).toString());
            ui->lineEdit_22->setText(qry.value(3).toString());
            ui->lineEdit_21->setText(qry.value(4).toString());
            ui->lineEdit_20->setText(qry.value(5).toString());
            ui->lineEdit_19->setText(qry.value(6).toString());
            ui->lineEdit_18->setText(qry.value(7).toString());
            ui->lineEdit_17->setText(qry.value(8).toString());
            ui->lineEdit_16->setText(qry.value(9).toString());
            ui->lineEdit_26->setText(qry.value(10).toString());
            ui->lineEdit_27->setText(qry.value(11).toString());
            ui->lineEdit_28->setText(qry.value(12).toString());
            ui->lineEdit_29->setText(qry.value(13).toString());
            ui->lineEdit_30->setText(qry.value(14).toString());
            ui->lineEdit_31->setText(qry.value(15).toString());

        }
        l.dbClose();
    }else{
        QMessageBox::critical(this, tr("ERROR"), qry.lastError().text());
    }

}
/*
 * List Click in
 * Add Animals
*/
void MainWindow::on_listView_2_activated(const QModelIndex &index)
{
    ui->stackedWidget->setCurrentIndex(4);
    QString val = ui->listView_2->model()->data(index).toString();
    login l;


    if(!l.dbOpen()){
        qDebug()<<"FAILED TO OPEN DATABASE";
        return;
    }
    /*
     * Store the User Input in the
     *        Database.
     */
    l.dbOpen();
    QSqlQuery qry;

    qry.prepare("SELECT * FROM ANIMAL where name ='"+val+"'");
    if(qry.exec()){
        while(qry.next()){
            ui->lineEdit_25->setText(qry.value(0).toString());
            ui->lineEdit_24->setText(qry.value(1).toString());
            ui->lineEdit_23->setText(qry.value(2).toString());
            ui->lineEdit_22->setText(qry.value(3).toString());
            ui->lineEdit_21->setText(qry.value(4).toString());
            ui->lineEdit_20->setText(qry.value(5).toString());
            ui->lineEdit_19->setText(qry.value(6).toString());
            ui->lineEdit_18->setText(qry.value(7).toString());
            ui->lineEdit_17->setText(qry.value(8).toString());
            ui->lineEdit_16->setText(qry.value(9).toString());
            ui->lineEdit_26->setText(qry.value(10).toString());
            ui->lineEdit_27->setText(qry.value(11).toString());
            ui->lineEdit_28->setText(qry.value(12).toString());
            ui->lineEdit_29->setText(qry.value(13).toString());
            ui->lineEdit_30->setText(qry.value(14).toString());
            ui->lineEdit_31->setText(qry.value(15).toString());

        }
        l.dbClose();
    }else{
        QMessageBox::critical(this, tr("ERROR"), qry.lastError().text());
    }
}
/*
 * Load Button for
 * Add Client in Staff
*/
/*
void MainWindow::on_pushButton_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    login l;
    QSqlQueryModel *m = new QSqlQueryModel();
    l.dbOpen();
    QSqlQuery* qry = new QSqlQuery(l.db);
    qry->prepare("SELECT id from CLIENT");
    qry->exec();
    m->setQuery(*qry);
    ui->listView_3->setModel(m);
    ui->comboBox_2->setModel(m);
    l.dbClose();
    qDebug() <<(m->rowCount());
}
*/
/*
 * Combo Click
 * in Add CLient
*/
void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    ui->stackedWidget->setCurrentIndex(7);
    QString id = ui->comboBox_2->currentText();
    login l;


    if(!l.dbOpen()){
        qDebug()<<"FAILED TO OPEN DATABASE";
        return;
    }
    /*
     * Store the User Input in the
     *        Database.
     */
    l.dbOpen();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM CLIENT where id ='"+id+"'");

    if(qry.exec()){
        while(qry.next()){
            ui->lineEdit_32->setText(qry.value(0).toString());
            ui->lineEdit_33->setText(qry.value(1).toString());
            ui->lineEdit_34->setText(qry.value(2).toString());
            ui->lineEdit_36->setText(qry.value(3).toString());
            ui->lineEdit_35->setText(qry.value(4).toString());
            ui->lineEdit_46->setText(qry.value(5).toString());
            ui->lineEdit_39->setText(qry.value(6).toString());
            ui->lineEdit_40->setText(qry.value(7).toString());
            ui->lineEdit_43->setText(qry.value(8).toString());
            ui->lineEdit_44->setText(qry.value(9).toString());
            ui->lineEdit_37->setText(qry.value(10).toString());
            ui->lineEdit_42->setText(qry.value(11).toString());
            ui->lineEdit_41->setText(qry.value(12).toString());
            ui->lineEdit_38->setText(qry.value(13).toString());
            ui->lineEdit_45->setText(qry.value(14).toString());

        }
        l.dbClose();
    }else{
        QMessageBox::critical(this, tr("ERROR"), qry.lastError().text());
    }

}
/*
 * Table Click in
 * Add Client
*/
void MainWindow::on_tableView_5_activated(const QModelIndex &index)
{
    ui->stackedWidget->setCurrentIndex(7);
    QString val = ui->tableView_5->model()->data(index).toString();
    login l;


    if(!l.dbOpen()){
        qDebug()<<"FAILED TO OPEN DATABASE";
        return;
    }
    /*
     * Store the User Input in the
     *        Database.
     */
    l.dbOpen();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM CLIENT where id ='"+val+"' or name='"+val+"' or address='"+val+"' or age='"+val+"' or social='"+val+"' or condition='"+val+"' or diet='"+val+"' or train='"+val+"' or nocturnal='"+val+"' or emotion='"+val+"' or petWorth='"+val+"' or parental='"+val+"' or allergies='"+val+"' or stability='"+val+"' or res='"+val+"'");

    if(qry.exec()){
        while(qry.next()){
            ui->lineEdit_32->setText(qry.value(0).toString());
            ui->lineEdit_33->setText(qry.value(1).toString());
            ui->lineEdit_34->setText(qry.value(2).toString());
            ui->lineEdit_36->setText(qry.value(3).toString());
            ui->lineEdit_35->setText(qry.value(4).toString());
            ui->lineEdit_46->setText(qry.value(5).toString());
            ui->lineEdit_39->setText(qry.value(6).toString());
            ui->lineEdit_40->setText(qry.value(7).toString());
            ui->lineEdit_43->setText(qry.value(8).toString());
            ui->lineEdit_44->setText(qry.value(9).toString());
            ui->lineEdit_37->setText(qry.value(10).toString());
            ui->lineEdit_42->setText(qry.value(11).toString());
            ui->lineEdit_41->setText(qry.value(12).toString());
            ui->lineEdit_38->setText(qry.value(13).toString());
            ui->lineEdit_45->setText(qry.value(14).toString());

        }
        l.dbClose();
    }else{
        QMessageBox::critical(this, tr("ERROR"), qry.lastError().text());
    }

}
/*
 * List Click in
 * Add Client
*/
void MainWindow::on_listView_3_activated(const QModelIndex &index)
{
    ui->stackedWidget->setCurrentIndex(7);
    QString val = ui->listView_3->model()->data(index).toString();
    login l;


    if(!l.dbOpen()){
        qDebug()<<"FAILED TO OPEN DATABASE";
        return;
    }
    /*
     * Store the User Input in the
     *        Database.
     */
    l.dbOpen();
    QSqlQuery qry;

    qry.prepare("SELECT * FROM CLIENT where id ='"+val+"'");
    if(qry.exec()){
        while(qry.next()){
            ui->lineEdit_32->setText(qry.value(0).toString());
            ui->lineEdit_33->setText(qry.value(1).toString());
            ui->lineEdit_34->setText(qry.value(2).toString());
            ui->lineEdit_36->setText(qry.value(3).toString());
            ui->lineEdit_35->setText(qry.value(4).toString());
            ui->lineEdit_46->setText(qry.value(5).toString());
            ui->lineEdit_39->setText(qry.value(6).toString());
            ui->lineEdit_40->setText(qry.value(7).toString());
            ui->lineEdit_43->setText(qry.value(8).toString());
            ui->lineEdit_44->setText(qry.value(9).toString());
            ui->lineEdit_37->setText(qry.value(10).toString());
            ui->lineEdit_42->setText(qry.value(11).toString());
            ui->lineEdit_41->setText(qry.value(12).toString());
            ui->lineEdit_38->setText(qry.value(13).toString());
            ui->lineEdit_45->setText(qry.value(14).toString());
        }
        l.dbClose();
    }else{
        QMessageBox::critical(this, tr("ERROR"), qry.lastError().text());
    }

}
/*
 * Clear Button for
 * Add Animals
*/
void MainWindow::on_pushButton_24_clicked()
{
    ui->lineEdit_25->setText("");
    ui->lineEdit_24->setText("");
    ui->lineEdit_23->setText("");
    ui->lineEdit_22->setText("");
    ui->lineEdit_21->setText("");
    ui->lineEdit_20->setText("");
    ui->lineEdit_19->setText("");
    ui->lineEdit_18->setText("");
    ui->lineEdit_17->setText("");
    ui->lineEdit_16->setText("");
    ui->lineEdit_26->setText("");
    ui->lineEdit_27->setText("");
    ui->lineEdit_28->setText("");
    ui->lineEdit_29->setText("");
    ui->lineEdit_30->setText("");
    ui->lineEdit_31->setText("");
}
/*
 * Clear Button for
 * Add Clients
*/
void MainWindow::on_pushButton_25_clicked()
{
    ui->lineEdit_32->setText("");
    ui->lineEdit_33->setText("");
    ui->lineEdit_34->setText("");
    ui->lineEdit_36->setText("");
    ui->lineEdit_35->setText("");
    ui->lineEdit_46->setText("");
    ui->lineEdit_39->setText("");
    ui->lineEdit_40->setText("");
    ui->lineEdit_43->setText("");
    ui->lineEdit_44->setText("");
    ui->lineEdit_37->setText("");
    ui->lineEdit_42->setText("");
    ui->lineEdit_41->setText("");
    ui->lineEdit_38->setText("");
    ui->lineEdit_45->setText("");


}
/*
 * Update Button for
 * Add Animals
*/
void MainWindow::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    login l;
    QString type, breed, name, sex, age, social, condition, diet, train;
    QString nocturnal, emotion, petWorth, parental, allergies, stability, res;

    type         = ui->lineEdit_25->text();
    breed        = ui->lineEdit_24->text();
    name         = ui->lineEdit_23->text();
    sex          = ui->lineEdit_22->text();
    age          = ui->lineEdit_21->text();
    social       = ui->lineEdit_20->text();
    condition    = ui->lineEdit_19->text();
    diet         = ui->lineEdit_18->text();
    train        = ui->lineEdit_17->text();
    nocturnal    = ui->lineEdit_16->text();
    emotion      = ui->lineEdit_26->text();
    petWorth     = ui->lineEdit_27->text();
    parental     = ui->lineEdit_28->text();
    allergies    = ui->lineEdit_29->text();
    stability    = ui->lineEdit_30->text();
    res          = ui->lineEdit_31->text();



    if(!l.dbOpen()){
        qDebug()<<"FAILED TO OPEN DATABASE";
        return;
    }
    /*
     * Create an Animal Object for User Input
     *     and stores it in Memory
     *         (Linked List).
     */
    Animal *newAnimal;
    newAnimal = new Animal(type, breed, name, sex, age, social, condition, diet, train, nocturnal, emotion, petWorth, parental, allergies, stability, res);
    shelter.add(newAnimal);
    /*
     * Store the User Input in the
     *        Database.
     */
    l.dbOpen();
    QSqlQuery q;
    q.prepare("update ANIMAL set type='"+type+"', breed='"+breed+"',name='"+name+"',sex='"+sex+"',age='"+age+"',social='"+social+"',condition='"+condition+"',diet='"+diet+"',train='"+train+"',nocturnal='"+nocturnal+"',emotion='"+emotion+"', petWorth='"+petWorth+"',parental='"+parental+"', allergies='"+allergies+"', stability='"+stability+"',res='"+res+"' where name='"+name+"'");

    if(q.exec()){
        //Message for User if Animal is added.
        QMessageBox::critical(this, tr("Edit"), tr("Updated!"));
        l.dbClose();
    }else{
        QMessageBox::critical(this, tr("ERROR"), q.lastError().text());
    }
    /*
     * Print Updated
     *   Database.
     */
    QSqlQueryModel *model = new QSqlQueryModel();
    l.dbOpen();
    QSqlQuery *que = new QSqlQuery(l.db);
    que->prepare("SELECT * from ANIMAL");
    que->exec();
    model->setQuery(*que);
    ui->tableView_2->setModel(model);
    l.dbClose();
    qDebug() << "There is:" << (model->rowCount()) << "Animals in the database now.";

    //login l;
    QSqlQueryModel *m = new QSqlQueryModel();
    l.dbOpen();
    QSqlQuery* qry = new QSqlQuery(l.db);
    qry->prepare("SELECT name from ANIMAL");
    qry->exec();
    m->setQuery(*qry);
    ui->listView_2->setModel(m);
    ui->comboBox->setModel(m);
    l.dbClose();
    qDebug() <<(m->rowCount());

    l.dbLaunch();
    on_pushButton_24_clicked();

}
/*
 * Update Button for
 * Add Client
*/
void MainWindow::on_pushButton_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    login l;
    QString id, name, address, age, social, condition, diet, train, nocturnal, emotion, petWorth, parental, allergies, stability, res;

    id          = ui->lineEdit_32->text();
    name        = ui->lineEdit_33->text();
    address     = ui->lineEdit_34->text();
    age         = ui->lineEdit_36->text();
    social      = ui->lineEdit_35->text();
    condition   = ui->lineEdit_46->text();
    diet        = ui->lineEdit_39->text();
    train       = ui->lineEdit_40->text();
    nocturnal   = ui->lineEdit_43->text();
    emotion     = ui->lineEdit_44->text();
    petWorth    = ui->lineEdit_37->text();
    parental    = ui->lineEdit_42->text();
    allergies   = ui->lineEdit_41->text();
    stability   = ui->lineEdit_38->text();
    res         = ui->lineEdit_45->text();

    if(!l.dbOpen()){
        qDebug()<<"FAILED TO OPEN DATABASE";
        return;
    }
    /*
     * Create an Client Object for User Input
     *     and stores it in Memory
     *         (Linked List).
     */
    Client *newClient;
    newClient = new Client(id, name, address, age, social, condition, diet, train, nocturnal, emotion, petWorth, parental, allergies, stability, res);
    shelter.addClient(newClient);
    /*
     * Store the User Input in the
     *        Database.
     */
    l.dbOpen();
    QSqlQuery q;
    q.prepare("update CLIENT set id='"+id+"', name='"+name+"', address='"+address+"', age='"+age+"', social='"+social+"', condition='"+condition+"', diet='"+diet+"', train='"+train+"', nocturnal='"+nocturnal+"', emotion='"+emotion+"', petWorth='"+petWorth+"', parental='"+parental+"', allergies='"+allergies+"', stability='"+stability+"', res='"+res+"' where id='"+id+"'");
    if(q.exec()){
        //Message for User if Client is added.
        QMessageBox::critical(this, tr("Edit"), tr("Updated!"));
        l.dbClose();
    }else{
        QMessageBox::critical(this, tr("ERROR"), q.lastError().text());
    }
    /*
     * Print Updated
     *   Database.
     */
    QSqlQueryModel *model = new QSqlQueryModel();
    l.dbOpen();
    QSqlQuery *que = new QSqlQuery(l.db);
    que->prepare("SELECT * from CLIENT");
    que->exec();
    model->setQuery(*que);
    ui->tableView_5->setModel(model);
    l.dbClose();
    qDebug() << "There is:" << (model->rowCount()) << "Clients in the database now.";

    //login l;
    QSqlQueryModel *m = new QSqlQueryModel();
    l.dbOpen();
    QSqlQuery* qry = new QSqlQuery(l.db);
    qry->prepare("SELECT id from CLIENT");
    qry->exec();
    m->setQuery(*qry);
    ui->listView_3->setModel(m);
    ui->comboBox_2->setModel(m);
    l.dbClose();
    qDebug() <<(m->rowCount());

    l.dbLaunch();
    on_pushButton_25_clicked();

}
/*
 * View Animals Staff
 * List Click
*/
void MainWindow::on_listView_4_activated(const QModelIndex &index)
{
    QString val = ui->listView_4->model()->data(index).toString();
    login l;


    if(!l.dbOpen()){
        qDebug()<<"FAILED TO OPEN DATABASE";
        return;
    }
    /*
     * Store the User Input in the
     *        Database.
     */
    l.dbOpen();
    QSqlQuery qry;

    qry.prepare("SELECT * FROM ANIMAL where name ='"+val+"'");
    if(qry.exec()){
        while(qry.next()){
            ui->lineEdit_61->setText(qry.value(0).toString());
            ui->lineEdit_60->setText(qry.value(1).toString());
            ui->lineEdit_53->setText(qry.value(2).toString());
            ui->lineEdit_52->setText(qry.value(3).toString());
            ui->lineEdit_48->setText(qry.value(4).toString());
            ui->lineEdit_47->setText(qry.value(5).toString());
            ui->lineEdit_62->setText(qry.value(6).toString());
            ui->lineEdit_51->setText(qry.value(7).toString());
            ui->lineEdit_54->setText(qry.value(8).toString());
            ui->lineEdit_57->setText(qry.value(9).toString());
            ui->lineEdit_58->setText(qry.value(10).toString());
            ui->lineEdit_49->setText(qry.value(11).toString());
            ui->lineEdit_56->setText(qry.value(12).toString());
            ui->lineEdit_55->setText(qry.value(13).toString());
            ui->lineEdit_50->setText(qry.value(14).toString());
            ui->lineEdit_59->setText(qry.value(15).toString());

        }
        l.dbClose();
    }else{
        QMessageBox::critical(this, tr("ERROR"), qry.lastError().text());
    }

}
/*
 * Clear Button for
 * View Animals in
 *     Staff
*/
void MainWindow::on_pushButton_26_clicked()
{
    ui->lineEdit_61->setText("");
    ui->lineEdit_60->setText("");
    ui->lineEdit_53->setText("");
    ui->lineEdit_52->setText("");
    ui->lineEdit_48->setText("");
    ui->lineEdit_47->setText("");
    ui->lineEdit_62->setText("");
    ui->lineEdit_51->setText("");
    ui->lineEdit_54->setText("");
    ui->lineEdit_57->setText("");
    ui->lineEdit_58->setText("");
    ui->lineEdit_49->setText("");
    ui->lineEdit_56->setText("");
    ui->lineEdit_55->setText("");
    ui->lineEdit_50->setText("");
    ui->lineEdit_59->setText("");

}
/*
 * List Click for
 * View Animals in
 *     Client
*/
void MainWindow::on_listView_9_activated(const QModelIndex &index)
{
    QString val = ui->listView_9->model()->data(index).toString();
    login l;


    if(!l.dbOpen()){
        qDebug()<<"FAILED TO OPEN DATABASE";
        return;
    }
    /*
     * Store the User Input in the
     *        Database.
     */
    l.dbOpen();
    QSqlQuery qry;

    qry.prepare("SELECT * FROM ANIMAL where name ='"+val+"'");
    if(qry.exec()){
        while(qry.next()){
            ui->lineEdit_139->setText(qry.value(0).toString());
            ui->lineEdit_129->setText(qry.value(1).toString());
            ui->lineEdit_138->setText(qry.value(2).toString());
            ui->lineEdit_133->setText(qry.value(3).toString());
            ui->lineEdit_132->setText(qry.value(4).toString());
            ui->lineEdit_140->setText(qry.value(5).toString());
            ui->lineEdit_135->setText(qry.value(6).toString());
            ui->lineEdit_128->setText(qry.value(7).toString());
            ui->lineEdit_131->setText(qry.value(8).toString());
            ui->lineEdit_137->setText(qry.value(9).toString());
            ui->lineEdit_125->setText(qry.value(10).toString());
            ui->lineEdit_126->setText(qry.value(11).toString());
            ui->lineEdit_136->setText(qry.value(12).toString());
            ui->lineEdit_134->setText(qry.value(13).toString());
            ui->lineEdit_127->setText(qry.value(14).toString());
            ui->lineEdit_130->setText(qry.value(15).toString());

        }
        l.dbClose();
    }else{
        QMessageBox::critical(this, tr("ERROR"), qry.lastError().text());
    }

}
/*
 * Clear Button for
 * View Animals in
 *     Client
*/
void MainWindow::on_pushButton_54_clicked()
{
    ui->lineEdit_139->setText("");
    ui->lineEdit_129->setText("");
    ui->lineEdit_138->setText("");
    ui->lineEdit_133->setText("");
    ui->lineEdit_132->setText("");
    ui->lineEdit_140->setText("");
    ui->lineEdit_135->setText("");
    ui->lineEdit_128->setText("");
    ui->lineEdit_131->setText("");
    ui->lineEdit_137->setText("");
    ui->lineEdit_125->setText("");
    ui->lineEdit_126->setText("");
    ui->lineEdit_136->setText("");
    ui->lineEdit_134->setText("");
    ui->lineEdit_127->setText("");
    ui->lineEdit_130->setText("");

}
/*
 * List Click in
 * View Clients for
 *     Staff
*/
void MainWindow::on_listView_8_activated(const QModelIndex &index)
{
    QString val = ui->listView_8->model()->data(index).toString();
    login l;


    if(!l.dbOpen()){
        qDebug()<<"FAILED TO OPEN DATABASE";
        return;
    }
    /*
     * Store the User Input in the
     *        Database.
     */
    l.dbOpen();
    QSqlQuery qry;

    qry.prepare("SELECT * FROM CLIENT where id ='"+val+"'");
    if(qry.exec()){
        while(qry.next()){
            ui->lineEdit_113->setText(qry.value(0).toString());
            ui->lineEdit_114->setText(qry.value(1).toString());
            ui->lineEdit_121->setText(qry.value(2).toString());
            ui->lineEdit_111->setText(qry.value(3).toString());
            ui->lineEdit_123->setText(qry.value(4).toString());
            ui->lineEdit_112->setText(qry.value(5).toString());
            ui->lineEdit_117->setText(qry.value(6).toString());
            ui->lineEdit_116->setText(qry.value(7).toString());
            ui->lineEdit_115->setText(qry.value(8).toString());
            ui->lineEdit_124->setText(qry.value(9).toString());
            ui->lineEdit_110->setText(qry.value(10).toString());
            ui->lineEdit_119->setText(qry.value(11).toString());
            ui->lineEdit_122->setText(qry.value(12).toString());
            ui->lineEdit_120->setText(qry.value(13).toString());
            ui->lineEdit_118->setText(qry.value(14).toString());
        }
        l.dbClose();
    }else{
        QMessageBox::critical(this, tr("ERROR"), qry.lastError().text());
    }

}
/*
 * Clear Button for
 * View Clients for
 *     Staff
*/
void MainWindow::on_pushButton_53_clicked()
{
    ui->lineEdit_113->setText("");
    ui->lineEdit_114->setText("");
    ui->lineEdit_121->setText("");
    ui->lineEdit_111->setText("");
    ui->lineEdit_123->setText("");
    ui->lineEdit_112->setText("");
    ui->lineEdit_117->setText("");
    ui->lineEdit_116->setText("");
    ui->lineEdit_115->setText("");
    ui->lineEdit_124->setText("");
    ui->lineEdit_110->setText("");
    ui->lineEdit_119->setText("");
    ui->lineEdit_122->setText("");
    ui->lineEdit_120->setText("");
    ui->lineEdit_118->setText("");

}

void MainWindow::on_pushButton_55_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);

    login l;
    QSqlQueryModel *m = new QSqlQueryModel();
    l.dbOpen();
    QSqlQuery* qry = new QSqlQuery(l.db);
    qry->prepare("SELECT id from CLIENT");
    qry->exec();
    m->setQuery(*qry);
    ui->listView_10->setModel(m);
    //ui->comboBox_7->setModel(m);
    l.dbClose();
    qDebug() <<(m->rowCount());

    on_pushButton_53_clicked();
}

/*
 * List Click for
 * Edit Client in
 * Client
*/
void MainWindow::on_listView_10_activated(const QModelIndex &index)
{
    ui->stackedWidget->setCurrentIndex(8);
    QString val = ui->listView_10->model()->data(index).toString();
    login l;


    if(!l.dbOpen()){
        qDebug()<<"FAILED TO OPEN DATABASE";
        return;
    }

    /*
     * Store the User Input in the
     *        Database.
     */

    l.dbOpen();
    QSqlQuery qry;

    qry.prepare("SELECT * FROM CLIENT where id ='"+val+"'");
    ui->stackedWidget->setCurrentIndex(9);

    if(qry.exec()){
        while(qry.next()){
            ui->lineEdit_229->setText(qry.value(0).toString());
            ui->lineEdit_230->setText(qry.value(1).toString());
            ui->lineEdit_233->setText(qry.value(2).toString());
            ui->lineEdit_227->setText(qry.value(3).toString());
            ui->lineEdit_231->setText(qry.value(4).toString());
            ui->lineEdit_220->setText(qry.value(5).toString());
            ui->lineEdit_226->setText(qry.value(6).toString());
            ui->lineEdit_221->setText(qry.value(7).toString());
            ui->lineEdit_222->setText(qry.value(8).toString());
            ui->lineEdit_232->setText(qry.value(9).toString());
            ui->lineEdit_224->setText(qry.value(10).toString());
            ui->lineEdit_219->setText(qry.value(11).toString());
            ui->lineEdit_228->setText(qry.value(12).toString());
            ui->lineEdit_225->setText(qry.value(13).toString());
            ui->lineEdit_223->setText(qry.value(14).toString());
        }
        l.dbClose();
    }else{
        QMessageBox::critical(this, tr("ERROR"), qry.lastError().text());
    }
    QSqlQueryModel *model = new QSqlQueryModel();
    l.dbOpen();
    QSqlQuery *que = new QSqlQuery(l.db);
    que->prepare("SELECT * from CLIENT where id ='"+val+"'");
    que->exec();
    model->setQuery(*que);
    ui->tableView_16->setModel(model);
    l.dbClose();
    qDebug() << "There is:" << (model->rowCount()) << "Clients in the database now.";

    //ui->stackedWidget->setCurrentIndex(9);

}
/*
 * Update Button for
 * Edit Client in
 * List Click for
 * Client
*/
void MainWindow::on_pushButton_87_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    login l;
    QString id, name, address, age, social, condition, diet, train, nocturnal, emotion, petWorth, parental, allergies, stability, res;

    id          = ui->lineEdit_229->text();
    name        = ui->lineEdit_230->text();
    address     = ui->lineEdit_233->text();
    age         = ui->lineEdit_227->text();
    social      = ui->lineEdit_231->text();
    condition   = ui->lineEdit_220->text();
    diet        = ui->lineEdit_226->text();
    train       = ui->lineEdit_221->text();
    nocturnal   = ui->lineEdit_222->text();
    emotion     = ui->lineEdit_232->text();
    petWorth    = ui->lineEdit_224->text();
    parental    = ui->lineEdit_219->text();
    allergies   = ui->lineEdit_228->text();
    stability   = ui->lineEdit_225->text();
    res         = ui->lineEdit_223->text();

    if(!l.dbOpen()){
        qDebug()<<"FAILED TO OPEN DATABASE";
        return;
    }
    /*
     * Create an Client Object for User Input
     *     and stores it in Memory
     *         (Linked List).
     */
    Client *newClient;
    newClient = new Client(id, name, address, age, social, condition, diet, train, nocturnal, emotion, petWorth, parental, allergies, stability, res);
    shelter.addClient(newClient);
    /*
     * Store the User Input in the
     *        Database.
     */
    l.dbOpen();
    QSqlQuery q;
    q.prepare("update CLIENT set id='"+id+"', name='"+name+"', address='"+address+"', age='"+age+"', social='"+social+"', condition='"+condition+"', diet='"+diet+"', train='"+train+"', nocturnal='"+nocturnal+"', emotion='"+emotion+"', petWorth='"+petWorth+"', parental='"+parental+"', allergies='"+allergies+"', stability='"+stability+"', res='"+res+"' where id='"+id+"'");
    if(q.exec()){
        //Message for User if Client is added.
        QMessageBox::critical(this, tr("Edit"), tr("Updated!"));
        l.dbClose();
    }else{
        QMessageBox::critical(this, tr("ERROR"), q.lastError().text());
    }
    /*
     * Print Updated
     *   Database.
     */
    //ui->stackedWidget->setCurrentIndex(8);

    QSqlQueryModel *model = new QSqlQueryModel();
    //QString val = ui->listView_10->model()->data(index).toString();
    l.dbOpen();
    QSqlQuery *que = new QSqlQuery(l.db);
    que->prepare("SELECT * from CLIENT where id='"+id+"'");
    que->exec();
    model->setQuery(*que);
    ui->tableView_16->setModel(model);
    l.dbClose();
    qDebug() << "There is:" << (model->rowCount()) << "Clients in the database now.";

    /*
    //login l;
    QSqlQueryModel *m = new QSqlQueryModel();
    l.dbOpen();
    QSqlQuery* qry = new QSqlQuery(l.db);
    qry->prepare("SELECT id from CLIENT");
    qry->exec();
    m->setQuery(*qry);
    ui->listView_3->setModel(m);
    //ui->comboBox_2->setModel(m);
    l.dbClose();
    qDebug() <<(m->rowCount());

    l.dbLaunch();
    */

    //on_pushButton_25_clicked();
    //on_pushButton_55_clicked();

}
/*
 * Back Button for
 * Edit Client in
 * List Click for
 * Client
*/
void MainWindow::on_pushButton_85_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}
/*
 * Homepage Button for
 * Edit Client in
 * List Click
 * Client
*/
void MainWindow::on_pushButton_86_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
/*
 * Back Button for
 * Edit Client in
 * Client
*/
void MainWindow::on_pushButton_88_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
/*
 * Homepage Button for
 * Edit Client in
 * Client
*/
void MainWindow::on_pushButton_89_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

/*
 * ACM Button for
 * Staff
*/
void MainWindow::on_pushButton_27_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

/*
 * Back Button for
 * ACM in Staff
*/
void MainWindow::on_pushButton_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

/*
 * Homepage Button for
 * Staff in ACM
*/
void MainWindow::on_pushButton_29_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

/*
 * Start Button for
 * ACM in Staff
*/
void MainWindow::on_pushButton_30_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
//    login l;
//    QSqlQueryModel *m = new QSqlQueryModel();
//    QSqlQueryModel *m2 = new QSqlQueryModel();
//    l.dbOpen();
//    QSqlQuery* qry = new QSqlQuery(l.db);
//    QSqlQuery* qry2 = new QSqlQuery(l.db);
//    qry->prepare("SELECT distinct type from ANIMAL");
//    qry2->prepare("SELECT distinct age from ANIMAL");
//    qry->exec();
//    qry2->exec();
//    m->setQuery(*qry);
//    m2->setQuery(*qry2);
//    ui->comboBox_4->setModel(m);
//    ui->comboBox_5->setModel(m2);
//    l.dbClose();
//    qDebug() <<"There are:"<<(m->rowCount()) <<"Unique Animals in the database.";
//    qDebug() <<"There are:"<<(m2->rowCount())<<"Unique Ages of Animals in the database.";

    login l;
    QSqlQueryModel *m = new QSqlQueryModel();
    //QSqlQueryModel *m2 = new QSqlQueryModel();
    l.dbOpen();
    QSqlQuery* qry = new QSqlQuery(l.db);
    //QSqlQuery* qry2 = new QSqlQuery(l.db);
    qry->prepare("SELECT id from CLIENT");
    //qry2->prepare("SELECT * from ANIMAL");
    qry->exec();
    //qry2->exec();
    m->setQuery(*qry);
    //m2->setQuery(*qry2);
    ui->listView_5->setModel(m);
    //ui->tableView_6->setModel(m2);
    l.dbClose();
    qDebug() <<"There are:"<<(m->rowCount()) <<"Clients in the database.";
    //qDebug() <<"There are:"<<(m2->rowCount()) <<"Clients and Animals in the database.";

}


/*
 * Back Button for
 * ACM in Staff
*/
void MainWindow::on_pushButton_32_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

///*
// * Homepage Button for
// * ACM in Staff
//*/
void MainWindow::on_pushButton_31_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

///*
// * Next Button for
// * Filter Stage
// * in Staff for ACM
//*/
//void MainWindow::on_pushButton_33_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(12);
//}
///*
// * Back Button for
// * Scenerio Questions
// * in Staff for ACM
//*/
//void MainWindow::on_pushButton_34_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(11);
//}
///*
// * Submit Button for ACM
// * in Staff to match
// * Client with Pet
//*/
//void MainWindow::on_pushButton_35_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(13);
//}
///*
// * Back Button for
// * Matching Client in
// * Staff
//*/
//void MainWindow::on_pushButton_36_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(12);
//}

void MainWindow::on_pushButton_36_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_listView_5_activated(const QModelIndex &index)
{
    QString val = ui->listView_5->model()->data(index).toString();
    //Client
    QString id, name, address, age, social, condition, diet, train;
    QString nocturnal, emotion, petWorth, parental, allergies, stability, res;

    //Animal
    QString type, breed, name2, sex, age2, social2, condition2, diet2, train2;
    QString nocturnal2, emotion2, petWorth2, parental2, allergies2, stability2, res2;
    login l;
    /*ACM a = new ACM(0,0, type, breed, name2, sex, age2, social2, condition2, diet2, train2,
                  nocturnal2, emotion2, petWorth2, parental2, allergies2, stability2, res2,
                  id, name, address, age, social, condition, diet, train, nocturnal, emotion,
                  petWorth, parental, allergies, stability, res);
                  */


    if(!l.dbOpen()){
        qDebug()<<"FAILED TO OPEN DATABASE";
        return;
    }
    /*
     * Store the User Input in the
     *        Database.
     */
    l.dbOpen();
    QSqlQuery qry;
    QSqlQuery qryy;

    qry.prepare("SELECT * FROM CLIENT where id ='"+val+"'");
    ui->stackedWidget->setCurrentIndex(13);
    if(qry.exec()){
        QMessageBox::critical(this, tr("Match"), tr("MATCHED!"));
        l.dbClose();
    }else{
        QMessageBox::critical(this, tr("ERROR"), qry.lastError().text());
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQueryModel *modell = new QSqlQueryModel();
    l.dbOpen();
    QSqlQuery *que = new QSqlQuery(l.db);
    QSqlQuery *quee = new QSqlQuery(l.db);
    que->prepare("SELECT * from CLIENT where id ='"+val+"'");
    quee->prepare("SELECT * from ANIMAL where age !='"+val+"' ORDER BY RANDOM() LIMIT 1");
    que->exec();
    quee->exec();
    model->setQuery(*que);
    modell->setQuery(*quee);
    ui->tableView_6->setModel(model);
    ui->tableView_7->setModel(modell);
    //a.weightingSystem();
    l.dbClose();
    qDebug() << "There is:" << (model->rowCount()) << "Clients in the database now.";

}

void MainWindow::on_pushButton_37_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
