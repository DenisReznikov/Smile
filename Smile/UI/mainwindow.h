#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "auftragsannahme_telas.h"
#include "auswahl_dispo_center.h"
#include <QMessageBox>
#include <QMainWindow>
namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QString login,QWidget *parent = 0);
  ~MainWindow();
private slots:
  void on_Auftragsauswahl_clicked();
  void on_Dispositionsmodul_clicked();

private:
  Ui::MainWindow *ui;
  Auftragsannahme_TelAs *Auf;
  Auswahl_Dispo_Center *Auswahl;
  void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
