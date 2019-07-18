#include "auftragsannahme_many.h"
#include "ui_auftragsannahme_many.h"
<<<<<<< HEAD
#include <QDebug>
#include <QSqlError>
#include "auftragsannahme_alone.h"
Auftragsannahme_Many::Auftragsannahme_Many(QString login,QString str,QWidget *parent) :
=======

Auftragsannahme_Many::Auftragsannahme_Many(QWidget *parent) :
>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
  QMainWindow(parent),
  ui(new Ui::Auftragsannahme_Many)
{
  ui->setupUi(this);
<<<<<<< HEAD
  ui->Name_person->setText(login);
  this->login=login;
  db = QSqlDatabase::addDatabase("QSQLITE");

  db.setDatabaseName("C:/D_B/test.db");
  if(!db.open())
    {
      qDebug() << db.lastError().text();
    }
  else {
      qDebug() <<"yes";
    }
  model = new QSqlQueryModel;
  model->setQuery(str);
  ui->tableView->setModel(model);
  ui->tableView->horizontalHeader()->setStyleSheet("background-color:black;");
  ui->tableView->setStyleSheet("QHeaderView::section {background-color:red}");

  this->update_table();

=======
>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
}

Auftragsannahme_Many::~Auftragsannahme_Many()
{
  delete ui;
}

<<<<<<< HEAD
void Auftragsannahme_Many::update_table()
{
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
  ui->tableView->setTextElideMode(Qt::TextElideMode::ElideMiddle);
  ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
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
  au_alone =new Auftragsannahme_Alone(this->login,values);
  au_alone->show();
}
void Auftragsannahme_Many::resizeEvent(QResizeEvent *event)
{
  this->update_table();
=======
void Auftragsannahme_Many::on_lupeButton_clicked()
{
    Lupe(ui->outFrame);
>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
}
