#ifndef AUFTRAGSAUSWAHL_H
#define AUFTRAGSAUSWAHL_H
#include "auftragsliste.h"
#include <QMainWindow>
#include "../Smile/Server/toolsfordb.h"
namespace Ui {
  class Auftragsauswahl;
}

class Auftragsauswahl : public QMainWindow
{
  Q_OBJECT

public:
  explicit Auftragsauswahl(QString login,QWidget *parent = nullptr);
  ~Auftragsauswahl();
  QString login;

private slots:
  void on_OK_clicked();

private:
  Ui::Auftragsauswahl *ui;
  Auftragsliste *auftragsliste;

};

#endif // AUFTRAGSAUSWAHL_H
