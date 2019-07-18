#include "passwort_anderung.h"
#include "ui_passwort_anderung.h"

Passwort_Anderung::Passwort_Anderung(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Passwort_Anderung)
{
  ui->setupUi(this);
}

Passwort_Anderung::~Passwort_Anderung()
{
  delete ui;
}
