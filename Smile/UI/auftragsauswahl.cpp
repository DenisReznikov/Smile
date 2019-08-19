#include "auftragsauswahl.h"
#include "ui_auftragsauswahl.h"
#include <QDesktopWidget>
#include <QMessageBox>
Auftragsauswahl::Auftragsauswahl(QString login,QString DispoCenter,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsauswahl)
{
  ui->setupUi(this);
  ui->Name_person->setText(login);
  ui->labelDispoCenter->setText(DispoCenter);
  QDesktopWidget wid;
  QRect mainScreenSize = wid.screenGeometry(this);
  this->setGeometry(static_cast<int>(mainScreenSize.width()*0.2/2),static_cast<int>(mainScreenSize.height()*0.2/2),static_cast<int>(mainScreenSize.width()*0.8),static_cast<int>(mainScreenSize.height()*0.8));
}

Auftragsauswahl::~Auftragsauswahl()
{
  delete ui;
}

void Auftragsauswahl::search(QMap<QString,QString> map)
{
  static toolsForDB db =  toolsForDB();
  QSqlQuery qSqlQuery = db.returnTable("Auftragsliste",map);
  qSqlQuery.last();
  if(qSqlQuery.at()+1 == 1)
  {
    dispo = new Dispositionsdater_for_HVt_Schaltauftrag(ui->Name_person->text(),ui->labelDispoCenter->text(),qSqlQuery,this);
    dispo->show();
  }
  else if(qSqlQuery.at()+1>1)
  {
    auftragsliste = new Auftragsliste(ui->Name_person->text(),ui->labelDispoCenter->text(),qSqlQuery,this);
    auftragsliste->show();
  }
  else
  {
    QMessageBox::warning(this,"Hi","No matching records found");
  }
}

void Auftragsauswahl::on_OK_clicked()
{

  QMap<QString,QString> map;
  if(ui->line_Name->text()!="*"&&ui->line_Name->text()!="")
  {
    map.insert("Name",ui->line_Name->text());
  }
  if (ui->line_StraBe->text()!="*" && ui->line_StraBe->text()!="")
  {
    map.insert("Strabe",ui->line_StraBe->text());
    if (ui->line_HsNr->text()!="*" && ui->line_HsNr->text()!="")
    {
      map.insert("HsNr",ui->line_HsNr->text());
    }
  }
  if (ui->line_PlanGr->text()!="*" && ui->line_PlanGr->text()!="")
  {
    map.insert("PlanGr",ui->line_PlanGr->text());
  }
  if (ui->line_BearbZust->text()!="*" && ui->line_BearbZust->text()!="")
  {
    map.insert("BZu",ui->line_BearbZust->text());
  }
  if (ui->line_ONKz->text()!="*" && ui->line_ONKz->text()!="")
  {
    map.insert("ONKz",ui->line_ONKz->text());
  }
  if (ui->line_AsB->text()!="*" && ui->line_AsB->text()!="")
  {
    map.insert("AsB",ui->line_AsB->text());
  }
  this->search(map);
}


void Auftragsauswahl::on_button_Abbrechen_clicked()
{
  this->close();
}

void Auftragsauswahl::on_button_BearbZust_clicked()
{
  bearbZust = new BearbZust(this);
  bearbZust->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
  bearbZust->show();
  bearbZust->exec();
  ui->line_BearbZust->setText(bearbZust->ret);
}
