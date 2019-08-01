#include "auftragsliste.h"
#include "ui_auftragsliste.h"

Auftragsliste::Auftragsliste(QString login,QSqlQuery qSqlQuery,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsliste)
{
  ui->setupUi(this);
  ui->Name_person->setText(login);
  this->login=login;
  model = new QSqlQueryModel;
  model->setQuery(qSqlQuery);
  createTable();
}

Auftragsliste::~Auftragsliste()
{
  delete ui;
}


void Auftragsliste::on_lupeButton_clicked()
{

  lupe(ui->outFrame);
}


void Auftragsliste::createTable()
{
  ui->tableView->setModel(model);
  ui->tableView->setStyleSheet("QHeaderView::section {background-color:gray}");
  ui->tableView->verticalHeader()->setVisible(false);
  ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Stretch);
  ui->tableView->horizontalHeader()->setSectionResizeMode(7, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(8, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(9, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(10, QHeaderView::ResizeToContents);
}

void Auftragsliste::on_button_Abbrechen_clicked()
{
  this->close();
}
