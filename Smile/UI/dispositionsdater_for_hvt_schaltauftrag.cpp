#include "dispositionsdater_for_hvt_schaltauftrag.h"
#include "ui_dispositionsdater_for_hvt_schaltauftrag.h"
#include <QDesktopWidget>
Dispositionsdater_for_HVt_Schaltauftrag::Dispositionsdater_for_HVt_Schaltauftrag(QString login,QString DispoCenter,QVector<QString> values,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Dispositionsdater_for_HVt_Schaltauftrag)
{
  ui->setupUi(this);
  ui->Name_person->setText(login);
  ui->labelDispoCenter->setText(DispoCenter);
  QDesktopWidget widget;
  QRect mainScreenSize = widget.screenGeometry(this);
  this->setGeometry(mainScreenSize.width()*0.2/2,mainScreenSize.height()*0.2/2,(int)(mainScreenSize.width()*0.8),mainScreenSize.height()*0.8);

}

Dispositionsdater_for_HVt_Schaltauftrag::~Dispositionsdater_for_HVt_Schaltauftrag()
{
  delete ui;
}

void Dispositionsdater_for_HVt_Schaltauftrag::on_button_Abbrechen_clicked()
{
  this->close();
}
