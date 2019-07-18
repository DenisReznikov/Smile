#ifndef AUFTRAGSANNAHME_TELAS_H
#define AUFTRAGSANNAHME_TELAS_H
#include <QSqlDatabase>
#include <QCloseEvent>
#include <QMainWindow>
#include <QMessageBox>
#include "auftragsannahme_many.h"
#include "auftragsannahme_alone.h"
namespace Ui {
  class Auftragsannahme_TelAs;
}

class Auftragsannahme_TelAs : public QMainWindow
{
  Q_OBJECT

public:
  static void wert();
  explicit Auftragsannahme_TelAs(QString login,QWidget *parent = nullptr);
  ~Auftragsannahme_TelAs();

private slots:
  //  void on_OK_clicked();
  void on_OK_clicked();
  void on_Abbrech_clicked();
  void on_name_for_Sql_returnPressed();

private:
  QSqlDatabase db;
  QString login;
  Ui::Auftragsannahme_TelAs *ui;
  Auftragsannahme_Many *AUF_many;
  Auftragsannahme_Alone *AUF_Alone;
};

#endif // AUFTRAGSANNAHME_TELAS_H
