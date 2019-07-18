#include "auftragsannahme_alone.h"
#include "ui_auftragsannahme_alone.h"

<<<<<<< HEAD
Auftragsannahme_Alone::Auftragsannahme_Alone(QString login,QVector<QString> values,QWidget *parent) :
=======
Auftragsannahme_Alone::Auftragsannahme_Alone(QWidget *parent) :
>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
  QMainWindow(parent),
  ui(new Ui::Auftragsannahme_Alone)
{
  ui->setupUi(this);
<<<<<<< HEAD
  ui->Name_person->setText(login);
  this->login=login;
  ui->AuftragsNr->setText(values[5]);
=======
>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
}

Auftragsannahme_Alone::~Auftragsannahme_Alone()
{
  delete ui;
}
