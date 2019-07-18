#include "auftragsliste.h"
#include "ui_auftragsliste.h"

Auftragsliste::Auftragsliste(QString login,QString sql_string,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsliste)
{
  ui->setupUi(this);
  ui->Name_person->setText(login);
  this->login=login;
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
}

Auftragsliste::~Auftragsliste()
{
  delete ui;
}
