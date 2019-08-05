#ifndef AUFTRAGSANNAHME_TELAS_H
#define AUFTRAGSANNAHME_TELAS_H

#include <QCloseEvent>
#include <QMainWindow>
#include <QMessageBox>
#include "auftragsannahme_many.h"
#include "auftragsannahme_alone.h"
#include <../Smile/Server/toolsfordb.h>
#include <QLineEdit>
#include <QSqlRecord>
namespace Ui {
  class Auftragsannahme_TelAs;
}

class Auftragsannahme_TelAs : public QMainWindow
{
  Q_OBJECT

public:
  explicit Auftragsannahme_TelAs(QString login,QWidget *parent = 0);
  ~Auftragsannahme_TelAs();

private slots:
  void on_OK_clicked();
  void on_radio_Volhistorie_clicked(bool checked);
  void on_radio_L_Volhistorie_clicked(bool checked);
  void on_radio_laufendeAufrage_clicked(bool checked);
  void on_button_Abbrech_clicked();

  void on_tabWidget_tabBarClicked(int index);

private:
  QString login;
  Ui::Auftragsannahme_TelAs *ui;
  Auftragsannahme_Many *AUF_many;
  Auftragsannahme_Alone *AUF_Alone;
  void search(QMap<QString,QString> map);

};

#endif // AUFTRAGSANNAHME_TELAS_H
