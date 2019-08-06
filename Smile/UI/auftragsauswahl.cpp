#include "auftragsauswahl.h"
#include "ui_auftragsauswahl.h"
#include <QDesktopWidget>
Auftragsauswahl::Auftragsauswahl(QString login,QString DispoCenter,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsauswahl)
{
  ui->setupUi(this);
  this->login=login;
  ui->Name_person->setText(login);
  ui->labelDispoCenter->setText(DispoCenter);
  QDesktopWidget widget;
  QRect mainScreenSize = widget.screenGeometry(this);
  this->setGeometry(mainScreenSize.width()*0.2/2,mainScreenSize.height()*0.2/2,(int)(mainScreenSize.width()*0.8),mainScreenSize.height()*0.8);

}

Auftragsauswahl::~Auftragsauswahl()
{
  delete ui;
}

void Auftragsauswahl::on_OK_clicked()
{
  QMap<QString,QString> map;
  toolsForDB b;
  QSqlQuery QSqlQ=b.returnTable("Auftragsliste",map);
  QString sql_string ="select * from Auftragsliste";
  auftragsliste = new Auftragsliste(login,ui->labelDispoCenter->text(),QSqlQ,this);
  auftragsliste->show();
}


void Auftragsauswahl::on_button_Abbrechen_clicked()
{
    this->close();
}
