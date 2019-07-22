#include "auftragsauswahl.h"
#include "ui_auftragsauswahl.h"

Auftragsauswahl::Auftragsauswahl(QString login,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsauswahl)
{
  ui->setupUi(this);
  this->login=login;
  ui->Name_person->setText(login);
}

Auftragsauswahl::~Auftragsauswahl()
{
  delete ui;
}

void Auftragsauswahl::on_OK_clicked()
{
  QMap<QString,QString> map;
  toolsForDB b;
  QSqlQuery QSqlQ=b.checkInTable("Auftragsliste",map);
  QString sql_string ="select * from Auftragsliste";
  auftragsliste = new Auftragsliste(login,QSqlQ);
  auftragsliste->show();
}
