#include "auswahl_dispo_center.h"
#include "ui_auswahl_dispo_center.h"

Auswahl_Dispo_Center::Auswahl_Dispo_Center(QString login,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auswahl_Dispo_Center)
{
  ui->setupUi(this);
  this->login=login;
  ui->Name_person->setText(login);
}

Auswahl_Dispo_Center::~Auswahl_Dispo_Center()
{
  delete ui;
}
void Auswahl_Dispo_Center::createTable()
{
  model = new QSqlQueryModel;
  static toolsForDB db =  toolsForDB();
  QSqlQuery qSqlQuery= db.checkInTable("Auswahl_Dispo_Center");
  model->setQuery(qSqlQuery);
  ui->tableView->setModel(model);
  ui->tableView->setStyleSheet("QHeaderView::section {background-color:gray}");
  ui->tableView->verticalHeader()->setVisible(false);
  ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
  ui->tableView->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Stretch);
  ui->tableView->horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);

}
