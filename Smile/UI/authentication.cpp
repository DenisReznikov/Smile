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

void Authentication::on_login_clicked()
{
  this->ui->userName->text();
  mainWind = new MainWindow(this->ui->userName->text());
  mainWind->show();
  this->close();

}
