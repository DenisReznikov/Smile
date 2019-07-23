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
  ui->tableView->setModel(model);
  ui->tableView->setStyleSheet("QHeaderView::section {background-color:red}");
  updateTable(ui->tableView);
}

Auftragsliste::~Auftragsliste()
{
  delete ui;
}

void Auftragsliste::resizeEvent(QResizeEvent *event)
{
  qDebug()<<"rer";
  updateTable(ui->tableView);
}

void Auftragsliste::on_lupeButton_clicked()
{

    lupe(ui->outFrame);
}
