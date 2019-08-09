#include "bearbzust.h"
#include "ui_bearbzust.h"

BearbZust::BearbZust(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::BearbZust)
{
  ui->setupUi(this);
}

BearbZust::~BearbZust()
{
  delete ui;
}

void BearbZust::on_buttonBox_accepted()
{

}
