#include "dispositionsdater_for_hvt_schaltauftrag.h"
#include "ui_dispositionsdater_for_hvt_schaltauftrag.h"

Dispositionsdater_for_HVt_Schaltauftrag::Dispositionsdater_for_HVt_Schaltauftrag(QString login,QString DispoCenter,QVector<QString> values,QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Dispositionsdater_for_HVt_Schaltauftrag)
{
  ui->setupUi(this);
  ui->Name_person->setText(login);
  ui->labelDispoCenter->setText(DispoCenter);
  QList<QLineEdit *> box=ui->centralwidget->findChildren<QLineEdit*>();
  for(QLineEdit *i : box)
  {
    i->setReadOnly(true);
  }
}

Dispositionsdater_for_HVt_Schaltauftrag::~Dispositionsdater_for_HVt_Schaltauftrag()
{
  delete ui;
}

void Dispositionsdater_for_HVt_Schaltauftrag::on_button_Abbrechen_clicked()
{
  this->close();
}
