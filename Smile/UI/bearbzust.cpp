#include "bearbzust.h"
#include "ui_bearbzust.h"
#include <QDebug>
#include <QDesktopWidget>

BearbZust::BearbZust(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::BearbZust)
{
  ui->setupUi(this);
  model = new MSqlQueryModel;
  static toolsForDB db =  toolsForDB();
  QMap<QString,QString> map;
  QSqlQuery qSqlQuery= db.returnTable("BearbZust",map);
  model->setQuery(qSqlQuery);
  QDesktopWidget widget;
  QRect mainScreenSize = widget.screenGeometry(this);
  this->setGeometry(mainScreenSize.width()*0.8/2,mainScreenSize.height()*0.5/2,(int)(mainScreenSize.width()*0.2),mainScreenSize.height()*0.5);
  this->createTable();
  this->createTable();
}

BearbZust::~BearbZust()
{
  delete ui;
}

void BearbZust::createTable()
{
  ui->tableView->setModel(model);
  ui->tableView->setStyleSheet("QHeaderView::section {background-color:gray}");
  ui->tableView->verticalHeader()->setVisible(false);
  ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
  ui->tableView->selectRow(0);
}

void BearbZust::on_button_OK_clicked()
{
  ret=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toString();
  this->close();
}
