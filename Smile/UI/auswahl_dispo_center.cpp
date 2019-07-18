#include "auswahl_dispo_center.h"
#include "ui_auswahl_dispo_center.h"

Auswahl_Dispo_Center::Auswahl_Dispo_Center(QString login,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auswahl_Dispo_Center)
{
 ui->setupUi(this);
  this->login=login;
  ui->Name_person->setText(login);


}

Auswahl_Dispo_Center::~Auswahl_Dispo_Center()
{
  delete ui;
}



void Auswahl_Dispo_Center::on_show_clicked()
{
    ui->frame->show();
}

void Auswahl_Dispo_Center::on_Close_clicked()
{
     ui->frame->close();
}



void Auswahl_Dispo_Center::on_Next_clicked()
{
    o_Auftragsauswahl= new Auftragsauswahl(this->login);
    o_Auftragsauswahl->show();
}
