#include "auftragsannahme_many.h"
#include "ui_auftragsannahme_many.h"
#include <QSqlRecord>
#include <QDesktopWidget>
Auftragsannahme_Many::Auftragsannahme_Many(QString login,QSqlQuery qSqlQuery, QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsannahme_Many)
{
  ui->setupUi(this);
  ui->Name_person->setText(login);
  this->login=login;
  model = new MSqlQueryModel;
  model->setQuery(qSqlQuery);
  this->qSqlQuery=qSqlQuery;
  model->removeColumns(11,model->columnCount()-11);
  QDesktopWidget wid;
  QRect mainScreenSize = wid.screenGeometry(this);
  this->setGeometry(static_cast<int>(mainScreenSize.width()*0.2/2),static_cast<int>(mainScreenSize.height()*0.2/2),static_cast<int>(mainScreenSize.width()*0.8),static_cast<int>(mainScreenSize.height()*0.8));
  this->createTable();
}

Auftragsannahme_Many::~Auftragsannahme_Many()
{
  delete ui;
  delete model;
}

void Auftragsannahme_Many::on_tableView_clicked(const QModelIndex &index)
{
  ui->line_BigInfo->clear();
  qSqlQuery.seek(index.row());
  QList<QLineEdit *> box=ui->outFrame->findChildren<QLineEdit*>();
  int b=11;
  for(QLineEdit *i : box)
  {
    QString str="";
    i->setText(qSqlQuery.value(b).toString());
    b++;
  }
  ui->line_BigInfo->insertPlainText(qSqlQuery.value(b++).toString());
}

void Auftragsannahme_Many::on_tableView_doubleClicked(const QModelIndex &index)
{
  qSqlQuery.seek(index.row());
  auAlone =new Auftragsannahme_Alone(this->login,qSqlQuery,this);
  auAlone->show();
}

void Auftragsannahme_Many::createTable() const
{
  ui->tableView->setModel(model);
  ui->tableView->setStyleSheet("QHeaderView::section {background-color:gray}");
  //ui->tableView->verticalHeader()->setVisible(false);
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
  delete model;
}

void Auftragsannahme_Many::on_lupeButton_clicked()
{
  lupe(ui->outFrame);
}

void Auftragsannahme_Many::on_button_Abbrechen_clicked()
{
  this->close();
}

void Auftragsannahme_Many::on_tableView_activated(const QModelIndex &index)
{
  this->on_tableView_clicked(index);
}

void Auftragsannahme_Many::on_tableView_pressed(const QModelIndex &index)
{
  this->on_tableView_clicked(index);
}
