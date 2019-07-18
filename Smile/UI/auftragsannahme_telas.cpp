#include "auftragsannahme_telas.h"
#include "ui_auftragsannahme_telas.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
Auftragsannahme_TelAs::Auftragsannahme_TelAs(QString login,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsannahme_TelAs)
{
  ui->setupUi(this);
  ui->dateEdit->setDate(QDate::currentDate());
  ui->Name_person->setText(login);
  this->login=login;
  db = QSqlDatabase::addDatabase("QSQLITE");

  db.setDatabaseName("C:/D_B/test.db");
  //db.setUserName("test");
  //db.setPassword("test");
  if(!db.open())
    {
      qDebug() << db.lastError().text();
    }
  else {
      qDebug() <<"yes";
    }
  qDebug() <<db.tables();
}

Auftragsannahme_TelAs::~Auftragsannahme_TelAs()
{
  delete ui;
}



void Auftragsannahme_TelAs::on_OK_clicked()
{
  QVector<QString> values;
  QString Sql_name= this->ui->name_for_Sql->text();
  QSqlQuery query(db);
  qDebug()<<Sql_name;
  if(Sql_name=="*" || Sql_name=="")
    {
      Sql_name="Name";
    }
  else {
      Sql_name="'"+Sql_name+"'";
    }
  qDebug()<<Sql_name;
  QString quest="select * from Auftragsannahme_TelAs where Name = "+Sql_name+" ORDER BY GKZ ";
  qDebug() <<quest;
  query.exec(quest);
  query.size();
  query.last();
  if(query.at()+1 == 1)
    {
      query.first();
      int i = 0;

      while(i<query.record().count())
        {
          values.push_back(query.value(i).toString());
          qDebug() <<query.value(i).toString();
          i++;
        }
      AUF_Alone = new Auftragsannahme_Alone(this->login,values);

      AUF_Alone->show();

    }
  else if(query.at()+1>1)
    {
      AUF_many = new Auftragsannahme_Many(this->login,quest);

      AUF_many->show();
    }
  else
    {
      QMessageBox::warning(this,"Name","jordan или не nejordan");
    }
}






void Auftragsannahme_TelAs::on_Abbrech_clicked()
{

}

void Auftragsannahme_TelAs::on_name_for_Sql_returnPressed()
{
  this->on_OK_clicked();
}
