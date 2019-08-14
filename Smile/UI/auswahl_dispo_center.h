#ifndef AUSWAHL_DISPO_CENTER_H
#define AUSWAHL_DISPO_CENTER_H

#include <QMainWindow>
#include "Smile/UI/auftragsauswahl.h"
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

  void on_tableView_doubleClicked(const QModelIndex &index);
  void on_tableView_clicked(const QModelIndex &index);
  void on_tableView_entered(const QModelIndex &index);
  void on_button_Abbrechen_clicked();

private:
  void createTable() const;
  Ui::Auswahl_Dispo_Center *ui;
  QString login;
  Auftragsauswahl *auftrags;
  QSqlQueryModel *model;
};

#endif // AUSWAHL_DISPO_CENTER_H
