#ifndef AUSWAHL_DISPO_CENTER_H
#define AUSWAHL_DISPO_CENTER_H

#include <QMainWindow>
#include "auftragsauswahl.h"
#include <QSqlQuery>
namespace Ui {
  class Auswahl_Dispo_Center;
}

class Auswahl_Dispo_Center : public QMainWindow,public BaseWindowWithTable
{
  Q_OBJECT

public:
  explicit Auswahl_Dispo_Center(QString login,QWidget *parent = 0);
  ~Auswahl_Dispo_Center();

private slots:


private:
  Ui::Auswahl_Dispo_Center *ui;
  QString login;
  QSqlQueryModel *model;
};

#endif // AUSWAHL_DISPO_CENTER_H
