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
  explicit Dispositionsdater_for_HVt_Schaltauftrag(QString login,QString DispoCenter,QVector<QString> values,QWidget *parent = 0);
  ~Dispositionsdater_for_HVt_Schaltauftrag();

private slots:
  void on_button_Abbrechen_clicked();

private:
  Ui::Dispositionsdater_for_HVt_Schaltauftrag *ui;
};

#endif // DISPOSITIONSDATER_FOR_HVT_SCHALTAUFTRAG_H
