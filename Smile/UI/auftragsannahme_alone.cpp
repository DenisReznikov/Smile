#include "auftragsannahme_alone.h"
#include "ui_auftragsannahme_alone.h"
#include <QDesktopWidget>
Auftragsannahme_Alone::Auftragsannahme_Alone(QString login,QSqlQuery qSqlQuery,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsannahme_Alone)
{
  ui->setupUi(this);
  ui->Name_person->setText(login);
  this->addLine(qSqlQuery);
  QDesktopWidget widget;
  QRect mainScreenSize = widget.screenGeometry(this);
  qDebug()<<mainScreenSize.height();
  this->setGeometry(mainScreenSize.width()*0.2/2,mainScreenSize.height()*0.2/2,(int)(mainScreenSize.width()*0.8),mainScreenSize.height()*0.8);

}

Auftragsannahme_Alone::~Auftragsannahme_Alone()
{
  delete ui;
}

void Auftragsannahme_Alone::on_button_Abbrechen_clicked()
{
  this->close();
}
void Auftragsannahme_Alone::addLine(QSqlQuery qSqlQuery)
{
  QString str;
  ui->line_AuftragsNr->setText(qSqlQuery.value(5).toString());
  ui->line_AKL->setText(qSqlQuery.value(3).toString());
  ui->line_CRM_Auftr_Nr->setText(qSqlQuery.value(24).toString());
  ui->line_OPD_FA_Nr->setText(qSqlQuery.value(25).toString());
  ui->line_AuftragsNr->setText(qSqlQuery.value(26).toString());
  ui->line_Druckkopf->setText(qSqlQuery.value(27).toString());
  ui->line_Auftragasart->setText(qSqlQuery.value(28).toString());
  ui->line_Auftragsunterart->setText(qSqlQuery.value(29).toString());
  ui->line_VerweisauftragsNr->setText(qSqlQuery.value(30).toString());
  ui->line_Kdl_Kenner->setText(qSqlQuery.value(31).toString());
  ui->line_RK->setText(qSqlQuery.value(32).toString());
  str=qSqlQuery.value(1).toString();
  ui->line_Termin->setText(str.mid(0, str.indexOf('/')-1));
  ui->line_Terminatrt->setText(qSqlQuery.value(33).toString());
  ui->line_Kdbes_AS->setText(qSqlQuery.value(34).toString());
  ui->line_Zeift->setText(qSqlQuery.value(35).toString());
  str=qSqlQuery.value(11).toString();
  ui->line_Uhreseit_von->setText(str.right(5));
  str=qSqlQuery.value(1).toString();
  ui->line_bis->setText(str.right(5));
  ui->line_Schaltungsart->setText(qSqlQuery.value(36).toString());
  str=qSqlQuery.value(4).toString();
  ui->line_LSZ->setText(str.mid(0, str.indexOf('/')));
  ui->line_ONKzA->setText(str.mid(str.indexOf('/')+1,3));
  ui->line_OrdNr->setText(qSqlQuery.value(37).toString());
  ui->line_LSZZ->setText(qSqlQuery.value(38).toString());
  ui->line_ONKzB->setText(qSqlQuery.value(39).toString());
  ui->line_AuftragsNr->setText(qSqlQuery.value(40).toString());
  ui->line_ORKA->setText(qSqlQuery.value(41).toString());
  ui->line_ADSL->setText(qSqlQuery.value(42).toString());
  ui->line_DA->setText(qSqlQuery.value(43).toString());
  ui->line_FA_NR->setText(qSqlQuery.value(44).toString());
  ui->bigORKA->insertPlainText(qSqlQuery.value(45).toString());
  ui->line_VBz->setText(qSqlQuery.value(19).toString());
  ui->line_OrgEtyp->setText(qSqlQuery.value(46).toString());
  str=qSqlQuery.value(14).toString();
  ui->line_Rouying_ONKz->setText(str.mid(0, str.indexOf('/')));
  ui->line_Routing_Azb->setText(qSqlQuery.value(47).toString());
  ui->line_Kundennummer->setText(qSqlQuery.value(48).toString());
  ui->line_FKTO->setText(qSqlQuery.value(49).toString());
  ui->line_RuckrufNr->setText(qSqlQuery.value(50).toString());
  ui->line_Vertragstyp_Bedeufung->setText(qSqlQuery.value(51).toString());
  if(qSqlQuery.value(52).toString()=="")
  {
    ui->line_Vertagsdatum->setText("TT.MM.JJJJ");
  }
  else
  {
    ui->line_Vertagsdatum->setText(qSqlQuery.value(52).toString());

  }
  ui->line_Duma_ONKz->setText(qSqlQuery.value(53).toString());
  ui->line_Duma_Nr->setText(qSqlQuery.value(54).toString());
}
