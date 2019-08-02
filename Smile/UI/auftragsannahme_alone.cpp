#include "auftragsannahme_alone.h"
#include "ui_auftragsannahme_alone.h"
#include <sstream>
Auftragsannahme_Alone::Auftragsannahme_Alone(QString login,QVector<QString> value,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsannahme_Alone)
{
  ui->setupUi(this);
  ui->Name_person->setText(login);
  ui->AuftragsNr->setText(value[5]);
  QList<QLineEdit *> box=ui->centralwidget->findChildren<QLineEdit*>();
  int b=0;
  for(QLineEdit *i : box)
  {
    QString str="";
    i->setText(str.number(b));
    qDebug()<<str;
    b++;
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
