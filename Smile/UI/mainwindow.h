#ifndef MAINWINDOW_H
#define MAINWINDOW_H
<<<<<<< HEAD
#include <QMessageBox>
#include <QMainWindow>
#include "auftragsannahme_telas.h"
#include "auswahl_dispo_center.h"
=======
#include "auftragsannahme_telas.h"
#include "auswahl_dispo_center.h"
#include <QMessageBox>
#include <QMainWindow>

>>>>>>> 684bdc32c3b8175d3ee751b51b4c4c2376c37794
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
