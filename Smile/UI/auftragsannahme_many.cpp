#include "auftragsannahme_many.h"
#include "ui_auftragsannahme_many.h"

Auftragsannahme_Many::Auftragsannahme_Many(QString login,QSqlQuery qSqlQuery, QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsannahme_Many)
{
  ui->setupUi(this);
  ui->Name_person->setText(login);
  this->login=login;
  model = new QSqlQueryModel;
  model->setQuery(qSqlQuery);
  this->createTable();
}

Auftragsannahme_Many::~Auftragsannahme_Many()
{
  delete ui;
  delete model;
  delete auAlone;
}

void Auftragsannahme_Many::on_tableView_clicked(const QModelIndex &index)
{
  ui->line_f_ATZ->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),1)).toString());
  ui->line_Name->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),6)).toString());
}

void Auftragsannahme_Many::on_tableView_doubleClicked(const QModelIndex &index)
{
  QVector<QString> values;
  for(int i=0;i<model->columnCount();i++)
  {
    values.push_back((ui->tableView->model()->data(ui->tableView->model()->index(index.row(),i)).toString()));
  }
  auAlone =new Auftragsannahme_Alone(this->login,values,this);
  auAlone->show();
}

void Auftragsannahme_Many::createTable()
{
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
  ui->tableView->horizontalHeader()->setSectionResizeMode(7, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(8, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(9, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(10, QHeaderView::ResizeToContents);
}

void Auftragsannahme_Many::on_lupeButton_clicked()
{
  lupe(ui->outFrame);
}
