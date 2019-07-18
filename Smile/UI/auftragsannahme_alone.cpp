#include "auftragsannahme_alone.h"
#include "ui_auftragsannahme_alone.h"

Auftragsannahme_Alone::Auftragsannahme_Alone(QString login,QVector<QString> values,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsannahme_Alone)
{
  ui->setupUi(this);
  ui->Name_person->setText(login);
  this->login=login;
  ui->AuftragsNr->setText(values[5]);
}

Auftragsannahme_Alone::~Auftragsannahme_Alone()
{
  delete ui;
}
