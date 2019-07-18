#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QMainWindow>
#include "auftragsannahme_telas.h"
#include "auswahl_dispo_center.h"
namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QString login,QWidget *parent = nullptr);
  ~MainWindow();
private slots:
  void on_Auftragsauswahl_clicked();
  void on_Dispositionsmodul_clicked();

private:
  QString login;
  Ui::MainWindow *ui;
  Auftragsannahme_TelAs *Auf;
  Auswahl_Dispo_Center *Auswahl;
};

#endif // MAINWINDOW_H
