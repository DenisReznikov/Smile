#include "auftragsliste.h"
#include "ui_auftragsliste.h"
#include <QDesktopWidget>
Auftragsliste::Auftragsliste(QString login,QString dispo,QSqlQuery qSqlQuery,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsliste),
  qSqlQuery(qSqlQuery)
{
  ui->setupUi(this);
  ui->Name_person->setText(login);
  ui->labelDispo->setText(dispo);
  model = new MSqlQueryModel;
  model->setQuery(qSqlQuery);
  model->removeColumns(11,model->columnCount()-11);
  QDesktopWidget wid;
  QRect mainScreenSize = wid.screenGeometry(this);
  this->setGeometry(static_cast<int>(mainScreenSize.width()*0.2/2),static_cast<int>(mainScreenSize.height()*0.2/2),static_cast<int>(mainScreenSize.width()*0.8),static_cast<int>(mainScreenSize.height()*0.8));
  createTable();
}

Auftragsliste::~Auftragsliste()
{
  delete ui;
  delete model;
  delete DispoHvt;
}

void Auftragsliste::on_lupeButton_clicked()
{
  lupe(ui->outFrame);
}

void Auftragsliste::createTable() const
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
  ui->big_info->clear();
  qSqlQuery.seek(index.row());
  ui->line_f_ATZ->setText(qSqlQuery.value(11).toString());
  ui->line_s_EZ->setText(qSqlQuery.value(12).toString());
  ui->line_SO->setText(qSqlQuery.value(13).toString());
  ui->line_NBezug->setText(qSqlQuery.value(14).toString());
  ui->line_Name->setText(qSqlQuery.value(15).toString());
  ui->line_A_A->setText(qSqlQuery.value(16).toString());
  ui->line_A_UA->setText(qSqlQuery.value(17).toString());
  ui->line_VBKz->setText(qSqlQuery.value(18).toString());
  ui->line_ZM->setText(qSqlQuery.value(19).toString());
  ui->line_Vabst_ID->setText(qSqlQuery.value(20).toString());
  ui->line_Anzahl->setText(qSqlQuery.value(21).toString());
  ui->line_Vollstandg->setText(qSqlQuery.value(22).toString());
  ui->line_CRM->setText(qSqlQuery.value(23).toString());
  ui->big_info->insertPlainText(qSqlQuery.value(24).toString());
}

void Auftragsliste::on_tableView_doubleClicked(const QModelIndex &index)
{
  qSqlQuery.seek(index.row());
  DispoHvt=new Dispositionsdater_for_HVt_Schaltauftrag(this->login,ui->labelDispo->text(),qSqlQuery,this);
  DispoHvt->show();
}
