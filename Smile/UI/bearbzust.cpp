#include "bearbzust.h"
#include "ui_bearbzust.h"

BearbZust::BearbZust(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::BearbZust)
{
  ui->setupUi(this);
}

BearbZust::~BearbZust()
{
  delete ui;
}
