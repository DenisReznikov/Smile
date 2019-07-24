#ifndef DISPOSITIONSDATER_FOR_HVT_SCHALTAUFTRAG_H
#define DISPOSITIONSDATER_FOR_HVT_SCHALTAUFTRAG_H

#include <QMainWindow>

namespace Ui {
  class Dispositionsdater_for_HVt_Schaltauftrag;
}

class Dispositionsdater_for_HVt_Schaltauftrag : public QMainWindow
{
  Q_OBJECT

public:
  explicit Dispositionsdater_for_HVt_Schaltauftrag(QWidget *parent = 0);
  ~Dispositionsdater_for_HVt_Schaltauftrag();

private:
  Ui::Dispositionsdater_for_HVt_Schaltauftrag *ui;
};

#endif // DISPOSITIONSDATER_FOR_HVT_SCHALTAUFTRAG_H
