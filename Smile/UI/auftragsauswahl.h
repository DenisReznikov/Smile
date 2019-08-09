#ifndef AUFTRAGSAUSWAHL_H
#define AUFTRAGSAUSWAHL_H
#include "Smile/UI/bearbzust.h"
#include "auftragsliste.h"
#include <QMainWindow>
#include "../Smile/Server/toolsfordb.h"
#include "Smile/UI/dispositionsdater_for_hvt_schaltauftrag.h"
namespace Ui {
  class Auftragsauswahl;
}

class Auftragsauswahl : public QMainWindow
{
  Q_OBJECT

public:
  explicit Auftragsauswahl(QString login,QString DispoCenter,QWidget *parent = 0);
  ~Auftragsauswahl();
  QString login;

private slots:
  void on_OK_clicked();
  void on_button_Abbrechen_clicked();

  void on_button_BearbZust_clicked();

private:
  void search(QMap<QString,QString> map);
  Ui::Auftragsauswahl *ui;
  Auftragsliste *auftragsliste;
  Dispositionsdater_for_HVt_Schaltauftrag *dispo;
  BearbZust *bearbZust;
  void addBearbZust(QString str);
};

#endif // AUFTRAGSAUSWAHL_H
