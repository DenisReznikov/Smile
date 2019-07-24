#ifndef AUSWAHL_DISPO_CENTER_H
#define AUSWAHL_DISPO_CENTER_H

#include <QMainWindow>
#include "auftragsauswahl.h"
namespace Ui {
  class Auswahl_Dispo_Center;
}

class Auswahl_Dispo_Center : public QMainWindow
{
  Q_OBJECT

public:
  explicit Auswahl_Dispo_Center(QString login,QWidget *parent = 0);
  ~Auswahl_Dispo_Center();

private slots:
  void on_show_clicked();
  void on_Close_clicked();
  void on_Next_clicked();

private:
  Ui::Auswahl_Dispo_Center *ui;
  Auftragsauswahl * o_Auftragsauswahl;
  QString login;
};

#endif // AUSWAHL_DISPO_CENTER_H
