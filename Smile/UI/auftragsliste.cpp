#include "auftragsliste.h"
#include "ui_auftragsliste.h"

Auftragsliste::Auftragsliste(QString login,QString dispo,QSqlQuery qSqlQuery,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsliste)
{
  ui->setupUi(this);
  ui->Name_person->setText(login);
  ui->labelDispo->setText(dispo);
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
  ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
  ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(7, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(8, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(9, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(10, QHeaderView::ResizeToContents);
}

void Auftragsliste::on_button_Abbrechen_clicked()
{
  this->close();
}

void Auftragsliste::on_tableView_clicked(const QModelIndex &index)
{
 ui->lineNBezug->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),8)).toString());
}

void Auftragsliste::on_tableView_doubleClicked(const QModelIndex &index)
{
  QVector<QString> values;
  for(int i=0;i<model->columnCount();i++)
  {
    values.push_back((ui->tableView->model()->data(ui->tableView->model()->index(index.row(),i)).toString()));
  }
  DispoHvt=new Dispositionsdater_for_HVt_Schaltauftrag(this->login,ui->labelDispo->text(),values,this);
  DispoHvt->show();
}
