#include "auswahl_dispo_center.h"
#include "ui_auswahl_dispo_center.h"

Auswahl_Dispo_Center::Auswahl_Dispo_Center(QString login,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auswahl_Dispo_Center)
{
  ui->setupUi(this);
  this->login=login;
  ui->Name_person->setText(login);
  model = new QSqlQueryModel;
  static toolsForDB db =  toolsForDB();
  QSqlQuery qSqlQuery= db.checkInTable("Auswahl_Dispo_Center");
  model->setQuery(qSqlQuery);
  ui->tableView->setModel(model);
  ui->tableView->setStyleSheet("QHeaderView::section {background-color:gray}");
  this->updateTable(ui->tableView);
}

Auswahl_Dispo_Center::~Auswahl_Dispo_Center()
{
  delete ui;
}
