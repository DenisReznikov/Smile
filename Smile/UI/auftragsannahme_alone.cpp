#include "auftragsannahme_alone.h"
#include "ui_auftragsannahme_alone.h"

Auftragsannahme_Alone::Auftragsannahme_Alone(QString login,QVector<QString> value,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsannahme_Alone)
{
  ui->setupUi(this);
  ui->Name_person->setText(login);
  ui->AuftragsNr->setText(value[5]);
}

Auftragsannahme_Alone::~Auftragsannahme_Alone()
{
  delete ui;
}
