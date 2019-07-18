#include "authentication.h"
#include "ui_authentication.h"

Authentication::Authentication(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Authentication)
{
  ui->setupUi(this);
}

Authentication::~Authentication()
{
  delete ui;
}

<<<<<<< HEAD
void Authentication::on_newPasswort_clicked()
{
    passwortAnderung = new Passwort_Anderung;
    passwortAnderung->show();
}

void Authentication::on_login_clicked()
{
=======
void Authentication::on_login_clicked()
{
  this->ui->userName->text();
  mainWind = new MainWindow(this->ui->userName->text());
  mainWind->show();
  this->close();
>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794

}
