#include "new_passwort.h"
#include "ui_new_passwort.h"

New_Passwort::New_Passwort(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::New_Passwort)
{
  ui->setupUi(this);
}

New_Passwort::~New_Passwort()
{
  delete ui;
}

void New_Passwort::on_button_Abbrechen_clicked()
{
  this->close();
}
