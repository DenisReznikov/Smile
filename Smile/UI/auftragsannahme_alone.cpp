#include "auftragsannahme_alone.h"
#include "ui_auftragsannahme_alone.h"

Auftragsannahme_Alone::Auftragsannahme_Alone(QString login,QVector<QString> value,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsannahme_Alone)
{
  ui->setupUi(this);
  ui->Name_person->setText(login);
  ui->AuftragsNr->setText(value[5]);
  QList<QLineEdit *> box=ui->centralwidget->findChildren<QLineEdit*>();
  for(QLineEdit *i : box)
  {
    i->setStyleSheet("background-color: red");
  }
}

Auftragsannahme_Alone::~Auftragsannahme_Alone()
{
  delete ui;
}

void Auftragsannahme_Alone::on_button_Abbrechen_clicked()
{
  this->close();
}
