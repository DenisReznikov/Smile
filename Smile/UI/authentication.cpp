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

void Authentication::on_newPasswort_clicked()
{
    passwortAnderung = new Passwort_Anderung;
    passwortAnderung->show();
}

void Authentication::on_login_clicked()
{

}
