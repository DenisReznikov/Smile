#include "dispositionsdater_for_hvt_schaltauftrag.h"
#include "ui_dispositionsdater_for_hvt_schaltauftrag.h"

Dispositionsdater_for_HVt_Schaltauftrag::Dispositionsdater_for_HVt_Schaltauftrag(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Dispositionsdater_for_HVt_Schaltauftrag)
{
  ui->setupUi(this);
}

Dispositionsdater_for_HVt_Schaltauftrag::~Dispositionsdater_for_HVt_Schaltauftrag()
{
  delete ui;
}
