#include "auftragsannahme_telas.h"
#include "ui_auftragsannahme_telas.h"
#include <QDebug>

Auftragsannahme_TelAs::Auftragsannahme_TelAs(QString login,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsannahme_TelAs)
{
  ui->setupUi(this);
  ui->dateEdit->setDate(QDate::currentDate());
  ui->Name_person->setText(login);
  this->login=login;

}
Auftragsannahme_TelAs::~Auftragsannahme_TelAs()
{
  delete ui;
}

