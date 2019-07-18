#include "auftragsliste.h"
#include "ui_auftragsliste.h"

Auftragsliste::Auftragsliste(QString login,QString sql_string,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsliste)
{
  ui->setupUi(this);
  ui->Name_person->setText(login);
  this->login=login;
<<<<<<< HEAD
  db =  QSqlDatabase::addDatabase("QSQLITE");

  db.setDatabaseName("C:/D_B/test.db");
  if(!db.open())
    {
      qDebug() << db.lastError().text();
    }
  else
    {
      qDebug() <<"yes";
    }
  model = new QSqlQueryModel;
  model->setQuery(sql_string);

  ui->tableView->setModel(model);
=======

>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
}

Auftragsliste::~Auftragsliste()
{
  delete ui;
}
<<<<<<< HEAD
=======



void Auftragsliste::on_lupeButton_clicked()
{
    Lupe(ui->outFrame);
}
>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
