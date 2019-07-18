#include "auftragsauswahl.h"
#include "ui_auftragsauswahl.h"

Auftragsauswahl::Auftragsauswahl(QString login,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsauswahl)
{
  ui->setupUi(this);
  this->login=login;
  ui->Name_person->setText(login);

  sql_string ="select * from Auftragsliste";
}

Auftragsauswahl::~Auftragsauswahl()
{
  delete ui;
}

void Auftragsauswahl::on_OK_clicked()
{
  auftragsliste = new Auftragsliste(login,sql_string);
  auftragsliste->show();
}
