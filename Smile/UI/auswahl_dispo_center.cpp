#include "auswahl_dispo_center.h"
#include "ui_auswahl_dispo_center.h"
#include <QDesktopWidget>
Auswahl_Dispo_Center::Auswahl_Dispo_Center(QString login,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auswahl_Dispo_Center)
{
  ui->setupUi(this);
  this->login=login;
  ui->Name_person->setText(login);
  model = new QSqlQueryModel;
  static toolsForDB db =  toolsForDB();
  QMap<QString,QString> map;
  QSqlQuery qSqlQuery= db.returnTable("Auswahl_Dispo_Center",map);
  model->setQuery(qSqlQuery);
  QDesktopWidget widget;
  QRect mainScreenSize = widget.screenGeometry(this);
  this->setGeometry(mainScreenSize.width()*0.2/2,mainScreenSize.height()*0.2/2,(int)(mainScreenSize.width()*0.8),mainScreenSize.height()*0.8);
  this->createTable();
}

Auswahl_Dispo_Center::~Auswahl_Dispo_Center()
{
  delete ui;
  delete auftrags;
  delete model;
}
void Auswahl_Dispo_Center::createTable() const
{
  ui->tableView->setModel(model);
  ui->tableView->setStyleSheet("QHeaderView::section {background-color:gray}");
  ui->tableView->verticalHeader()->setVisible(false);
  ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
  ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);
}

void Auswahl_Dispo_Center::on_tableView_doubleClicked(const QModelIndex &index)
{
  ui->labelDispoCenter->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),2)).toString());
  auftrags =new Auftragsauswahl(ui->Name_person->text(),ui->labelDispoCenter->text(),this);
  auftrags->show();
}

void Auswahl_Dispo_Center::on_tableView_clicked(const QModelIndex &index)
{
  ui->labelDispoCenter->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),2)).toString());
}

void Auswahl_Dispo_Center::on_tableView_entered(const QModelIndex &index)
{
  this->on_tableView_doubleClicked(index);
}

void Auswahl_Dispo_Center::on_button_Abbrechen_clicked()
{
  this->close();
}
