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
  ui->tableView->setModel(model);


 ui->tableView->setStyleSheet("QHeaderView::section {background-color:gray}");

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

void Auftragsannahme_Many::resizeEvent(QResizeEvent *event)
{
  updateTable(ui->tableView);
}

void Auftragsannahme_Many::on_lupeButton_clicked()
{
    lupe(ui->outFrame);
}
