#include "auftragsannahme_many.h"
#include "ui_auftragsannahme_many.h"

Auftragsannahme_Many::Auftragsannahme_Many(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Auftragsannahme_Many)
{
  ui->setupUi(this);
}

Auftragsannahme_Many::~Auftragsannahme_Many()
{
  delete ui;
}

void Auftragsannahme_Many::on_lupeButton_clicked()
{
    Lupe(ui->outFrame);
}
