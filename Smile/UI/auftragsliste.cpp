#include "auftragsliste.h"
#include "ui_auftragsliste.h"

Auftragsliste::Auftragsliste(QString login,QString sql_string,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsliste)
{
  ui->setupUi(this);
  ui->Name_person->setText(login);
  this->login=login;

}

Auftragsliste::~Auftragsliste()
{
  delete ui;
}



void Auftragsliste::on_lupeButton_clicked()
{
    Lupe(ui->outFrame);
}
