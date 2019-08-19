#include "dispositionsdater_for_hvt_schaltauftrag.h"
#include "ui_dispositionsdater_for_hvt_schaltauftrag.h"
#include <QDesktopWidget>
Dispositionsdater_for_HVt_Schaltauftrag::Dispositionsdater_for_HVt_Schaltauftrag(QString login,QString DispoCenter,QSqlQuery qSqlQuery,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Dispositionsdater_for_HVt_Schaltauftrag)
{
  ui->setupUi(this);
  ui->Name_person->setText(login);
  ui->labelDispoCenter->setText(DispoCenter);
  this->addline(qSqlQuery);
  QDesktopWidget widget;
  QRect mainScreenSize = widget.screenGeometry(this);
  this->setGeometry(mainScreenSize.width()*0.2/2,mainScreenSize.height()*0.2/2,(int)(mainScreenSize.width()*0.8),mainScreenSize.height()*0.8);
}

Dispositionsdater_for_HVt_Schaltauftrag::~Dispositionsdater_for_HVt_Schaltauftrag()
{
  delete ui;
}

void Dispositionsdater_for_HVt_Schaltauftrag::on_button_Abbrechen_clicked()
{
  this->close();
}

void Dispositionsdater_for_HVt_Schaltauftrag::addline(QSqlQuery qSqlQuery)
{
  ui->big_line_Auftragsbeschreibung->clear();
  QString str;
  ui->line_Auftrags_Nr->setText(qSqlQuery.value(25).toString());
  ui->line_Servicemonteur->setText(qSqlQuery.value(26).toString());
  ui->line_Grobe_Zustandigkeit->setText(qSqlQuery.value(27).toString());
  ui->line_PlanGr->setText(qSqlQuery.value(10).toString());
  str=qSqlQuery.value(25).toString().mid(0,6);
  ui->line_Termin->setText(str+qSqlQuery.value(40).toString());
  str=qSqlQuery.value(25).toString().mid(6,5);
  ui->line_ATZ_1->setText(str);
  ui->line_Erledigungsdauer->setText(qSqlQuery.value(28).toString());
  ui->line_AuftrUKI->setText(qSqlQuery.value(2).toString());
  ui->line_Prioritat->setText(qSqlQuery.value(29).toString());
  ui->line_Skill->setText(qSqlQuery.value(30).toString());
  ui->line_TDN->setText(qSqlQuery.value(31).toString());
  ui->line_SchaltArt->setText(qSqlQuery.value(32).toString());
  ui->line_Vabst_ID->setText(qSqlQuery.value(20).toString());
  ui->line_Anzaht->setText(qSqlQuery.value(4).toString());
  ui->line_Vollstanding->setText(qSqlQuery.value(22).toString());
  ui->line_CRM->setText(qSqlQuery.value(23).toString());
  ui->line_ONKz->setText(qSqlQuery.value(33).toString());
  ui->line_AzB->setText(qSqlQuery.value(34).toString());
  ui->line_PLZ->setText(qSqlQuery.value(35).toString());
  ui->line_Ortsname->setText(qSqlQuery.value(36).toString());
  ui->line_StraNername->setText(qSqlQuery.value(38).toString());
  ui->line_HsHr->setText(qSqlQuery.value(39).toString());
  ui->big_line_Auftragsbeschreibung->insertPlainText(qSqlQuery.value(37).toString());
  ui->comboBox->addItem(qSqlQuery.value(9).toString());
}
