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
  checkWidjets();
}
void Auftragsannahme_TelAs::putInMap()
{

}

Auftragsannahme_TelAs::~Auftragsannahme_TelAs()
{
  delete ui;
}

bool Auftragsannahme_TelAs::checkWidjets()
{
  QList<QLineEdit *> box=ui->Name->findChildren<QLineEdit*>();
  for (auto iter = box.begin(); iter != box.end(); iter++)
    {
      if((*iter)->text().isEmpty())
     return false;
    }
  return true;
}

void Auftragsannahme_TelAs::on_OK_clicked()
{
  if(!checkWidjets())
    {
      QMessageBox::warning(this,"Внимание ","Вы не заполнили обязательные поля ");
      return;
    }
  qDebug()<<"EEEEEEEEEEEE";
}
