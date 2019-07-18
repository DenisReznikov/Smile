#include "auftragsannahme_alone.h"
#include "ui_auftragsannahme_alone.h"

Auftragsannahme_Alone::Auftragsannahme_Alone(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsannahme_Alone)
{
  ui->setupUi(this);
}

Auftragsannahme_Alone::~Auftragsannahme_Alone()
{
  delete ui;
}
