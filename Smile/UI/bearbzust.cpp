#include "bearbzust.h"
#include "ui_bearbzust.h"
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
  QDesktopWidget wid;
  QRect mainScreenSize = wid.screenGeometry(this);
  this->setGeometry(static_cast<int>(mainScreenSize.width()*0.8/2),static_cast<int>(mainScreenSize.height()*0.5/2),static_cast<int>(mainScreenSize.width()*0.2),static_cast<int>(mainScreenSize.height()*0.5));
  this->createTable();
}

BearbZust::~BearbZust()
{
  delete ui;
  delete model;
}

void BearbZust::createTable()
{
  ui->tableView->setModel(model);
  ui->tableView->setStyleSheet("QHeaderView::section {background-color:gray}");
  ui->tableView->verticalHeader()->setVisible(false);
  ui->tableView->selectRow(0);
  ui->tableView->setItemDelegate(new CheckBoxDelegate(ui->tableView,2));
  ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
  ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
  ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
}

void BearbZust::on_button_OK_clicked()
{
  ret=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toString();
  this->close();
}

void BearbZust::on_button_Abbrechen_clicked()
{
  this->close();
}

void BearbZust::on_tableView_doubleClicked(const QModelIndex )
{
  this->on_button_OK_clicked();
}
